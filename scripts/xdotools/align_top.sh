#!/bin/bash
wmctrl -r :ACTIVE: -b "remove,maximized_horz,maximized_vert" && \
xdotool getactivewindow windowsize 3350 750 windowmove 500 0