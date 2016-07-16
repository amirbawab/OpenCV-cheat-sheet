#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("lena1.png", CV_LOAD_IMAGE_GRAYSCALE);

	// Create windows
	namedWindow("My window 1", WINDOW_AUTOSIZE);

	// Count channels - grayscale
	cout << imageSrc.channels() << endl; // Prints: 1

	// Convert back to color
	cvtColor(imageSrc, imageSrc, CV_GRAY2BGR);

	// Count channels - BGR
	cout << imageSrc.channels() << endl; // Prints: 3

	// Show images in windows
	imshow("My window 1", imageSrc);

	waitKey(0);
	return 0;
}

