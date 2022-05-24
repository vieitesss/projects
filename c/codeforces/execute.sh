#!/bin/bash

gcc main.c -o exit

if [[ "$(echo $?)" != "0" ]]; then
   return 1 
fi

./exit && rm exit
