#!/bin/sh
#IS_HIT_UPDATE_SCRIPT=1

SOURCE_PATH="/mnt/usb"

aplay -c 1 -r 16000 -f S16_LE /usr/SNDDATA/SND_BLACKBOX_LOADING_START.snd

ls -lA -R / > $SOURCE_PATH/dirlist.txt 2>&1

aplay -c 1 -r 16000 -f S16_LE /usr/SNDDATA/SND_BLACKBOX_LOADING_END.snd

exit 0
