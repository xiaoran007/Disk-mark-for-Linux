# Disk mark for linux
GUI disk mark tool for linux, has similar CrystalDiskMark UI style, use C and GTK4.

It uses fio and xcore for disk benchmark.

## Supported OS / Architecture
This project was developed mainly for linux systems with the gnome desktop. It also works fine on the following platforms.

* macOS: intel, Apple silicon
* Linux with gnome desktop: amd64, arm64 (tested on debian and ubuntu)

GTK provides support for a wide range of systems and architectures, so it is possible to use this application on other systems (freeBSD) and architectures (armv7, mips) as well.

## Build from source
To build this application from source, gcc and make is needed. In macOS, the default gcc points to clang, which is tested that can be used to build this application, so you don't need to install additional gcc.

install GTK4 development kit from package manager, dependencies (glib and other packages) will be installed automatically.
```shell
brew install gtk4 # macOS
sudo apt install libgtk-4-dev # debian / ubuntu
```
then install pkg-config 
```shell
brew install pkg-config # macOS
sudo apt install pkg-config # debian / ubuntu
```
in project's directory, run make command:
```shell
make main
```
after build, you can find binary executable file in ./build directory.