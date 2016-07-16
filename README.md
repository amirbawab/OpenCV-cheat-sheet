# OpenCV Cheat Sheet


### Table of Contents

  * [Version](#version)
  * [Installation](#installation)
  * [Eclipse](#eclipse)
  * [Window](#window)
  * [Image](#image)

  
### Version
* OpenCV 2.4
  
### Installation

#### Ubuntu

* **Required**
```
sudo apt-get install build-essential
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
```

* Download OpenCV

```
wget https://github.com/Itseez/opencv/archive/2.4.13.zip 
mkdir -p /tmp/OpenCV
mv opencv-2.4.13.zip /tmp/OpenCV
cd /tmp/OpenCV
unzip opencv-2.4.13.zip
```
  
* Make OpenCV 
```
cd opencv-2.4.13
mkdir release
cd release
cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..
make
sudo make install
```

#### Reference:  
http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html#linux-installation

---

### Eclipse

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

#### Reference:  
* http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_eclipse/linux_eclipse.html

---

### Window

Create window
```
namedWindow("My window", WINDOW_AUTOSIZE);
```

Destroy window
```
destroyWindow("My window");
```

Destroy all windows
```
destroyAllWindows();
```

Move window
```
moveWindow("My window", 150 /*x*/, 160 /*y*/);
```

Resize window
```
resizeWindow("My window", 500 /*width*/, 500 /*height*/);
```

Set mouse call back
```
setMouseCallback("My Image", [](int event, int x, int y, int flags, void* userdata) {
 cout << "X: " << x << ", Y: " << y << endl;
}, 0);
```

Wait instead of terminating the program
```
waitKey(0);
```

#### Examples  
* [examples/window/](examples/window)

#### Reference:  
* http://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html

---

### Image

Load and store image in a matrix
```
Mat image = imread("img.jpg", CV_LOAD_IMAGE_COLOR);
```

Save image from matrix to file
```
imwrite( "img.jpg", mat);
```

Show image
```
imshow("My Image", image);
```

#### Examples  
* [examples/image/](examples/image)

#### Reference:  
* http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html?highlight=imread#imread
* http://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html

---
