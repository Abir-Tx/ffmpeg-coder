[![Download ffmpeg-coder](https://sourceforge.net/sflogo.php?type=11&group_id=3333544)](https://sourceforge.net/p/ffmpeg-coder/)

[![Download ffmpeg-coder](https://img.shields.io/sourceforge/dt/ffmpeg-coder.svg)](https://sourceforge.net/projects/ffmpeg-coder/files/latest/download) [![C/C++ CI](https://github.com/Abir-Tx/ffmpeg-coder/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/Abir-Tx/ffmpeg-coder/actions/workflows/c-cpp.yml)

# FFMPEG-Coder

A small **_cross platform_** CLI tool which will help in producing different types video converting codes quickly for new ffmpeg CLI users. The tool will make it easy to generate ffmpeg commands for them. If you don't use or know about **FFMPEG** then this tool might not be for you.

# Who is this tool for ?

This tool is created for those who find it difficult to understand or find the appropriate commands for converting a video as they want using the FFMPEG CLI tool.

Also those who are new to Command Lines they can also use this tool to generate ffmpeg commands very easily. Many new ffmpeg users find it difficult to find the appropriate ffmpeg commands to convert their videos to with their desired configs. So, as a result they end up googling a lot and wasting their time. So this tool is for them.

# Pre-requisites

The user should have really basic knowledge about ffmpeg like how to run ffmpeg in a directory and how to issue the commands. Thats it !!

# Features

- Supports **Windows, Linux** & **Mac OS**.
- Does not dpeend on any other dependencies.
- Very small, fast and lightweight.
- Supports options for **h264** and **libx265**.

# Downloads

- Downloads are available in **sourceforge** -

[![Download ffmpeg-coder](https://a.fsdn.com/con/app/sf-download-button)](https://sourceforge.net/projects/ffmpeg-coder/files/latest/download)

- You can download the latest version from the [release](https://github.com/Abir-Tx/ffmpeg-coder/releases/latest) section.

# Installation

## Windows

- First download the windows installer file from the release or from [here](https://github.com/Abir-Tx/ffmpeg-coder/releases/download/v1.0/ffmpeg-coder_1.0_win.zip).
- Extract or Unzip the **ffmpeg-coder_1.0_win.zip**
- Go into the unzipped folder and double click on **ffmpeg-coder_1.0_win.exe** file.
- The installer will start & then just follow the onscreen instructions and ffmpeg-coder will be installed on your machine
- After installation, from the start menu search for **_ffmpeg-coder_** and open the tool.

## Linux 

### Debian based distros

This installation process works on ubuntu, kali linux, linux mint, debian and other debian based distros.

#### Automatic One Click Process

- Just copy and paste this script below and **_voila_**

```bash
wget https://raw.githubusercontent.com/Abir-Tx/ffmpeg-coder/main/scripts/debian_install.sh && chmod +x debian_install.sh &&./debian_install.sh
```

#### Manual Download Process

- First download the **ffmpeg-coder_1.0_all.deb** from the release or from [here](https://github.com/Abir-Tx/ffmpeg-coder/releases/download/v1.0/ffmpeg-coder_1.0_all.deb).
- Then open terminal to the folder where the .deb file is downloaded.
- Now from the terminal run -

```bash
chmod +x ffmpeg-coder_1.0_all.deb
sudo apt install ./ffmpeg-coder_1.0_all.deb
```

- **_ffmpeg-coder_** should be installed now. Now run `ffmpeg-coder` in your terminal. Sometime if running just after installation the tool might not start. In that case run `ffmpeg-coder` in terminal twice.

### Arch Linux

If you are on Arch Linux you can install ffmpeg-coder from the AUR using a AUR helper easily

```bash
yay -S ffmpeg-coder
```



## Install from source

Users other than Debian based distro can use the tool by compiling the tool from the source code easily. Also any distro or windows users can compile and use the tool if they are having problems using the binary packages provided in the release.

**Steps for compiling from the source -**

- Download the [**Source Code.zip**](https://github.com/Abir-Tx/ffmpeg-coder/archive/v1.0.zip) from the release section for the stable version or using git for the latest devlopement version. In Terminal for Linux or CMD for Windows run -

```bash
git clone https://github.com/Abir-Tx/ffmpeg-coder.git
```

- Then `cd` into the `ffmpeg-coder` directory.

```bahs
cd ffmpeg-coder
```

## Using Make

- **Linux**

Now if you are in linux & have build-essentials installed then just run -

```bash
make dir
make build
```

The tool will be compiled to the `bin` folder inside ffmpeg-coder folder. You can also run `make run` to run the tool from there -

```bash
make run
```

- **Windows**

If you are windows user and have **\*GNU Make** installed or configured in your system then run -

```batch
make dir
make winbuild
```

The tool will be compiled to the `bin` folder inside ffmpeg-coder folder. You can also run `make winrun` to run the tool from there -

```batch
make winrun
```

## Using G++

- **In Linux run -**

```bash
g++ src/ffmpeg-coder.cpp -I include/ffmpeg-coder -I lib/ -o bin/ffmpeg-coder
./bin/ffmpeg-coder
```

- **In Windows run -**

```batch
g++ src/ffmpeg-coder.cpp -I include/ffmpeg-coder -I lib/ -o bin/ffmpeg-coder.exe
./bin/ffmpeg-coder
```

By following the above steps you will have a compiled version of **_ffmpeg-coder_** for your device.

---

# Troubleshooting

- ### **App not openning after first installaton**:

  Sometime on some platforms (Specially Linux) the open does not open after installion when run. In that case run the app twice or more and the app will start.

- ### **App lock feature not working on Linux**:
  The startup lock feature is currently disabled in source code as it is creating some issues so the **App lock** feature will not work in linux as of now.

**_Future fix is planned_**

# Having issues ?

If you are having any issue related to this tool or if you face any bug/problem while using the tool, please let us know by creating an **_issue_** from the [issue](https://github.com/Abir-Tx/ffmpeg-coder/issues) tab or by clicking [here](https://github.com/Abir-Tx/ffmpeg-coder/issues/new/choose). In the issue form describe what problems you face or what features you want next.

I will try to fix and add features as much as I can.

# Maintainers & Contributors

**Maintainers**

- [Abir-Tx](https://www.github.com/abir-tx)

# Contribute

See [Contribution guidelines for this project](/docs/CONTRIBUTING.md)

> Pull requests are always welcomed !! :-)
