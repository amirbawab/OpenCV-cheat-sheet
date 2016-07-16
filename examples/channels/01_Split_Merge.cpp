#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("lena1.png", CV_LOAD_IMAGE_COLOR);
	Mat imageDest;

	// Create windows
	namedWindow("My window 1", WINDOW_AUTOSIZE);
	namedWindow("My window 2", WINDOW_AUTOSIZE);
	namedWindow("blue", WINDOW_AUTOSIZE);
	namedWindow("green", WINDOW_AUTOSIZE);
	namedWindow("red", WINDOW_AUTOSIZE);

	// Prepare split vector
	vector<Mat> bgr;

	// Split channels
	split(imageSrc, bgr);

	// Merge channels again
	merge(bgr, imageDest);

	// Show images in windows
	imshow("My window 1", imageSrc);
	imshow("blue", bgr[0]);
	imshow("green", bgr[1]);
	imshow("red", bgr[2]);
	imshow("My window 2", imageDest);

	waitKey(0);
	return 0;
}

