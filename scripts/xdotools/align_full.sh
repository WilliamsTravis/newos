#!/bin/bash
wmctrl -r :ACTIVE: -b "remove,maximized_horz,maximized_vert" && \
xdotool getactivewindow windowsize 3340 1580 windowmove 500 0