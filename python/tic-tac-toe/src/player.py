import customtkinter as ctk
import utils.consts as consts
from PIL import Image


class Player:
    def __init__(self, image: str):
        self.image_str = image
        self.image = self._set_image(image)
        self.cells = []

    def get_image_str(self):
        return self.image_str

    def get_image(self):
        return self.image

    def _set_image(self, image: str):
        return ctk.CTkImage(Image.open(image), size=(consts.TTT_IMG_SIDE, consts.TTT_IMG_SIDE))
