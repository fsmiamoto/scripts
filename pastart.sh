#!/bin/bash
# pastart - Script for stating Pulseaudio
#

# Kill all previous instances
killall -q pulseaudio

# Wait until all of processes are killed
while pgrep -u $UID -x pulseaudio > /dev/null
do
    sleep 1;
done

# Launch pulseaudio
pulseaudio &
