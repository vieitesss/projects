#!../.venv/bin/python

# from tkinter import IntVar
import customtkinter as ctk
from utils.config import constants

consts = constants()


class TicTacToeFrame(ctk.CTkFrame):
    def __init__(self, master):
        super().__init__(master)

        self.master = master

        self.buttons = []
        self.text_from_button = ctk.StringVar(self, "")

        for i in range(3):
            self.buttons.append([])
            for j in range(3):
                button = ctk.CTkButton(
                    self,
                    50,
                    50,
                    0,
                    text=f"{i}-{j}",
                    command=lambda i=i, j=j: self.set_text(f"{i}-{j}"),
                )
                button.grid(row=i, column=j)
                self.buttons[i].append(button)

    def set_text(self, value):
        self.text_from_button.set(value)
        self.master.get_button_text()

    def get_text(self):
        return self.text_from_button.get()


class App(ctk.CTk):
    def __init__(self):
        super().__init__()

        self.text_from_button = ctk.StringVar(self, "")

        self.title("My app")

        self.set_geometry()
        self.grid_columnconfigure(0, weight=1)

        # self.button = ctk.CTkButton(self, text="my button", command=self.increase_counter)
        # self.button.grid(row=0, column=0, padx=20, pady=20)

        self.label = ctk.CTkLabel(self, text=self.text_from_button.get())
        self.label.grid(row=1, column=0, padx=10, pady=10)

        self.tttFrame = TicTacToeFrame(self)
        self.tttFrame.grid(row=2, column=0)

    def set_geometry(self):
        x = int(self.winfo_screenwidth() * 0.5 - int(consts["WINDOW_HEIGHT"]) / 2)
        y = int(self.winfo_screenheight() * 0.5 - int(consts["WINDOW_WIDTH"]) / 2)
        self.geometry(f"{consts['WINDOW_WIDTH']}x{consts['WINDOW_WIDTH']}+{x}+{y}")

    def get_button_text(self):
        self.text_from_button.set(self.tttFrame.get_text())
        self.label.configure(text=self.text_from_button.get())


app = App()
app.mainloop()
