#!../.venv/bin/python

import configparser

config = configparser.ConfigParser()


def constants():
    config.read("../config.ini")
    return config["constants"]


if __name__ == "__main__":
    consts = constants()
    print(consts["WINDOW_WIDTH"])
