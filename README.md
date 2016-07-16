# OpenCV Cheat Sheet


### Table of Contents

  * [Version](#version)
  * [Installation](#installation)
  * [Eclipse](#eclipse)
  * [Window](#window)
  * [Image](#image)
  * [Blur](#blur)

  
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
imwrite( "img.jpg", image);
```

Show image
```
imshow("My Image", image);
```

Clone image
```
image.clone();
```

Rotate image
```
Mat matRotate = getRotationMatrix2D(Point(imageSrc.rows/2, imageSrc.cols/2) /*center*/, 180 /*angle*/, 1 /*scale*/);
warpAffine(imageSrc, imageDest, matRotate, imageSrc.size() /*new size*/);
```

#### Examples  
* [examples/image/](examples/image)

#### Reference:  
* http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html?highlight=imread#imread
* http://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html

---

### Blur

#### Algorithms

Normalized Block Filter
```
int kernelSize=20;
blur( imageSrc, imageDest, Size(kernelSize, kernelSize), Point(-1,-1));
```

Gaussian Filter
```
int kernelSize=21; // Int: Positive & Odd
GaussianBlur( imageSrc, imageDest, Size(kernelSize, kernelSize), 0, 0);
```

Median Filter
```
int kernelSize=21; // Int: Odd
medianBlur(imageSrc, imageDest, kernelSize);
```

#### Other

Blur part of the image
```
Rect region(0 /*x*/, 0 /*y*/, 200 /*width*/, 200 /*height*/);
int kernelSize = 25;
GaussianBlur(imageSrc(region), imageDest(region), Size(kernelSize,kernelSize), 0, 0); // Mat::operator() overloaded
```

Save only the blurred region in a matrix
```
Rect region(0 /*x*/, 0 /*y*/, 200 /*width*/, 200 /*height*/);
int kernelSize = 25;
Mat imageDest;
GaussianBlur(imageSrc(region), imageDest, Size(kernelSize,kernelSize), 0, 0); // Mat::operator() overloaded
```

#### Examples  
* [examples/blur/](examples/blur)

#### Reference:  
* http://docs.opencv.org/2.4.13/doc/tutorials/imgproc/gausian_median_blur_bilateral_filter/gausian_median_blur_bilateral_filter.html#goal

---
