# OpenCV Cheat Sheet


### Table of Contents

  * [Version]()
  * [Installation]()
  * [Eclipse]()
  * [Image]()
  
  
#### Version
* OpenCV 2.4
  
#### Installation

##### Ubuntu

1. **Required**
```
sudo apt-get install build-essential
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```

2. Download OpenCV

```
wget https://github.com/Itseez/opencv/archive/2.4.13.zip 
mkdir -p /tmp/OpenCV
mv opencv-2.4.13.zip /tmp/OpenCV
cd /tmp/OpenCV
unzip opencv-2.4.13.zip
```
  
3. Make OpenCV 
```
cd opencv-2.4.13
mkdir release
cd release
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..
make
sudo make install
```

#### Eclipse

* Project > Properties > C/C++ Build [Menu] > Tool Settings [Tab] > GCC C++ Compiler [Option] > Includes [Option] > Include paths (-I)  

  Add:
```
/usr/local/include/opencv
```

* Project > Properties > C/C++ Build [Menu] > Tool Settings [Tab] > GCC C++ Linker [Option] > Libraries [Option] > Libraries (-l)  

  Add:
```
opencv_core
opencv_imgproc
opencv_highgui
opencv_ml
opencv_video
opencv_features2d
opencv_calib3d
opencv_objdetect
opencv_contrib
opencv_legacy
opencv_flann
```

* Project > Properties > C/C++ Build [Menu] > Tool Settings [Tab] > GCC C++ Linker [Option] > Libraries [Option] > Library search path (-L)  

  Add:
```
/usr/local/lib
```

Reference:  
http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_eclipse/linux_eclipse.html

#### Image

