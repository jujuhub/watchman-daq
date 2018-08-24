CC = gcc
GCCFLAGS = -Wall -Wextra -g
INCLUDES = -I/home/juhe/caen/CAENHVWrapper-5.82/include -Iinclude
SRC = src
BINDIR = bin
LIBDIR = lib

HVFUNC = watchHV.c
HVOPTIONS := -Wno-write-strings -pthread
HVLIBS := -lcaenhvwrapper -ldl -lm

all: power init setV

power:
	$(CC) $(GCCFLAGS) $(HVOPTIONS) $(INCLUDES) $(HVLIBS) $(SRC)/$(HVFUNC) $(SRC)/hvPower_main.c -o power

init:
	$(CC) $(GCCFLAGS) $(HVOPTIONS) $(INCLUDES) $(HVLIBS) $(SRC)/$(HVFUNC) $(SRC)/initSettings_main.c -o init

setV:
	$(CC) $(GCCFLAGS) $(HVOPTIONS) $(INCLUDES) $(HVLIBS) $(SRC)/$(HVFUNC) $(SRC)/setVolt_main.c -o setV

clean:
	rm power init setV 
