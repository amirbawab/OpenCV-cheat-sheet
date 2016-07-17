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
	Mat imageSrc = imread("bb1.jpg", CV_LOAD_IMAGE_COLOR);

	// Create windows
	namedWindow("Source", WINDOW_AUTOSIZE);
	namedWindow("Destination", WINDOW_AUTOSIZE);
	namedWindow("Control", WINDOW_AUTOSIZE);

	// HSV low-high values
	int lowH = 0;
	int highH = 179;

	int lowS = 0;
	int highS = 255;

	int lowV = 0;
	int highV = 255;

	// Create trackbar
	createTrackbar("LowH", "Control", &lowH, 179); //Hue (0 - 179)
	createTrackbar("HighH", "Control", &highH, 179);

	createTrackbar("LowS", "Control", &lowS, 255); //Saturation (0 - 255)
	createTrackbar("HighS", "Control", &highS, 255);

	createTrackbar("LowV", "Control", &lowV, 255); //Value (0 - 255)
	createTrackbar("HighV", "Control", &highV, 255);

	// Keep reading values from control window
	while(true) {

		// Destination image
		Mat imageDest;

		// Convert BGR to HSV
		cvtColor(imageSrc, imageDest, COLOR_BGR2HSV);

		// Get colors in specified range
		inRange(imageDest, Scalar(lowH, lowS, lowV), Scalar(highH, highS, highV), imageDest);

		// Morphological opening (remove small objects from the foreground)
		erode(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(8, 8)) );
		dilate(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(8, 8)) );

		// Morphological closing (fill small holes in the foreground)
		dilate(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(8, 8)) );
		erode(imageDest, imageDest, getStructuringElement(MORPH_ELLIPSE, Size(8, 8)) );

		// Create moment
		Moments mmts = moments(imageDest);

		// Calculate center x and y
		double x = mmts.m10 / mmts.m00;
		double y = mmts.m01 / mmts.m00;

		// Draw circle at x and y
		Mat tmpSource = imageSrc.clone();
		circle(tmpSource, Point(x, y), 10, Scalar(0, 0, 255), 10);

		// Show images in windows
		imshow("Destination", imageDest);
		imshow("Source", tmpSource);

		// Delay 50ms
		waitKey(50);
	}
	return 0;
}

