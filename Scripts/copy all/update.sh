#!/bin/sh
#IS_HIT_UPDATE_SCRIPT=1

SOURCE_PATH="/mnt/usb"

aplay -c 1 -r 16000 -f S16_LE /usr/SNDDATA/SND_BLACKBOX_LOADING_START.snd

mkdir $SOURCE_PATH/backup/

cp -R /linuxrc $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /bin  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
#cp -R /dev $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /etc  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /lib  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
#cp -R /mnt  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
#cp -R /proc $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
#cp -R /root $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /sbin $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
#cp -R /sys  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /temp $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /tmp  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /usr  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1
cp -R /var  $SOURCE_PATH/backup/ >> $SOURCE_PATH/output.txt 2>&1

aplay -c 1 -r 16000 -f S16_LE /usr/SNDDATA/SND_BLACKBOX_LOADING_END.snd

exit 0
