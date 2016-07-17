#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("shapes.png", CV_LOAD_IMAGE_COLOR);

	// Create windows
	namedWindow("Source", WINDOW_AUTOSIZE);

	// Destination matrix
	Mat imageDest;

	// Convert to grayscale
	cvtColor(imageSrc, imageDest, CV_BGR2GRAY);

	// Find contours
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(imageDest, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	// Loop on contours
	for(size_t i = 0; i< contours.size(); i++ ){

		// Enhance the contours found by reducing the number corners if possible
		approxPolyDP(Mat(contours[i]), contours[i] /*overwrite*/, 3 /*accuracy*/, true /*closed*/);

		// Print contour area
		cout << "Contour area: " << contourArea(contours[i]) << endl;
	}

	// Show images
	imshow("Source", imageSrc);

	// Wait forever
	waitKey(0);

	return 0;
}


