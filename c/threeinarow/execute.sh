#!/bin/bash

gcc -Wall -Wextra -Wshadow -Wpedantic -std=c99 main.c game.c player.c -o exit
if [[ "$(echo $?)" != "0" ]]; then
    return 1
fi
./exit && rm exit
