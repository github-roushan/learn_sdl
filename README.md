# SDL2 Learning Repository

This repository documents my learning journey with **SDL2**, a popular library for multimedia, graphics, and game development.

## Build Instructions

To compile and run an example program (e.g., `prog_003.cpp`), use the following command:

```bash
g++ prog_003.cpp -o app -I/usr/include/SDL2 -lSDL2
```

Then, run the compiled program:

```bash
./app
```

## Requirements

* **C++ Compiler** (e.g., `g++`)
* **SDL2 Library** installed on your system

## Installation (Linux)

Depending on your Linux distribution, use one of the following commands:

### Ubuntu / Debian

```bash
sudo apt update
sudo apt install g++ libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
```

### Fedora

```bash
sudo dnf install gcc-c++ SDL2-devel SDL2_image-devel SDL2_mixer-devel SDL2_ttf-devel
```

### Arch Linux

```bash
sudo pacman -S sdl2 sdl2_image sdl2_mixer sdl2_ttf
```

### openSUSE

```bash
sudo zypper install gcc-c++ libSDL2-devel libSDL2_image-devel libSDL2_mixer-devel libSDL2_ttf-devel
```

## Goal

The aim of this repo is to:

* Practice SDL2 basics
* Build a foundation for simple 2D games
* Document useful commands and examples for future reference