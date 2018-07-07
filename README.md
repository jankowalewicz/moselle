![banner](https://raw.githubusercontent.com/jankowalewicz/moselle/master/gh-resources/banner.png)

The project aims to be a UI for ICE (in-car-entertainment) system. Mainly used together with the [Raspberry Pi 3](https://www.raspberrypi.org/products/raspberry-pi-3-model-b-plus/) and a [touchscreen](https://www.waveshare.com/3.2inch-rpi-lcd-b.htm).

### Planned features

- Music player
- Bluetooth audio streaming
- Profile management (different profiles for different drivers)
- Integrated apps (navigation? messages?)

### Building

**Not ready for production use yet!**

    Dev env: Ubuntu 18.04 LTS

You'll need at least [Qt 5.9.x](http://download.qt.io/archive/qt/5.9/) and g++ together with make.

    git clone https://github.com/jankowalewicz/moselle.git
    cd moselle
    qmake
    make
    ./msle
    
Currently just a boilerplate window shows up.

### License

The Moselle project is licensed under the terms of the MIT License.

```
Copyright (c) 2018 Jan Kowalewicz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
