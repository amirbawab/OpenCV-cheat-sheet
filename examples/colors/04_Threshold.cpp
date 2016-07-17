#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("lena1.png", CV_LOAD_IMAGE_COLOR);

	// Create windows
	namedWindow("Source", WINDOW_AUTOSIZE);
	namedWindow("Destination", WINDOW_AUTOSIZE);

	int val1 = 0;
	int val2 = 0;

	createTrackbar("Val1", "Destination", &val1, 255);
	createTrackbar("Val2", "Destination", &val2, 255);

	// Keep updating
	while(true) {

		// Destination matrix
		Mat imageDest;

		// Convert to grayscale
		cvtColor(imageSrc, imageDest, CV_BGR2GRAY);

		// Apply threshold
		threshold(imageDest, imageDest, 150, 255, CV_THRESH_BINARY);

		// Show images
		imshow("Source", imageSrc);
		imshow("Destination", imageDest);

		// Wait forever
		waitKey(50);
	}

	return 0;
}

