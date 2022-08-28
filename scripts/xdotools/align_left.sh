#!/bin/bash
wmctrl -r :ACTIVE: -b "remove,maximized_horz,maximized_vert" && \
xdotool getactivewindow windowsize 1750 1600 windowmove 500 0