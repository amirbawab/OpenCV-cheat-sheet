#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat imageSrc = imread("lena1.png", CV_LOAD_IMAGE_COLOR);
	Mat imageDest = Mat::zeros(imageSrc.size(), imageSrc.type());;

	// Create windows
	namedWindow("My window 1", WINDOW_AUTOSIZE);
	namedWindow("My window 2", WINDOW_AUTOSIZE);

	// Constants
	double alpha = 0.5;
	int beta = 100;

	// Loop on matrix
	for( int row = 0; row < imageSrc.rows; row++ ){
	    for( int col = 0; col < imageSrc.cols; col++ ){

	        // Loop on channels (0: Blue, 1: Green, 2: Red)
	        for( int c = 0; c < imageSrc.channels(); c++ ) {

	            // g(row, col) = alpha * f(row, col) + beta
	            imageDest.at<Vec3b>(row,col)[c] = saturate_cast<uchar>(alpha *( imageSrc.at<Vec3b>(row,col)[c] ) + beta);
	        }
	    }
	}

	// Show images in windows
	imshow("My window 1", imageSrc);
	imshow("My window 2", imageDest);

	waitKey(0);
	return 0;
}

