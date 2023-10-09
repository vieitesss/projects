#!../.venv/bin/python

import customtkinter as ctk
from PIL import Image
from player import Player
import utils.consts as consts


class TicTacToeFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)

        self.master = master

        self.buttons = []

        for i in range(3):
            self.grid_rowconfigure(i, weight=1)
            self.buttons.append([])
            for j in range(3):
                self.grid_columnconfigure(j, weight=1)
                button = ctk.CTkButton(
                    self,
                    consts.TTT_IMG_SIDE,
                    consts.TTT_IMG_SIDE,
                    0,
                    text="",
                    command=lambda i=i, j=j: self.update_board(i, j),
                    fg_color="transparent",
                    hover=False,
                    image=ctk.CTkImage(
                        Image.open(consts.WHITE_IMG),
                        size=(consts.TTT_IMG_SIDE, consts.TTT_IMG_SIDE),
                    ),
                )
                button.grid(row=i, column=j)
                self.buttons[i].append(button)

    def update_board(self, i: int, j: int):
        current_player_image = self.master.get_current_player_image()

        self.buttons[i][j].configure(image=current_player_image)
        self.master.change_player_turn()


class App(ctk.CTk):
    def __init__(self):
        super().__init__()

        self.text_from_button = ctk.StringVar(self, "")

        self.title("My app")

        self.set_geometry()
        self.grid_columnconfigure(0, weight=1)

        self.players = []
        self.player1 = Player(consts.CIRCLE_IMG)
        self.player2 = Player(consts.CROSS_IMG)
        self.players.append(self.player1)
        self.players.append(self.player2)

        self.player_turn = ctk.IntVar(self, 0)

        self.player_turn_label = ctk.CTkLabel(self, text=f"Turn: {self.get_player_turn()}")
        self.player_turn_label.grid(row=1, column=0, padx=10, pady=10)

        self.tttFrame = TicTacToeFrame(self)
        self.tttFrame.grid(row=2, column=0, ipadx=5, ipady=5)

    def change_player_turn(self):
        self.player_turn.set((self.player_turn.get() + 1) % 2)
        self.player_turn_label.configure(text=f"Turn: {self.get_player_turn()}")

    def get_current_player_image(self):
        return self.players[self.player_turn.get()].get_image()

    def get_player_turn(self):
        return "Player 1" if self.player_turn.get() == 0 else "Player 2"

    def set_geometry(self):
        x = int(self.winfo_screenwidth() * 0.5 - int(consts.WINDOW_WIDTH) / 2)
        y = int(self.winfo_screenheight() * 0.5 - int(consts.WINDOW_HEIGHT) / 2)
        self.geometry(f"{consts.WINDOW_WIDTH}x{consts.WINDOW_HEIGHT}+{x}+{y}")


app = App()
app.mainloop()
