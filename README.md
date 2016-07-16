# OpenCV Cheat Sheet


### Table of Contents

  * [Version](#version)
  * [Installation](#installation)
  * [Eclipse](#eclipse)
  * [Image](#image)
  
  
#### Version
* OpenCV 2.4
  
#### Installation

##### Ubuntu

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

Reference:  
http://docs.opencv.org/2.4/doc/tutorials/introduction/linux_install/linux_install.html#linux-installation

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

Load and store image in a matrix
```
Mat image = imread("img.jpg", CV_LOAD_IMAGE_COLOR);
```
Parameters for `imread()`:	

* **filename**  
  Name of file to be loaded.

* **flags**

    * CV_LOAD_IMAGE_ANYDEPTH - If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.
    * CV_LOAD_IMAGE_COLOR - If set, always convert image to the color one
    * CV_LOAD_IMAGE_GRAYSCALE - If set, always convert image to the grayscale one
    * > 0 Return a 3-channel color image.
    * = 0 Return a grayscale image.
    * < 0 Return the loaded image as is (with alpha channel).

Reference:  
http://docs.opencv.org/2.4/modules/highgui/doc/reading_and_writing_images_and_video.html?highlight=imread#imread

Show image
```
// Create a named window
namedWindow("My Image", WINDOW_AUTOSIZE);

// Displays image in the named window
imshow("My Image", image);

// Wait for key press to avoid terminating the program
waitKey(0);
```

Parameters for `namedWindow()`:	

* **name**  
  Name of the window (key).

* **flags**

    * WINDOW_NORMAL If this is set, the user can resize the window (no constraint).
    * WINDOW_AUTOSIZE If this is set, the window size is automatically adjusted to fit the displayed image (see imshow() ), and you cannot change the window size manually.
    * WINDOW_OPENGL If this is set, the window will be created with OpenGL support.

Reference:  
http://docs.opencv.org/2.4/modules/highgui/doc/user_interface.html

##### Examples  
https://github.com/amirbawab/OpenCV-Cheat-Sheet/blob/master/examples/image
