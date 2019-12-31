# reMarkable splashscreen
replacement for remarkable-shutdown / show any image

## Why
 - remarkable-shutdown resets the background to black before displaying the image.
The goal is to have the last page still displayed, even when the devices has powered down.(utilizing a mostly transparent png)
- could be used as a simple util for showing images


## Usage
remarkable-splash file-path

without any parameter the /usr/share/remarkable/poweroff.png is displayed

## How to compile
the usual
```
source 
qmake
make
```
