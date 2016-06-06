## Synopsis

Using ARM GCC Toolchain and Make


## Requirements

Works Only on Ubuntu Based Linux Distros. Tested with Mint 17.1

First download and install arm toolchain provided by https://launchpad.net/gcc-arm-embedded

```
$ sudo add-apt-repository ppa:terry.guo/gcc-arm-embedded 
$ sudo apt-get update
$ sudo apt-get install gcc-arm-none-eabi
```

Before the Texane STLink installation, yoy need to install some dependencies.

```
$ sudo apt-get install libusb-1.0-0-dev git pkg-config build-essential dh-autoreconf
```

After that, clone Texane STLink and Install the provided utilities

```
$ git clone https://github.com/texane/stlink stlink-install
$ cd stlink-install
$ ./autogen.sh
$ ./configure
$ make
$ sudo make install
$ sudo cp *.rules /etc/udev/rules.d
$ sudo restart udev
```

## Usage

```
$ git clone https://gitlab.com/open-source-applications/stm32-discovery
$ cd "Source Code"/
$ cd (choose one of the self-contained examples)
$ make
$ make program
```

## License

Copyright (c)  2015, 2016 Io. D

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
