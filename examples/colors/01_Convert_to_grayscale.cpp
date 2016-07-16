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

	// Convert back to color
	cvtColor(imageSrc, imageSrc, CV_BGR2GRAY);

	// Show images in windows
	imshow("My window 1", imageSrc);

	waitKey(0);
	return 0;
}

