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

	// Loop on contours
	Mat tmpImage = Mat::zeros(imageSrc.size(), imageSrc.type());
	for(size_t i = 0; i< contours.size(); i++ ){

		// Circle around contour
		Point2f center;
		float radius;
		minEnclosingCircle(contours[i], center, radius);
		circle( tmpImage, center, radius, Scalar(255, 0, 0), 2/*thickness*/);

		// Rectangle around contour
		Rect rect = boundingRect(Mat(contours[i]));
		rectangle(tmpImage, rect.tl(), rect.br(), Scalar(0,255,0), 2 /*thickness*/);

		// Draw contours
		drawContours(tmpImage, contours, i /*contours[i]*/, Scalar(0, 0, 255) /*color*/, 2/*thickness*/, 8/*type*/, hierarchy, 0, Point());

	}

	// Show images
	imshow("Source", imageSrc);
	imshow("Destination", tmpImage);

	// Wait forever
	waitKey(0);

	return 0;
}


