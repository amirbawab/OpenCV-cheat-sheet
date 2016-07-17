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
	namedWindow("Destination", WINDOW_AUTOSIZE);

	// Destination matrix
	Mat imageDest;

	// Convert to grayscale
	cvtColor(imageSrc, imageDest, CV_BGR2GRAY);

	// Find contours
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(imageDest, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

	// Draw contours
	Mat tmpImage = Mat::zeros(imageSrc.size(), imageSrc.type());
	vector<vector<Point> > approx_contours(contours.size());
	for(size_t i = 0; i< contours.size(); i++ ){

		// Enhance the contours found by reducing the number corners if possible
		approxPolyDP(Mat(contours[i]), approx_contours[i] /*don't overwrite*/, 3 /*accuracy*/, true /*closed*/);

		// Display the difference before and after using the approx method
		cout << "Without approx: " << contours[i].size() << ", with approx: " << approx_contours[i].size() << endl;

		// Draw contours
		drawContours(tmpImage, contours, i /*contours[i]*/, Scalar(rand()%256, rand()%256, rand()%256) /*color*/, 2/*thickness*/, 8/*type*/, hierarchy, 0, Point());
	}

	// Show images
	imshow("Source", imageSrc);
	imshow("Destination", tmpImage);

	// Wait forever
	waitKey(0);

	return 0;
}

