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

all: build run

.PHONY: build
build:
	${CC} ${CFLAG} ${SRCDIR}/${APPNAME}.cpp ${INC} -o ${BUILDDIR}/${APPNAME}.o

.PHONY: clean
clean:
	echo Deleting the binaries....
	rm ${BUILDDIR}/*
	rm ffmpeg-coder/usr/bin/ffmpeg-coder
	
.PHONY: run
run:
	echo Running the built program....
	./${BUILDDIR}/${APPNAME}.o

.PHONY: dir
dir:
	echo Creating directories.....
	mkdir bin

.PHONY: debpackage
debpackage: build
	echo Creating the debian package of ffmpeg-coder
	mv bin/ffmpeg-coder.o bin/ffmpeg-coder
	cp bin/ffmpeg-coder ffmpeg-coder/usr/bin/
	fakeroot dpkg-deb -v --build ffmpeg-coder bin
	echo The deb package has been created in the bin folder
	

# Windows Configs for make
.PHONY: winbuild
winbuild:
	${CC} ${CFLAG} ${SRCDIR}/${APPNAME}.cpp ${INC} -o ${BUILDDIR}/${APPNAME}.exe

.PHONY: winrun
winrun:
	echo Running the built program....
	./${BUILDDIR}/${APPNAME}.exe
