#!/bin/bash

# open WaveDump software
wavedump
# or use another DAQ software that circumvents use of WaveDump 
# / directly communicates with digitizer to avoid keystroke method

# send it some keystrokes
s # starts/stops acquistion
W # enable/disable continuous writing
P # enable/disable continuous plotting; adjust config file to plot all ch's to monitor PMTs?

# if file gets to a certain size; use wave_0 as ref
if [ wave_0.txt is xx MB ]; do
	# send keystroke 'W' to stop writing, 's' to stop run
	# or 'q' to quit completely
done

# run python/C++ script to analyze raw data output
# incorporate analyzing multiple files at once
for ch in {0..3}; do
	python plot_wavetxt.py wave_$ch.txt my_charge_$ch.txt # need to incorporate variable output file name
	python gainCalc.py my_charge_$ch.txt

	if [ $? == -1 ]
		# send to HV module new volt setting
	fi
	else
		# save raw data for further data analysis, record operating voltage
done
