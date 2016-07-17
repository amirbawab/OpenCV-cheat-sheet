#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("lena1.png", CV_LOAD_IMAGE_COLOR);

	// Create windows
	namedWindow("My window 1", WINDOW_AUTOSIZE);

	// Show image in window
	imshow("My window 1", imageSrc);

	// Create trackbar
	int brightnessValue = 0;
	createTrackbar("Brightness", "My window 1", &brightnessValue, 255, [](int brightnessValue, void *userData){

		// Set brightness
		Mat imageDest = *(Mat*)userData + Scalar(brightnessValue, brightnessValue, brightnessValue);

		// Show image in window
		imshow("My window 1", imageDest);
	}, &imageSrc);

	// Wait forever
	waitKey(0);
	return 0;
}

