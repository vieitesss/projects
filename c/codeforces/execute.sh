#!/bin/bash

gcc main.c -lm -o exit

if [[ "$(echo $?)" != "0" ]]; then
   return 1 
fi

./exit && rm exit
