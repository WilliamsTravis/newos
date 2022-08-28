#!/bin/bash
readarray -t ADDRR < <(wmctrl -l | cut -d ' ' -f 4-);
for i in "${ADDR[@]}"
do
  wmctrl -r $i -b "toggle,hidden"
done
