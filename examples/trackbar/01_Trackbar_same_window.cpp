#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("lena1.png", CV_LOAD_IMAGE_COLOR);
	Mat imageDest;

	// Create window
	namedWindow("My window 1", WINDOW_AUTOSIZE);

	// Create trackbar
	int brightnessValue = 50;
	createTrackbar("Brightness", "My window 1", &brightnessValue, 255);

	// Keep updating the image
	while (true) {

		 // Set brightness
		 imageDest = imageSrc + Scalar(brightnessValue, brightnessValue, brightnessValue);

		 // Show image in window
		 imshow("My window 1", imageDest);

		 // Delay 50ms
		 waitKey(50);
	}

	return 0;
}

