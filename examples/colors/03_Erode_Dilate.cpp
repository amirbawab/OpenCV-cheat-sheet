/**
 * Original code:
 * http://opencv-srf.blogspot.ca/2010/09/object-detection-using-color-seperation.html
 */

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
	namedWindow("My window 2", WINDOW_AUTOSIZE);

	// HSV low-high values
	int lowH = 0;
	int highH = 179;

	int lowS = 0;
	int highS = 255;

	int lowV = 0;
	int highV = 255;

	// Create trackbar
	createTrackbar("LowH", "My window 2", &lowH, 179); //Hue (0 - 179)
	createTrackbar("HighH", "My window 2", &highH, 179);

	createTrackbar("LowS", "My window 2", &lowS, 255); //Saturation (0 - 255)
	createTrackbar("HighS", "My window 2", &highS, 255);

	createTrackbar("LowV", "My window 2", &lowV, 255); //Value (0 - 255)
	createTrackbar("HighV", "My window 2", &highV, 255);

	while(true) {

		Mat imageDest;

		// Convert BGR to HSV
		cvtColor(imageSrc, imageDest, COLOR_BGR2HSV);

		// Get colors in specified range
		inRange(imageDest, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), imageDest);

		// Morphological opening (remove small objects from the foreground)
		erode(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		dilate(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		// Morphological closing (fill small holes in the foreground)
		dilate(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );
		erode(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)) );

		// Show image in window
		imshow("My window 1", imageDest);

		waitKey(50);
	}

	// Wait forever
	waitKey(0);
	return 0;
}

