#!/bin/bash
wmctrl -r :ACTIVE: -b "remove,maximized_horz,maximized_vert" && \
xdotool getactivewindow windowsize 1600 1600 windowmove 2250 0