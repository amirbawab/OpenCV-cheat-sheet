#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Load and store image in a matrix
	Mat image = imread("img.jpg", CV_LOAD_IMAGE_COLOR);
	
	// Create a named window
	namedWindow("My Image", WINDOW_AUTOSIZE);
	
	// Show image in the created named window
	imshow("My Image", image);

	// Wait for user input to avoid terminating the program
	waitKey(0);
	return 0;
}

