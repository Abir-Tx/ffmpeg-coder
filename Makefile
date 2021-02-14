# make script for the ffmpeg-coder project to build the project from source code 
# By Abir-Tx


# variables
CC := g++
SRCDIR := src
BUILDDIR := bin
CFLAG := -v
INC := -I include/ffmpeg-coder -I lib
APPNAME := ffmpeg-coder

.PHONY: all

all: dir build run

.PHONY: build
build:
	${CC} ${CFLAG} ${SRCDIR}/${APPNAME}.cpp ${INC} -o ${BUILDDIR}/${APPNAME}.o

.PHONY: clean
clean:
	echo "Deleting the binaries...."
        rm ${BUILDDIR}/*
        rm usrData/*
        rm appData/*

.PHONY: run
run:
	echo "Running the built program...."
	./${BUILDDIR}/${APPNAME}.o


# Windows Configs for make
.PHONY: winbuild
winbuild:
	${CC} ${CFLAG} ${SRCDIR}/${APPNAME}.cpp ${INC} -o ${BUILDDIR}/${APPNAME}.exe

.PHONY: winrun
winrun:
	echo "Running the built program...."
	./${BUILDDIR}/${APPNAME}.exe

.PHONY: dir
dir:
	echo Creating directories.....
	mkdir bin usrData appData
