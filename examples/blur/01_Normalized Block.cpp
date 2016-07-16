#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("lena1.png", CV_LOAD_IMAGE_COLOR);
	Mat imageDest = imageSrc.clone();

	// Create windows
	namedWindow("My window 1", WINDOW_AUTOSIZE);
	namedWindow("My window 2", WINDOW_AUTOSIZE);

	// Set kernel size
	int kernelSize=20;

	// Apply blur
	blur( imageSrc, imageDest, Size(kernelSize, kernelSize), Point(-1,-1));

	// Show images in windows
	imshow("My window 1", imageSrc);
	imshow("My window 2", imageDest);

	waitKey(0);
	return 0;
}

