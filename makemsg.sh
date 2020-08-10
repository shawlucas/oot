#!/bin/bash

# make nes_c.c
rm -f end.txt *.rtf
rm -f nes_a nes_b nes_c.c

dir1="data/message/NES/"
ln -s $dir1/rtf/zel0000.rtf zel0000.rtf
ln -s $dir1/rtf/zel0100.rtf zel0100.rtf
ln -s $dir1/rtf/zel0200.rtf zel0200.rtf
ln -s $dir1/rtf//zel0300.rtf zel0300.rtf
ln -s $dir1/rtf//zel0400.rtf zel0400.rtf
ln -s $dir1/rtf//zel0600.rtf zel0600.rtf
ln -s $dir1/rtf//zel0800.rtf zel0800.rtf
ln -s $dir1/rtf//zel1000.rtf zel1000.rtf
ln -s $dir1/rtf//zel2000.rtf zel2000.rtf
ln -s $dir1/rtf//zel3000.rtf zel3000.rtf
ln -s $dir1/rtf//zel4000.rtf zel4000.rtf
ln -s $dir1/rtf//zel5000.rtf zel5000.rtf
ln -s $dir1/rtf//zel6000.rtf zel6000.rtf
ln -s $dir1/rtf//zel7000.rtf zel7000.rtf
ln -s $dir1/rtf//zel7100.rtf zel7100.rtf
ln -s $dir1/end.txt end.txt
tools/message/make_msg_zh nes zel0000.rtf zel0100.rtf zel0200.rtf zel0300.rtf zel0400.rtf zel0600.rtf zel0800.rtf  zel1000.rtf zel2000.rtf zel3000.rtf zel4000.rtf zel5000.rtf zel6000.rtf zel7000.rtf zel7100.rtf end.txt

rm -rf *.rtf end.txt
mv nes_* data/message/NES/
