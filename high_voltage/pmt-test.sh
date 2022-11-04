#!/bin/bash

# turn on channels
sudo ./power ON

# set initial settings
sudo ./init

# set initial voltage
for chNum in [0..3]; do
  sudo ./setV $chNum 1200.

# start and stop data acquistion
run wrapper for wavedump
if [ wave0*.txt or wave0*.dat reaches a certain file size ];
  stop data acquistion

# analyze data and adjust voltage
for chNum in [0..3]; do
  python gainCalc.py wave0$chNum.txt
  if [ gain within 10% of 10**7 ];
    save data file for further analysis (e.g. after pulsing, etc)
  else if [ gain > 10**7 ];
    sudo ./setV $chNum $(initVolt - 100).
  else if [ gain < 10**7 ];
    sudo ./setV $chNum $(initvolt + 100).

# when operating voltage determined for all channels
sudo ./init
sudo ./power OFF
