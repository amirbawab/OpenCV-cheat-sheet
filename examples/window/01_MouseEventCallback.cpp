#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

/**
 * Struct used later as a `userdata`
 */
struct Object {
	int id = 100;
};

ostream& operator<<(std::ostream& stream, const Object& obj) {
	stream << "ID=" << obj.id;
	return stream;
}

int main( int argc, char** argv ) {

	// Create matrix from image
	Mat image = imread("lena1.png", CV_LOAD_IMAGE_COLOR);

	// Create window
	namedWindow("My Image", WINDOW_AUTOSIZE);

	// Show image in window
	imshow("My Image", image);

	// Create an object
	Object *objptr = new Object;

	// Set callback function on mouse event
	setMouseCallback("My Image", [](int event, int x, int y, int flags, void* userdata) {
		cout << "=================================" << endl;
		cout << "X: " << x << ", Y: " << y << endl;
		cout << "Event type: " << event << endl;
		/**
		 * cv::EVENT_MOUSEMOVE = 0,
		 * cv::EVENT_LBUTTONDOWN = 1,
		 * cv::EVENT_RBUTTONDOWN = 2,
		 * cv::EVENT_MBUTTONDOWN = 3,
		 * cv::EVENT_LBUTTONUP = 4,
		 * cv::EVENT_RBUTTONUP = 5,
		 * cv::EVENT_MBUTTONUP = 6,
		 * cv::EVENT_LBUTTONDBLCLK = 7,
		 * cv::EVENT_RBUTTONDBLCLK = 8,
		 * cv::EVENT_MBUTTONDBLCLK = 9,
		 * cv::EVENT_MOUSEWHEEL = 10,
		 * cv::EVENT_MOUSEHWHEEL = 11
		 */

		cout << "Flag: " << flags << endl;
		/**
		 * cv::EVENT_FLAG_LBUTTON = 1,
		 * cv::EVENT_FLAG_RBUTTON = 2,
		 * cv::EVENT_FLAG_MBUTTON = 4,
		 * cv::EVENT_FLAG_CTRLKEY = 8,
		 * cv::EVENT_FLAG_SHIFTKEY = 16,
		 * cv::EVENT_FLAG_ALTKEY = 32
		 */

		// User defined value
		cout << "Userdata: " << *(Object*)userdata << endl;
	}, objptr /*extra pointer parameter*/);

	// Wait for user input
	waitKey(0);

	// Delete pointer
	delete objptr;
	return 0;
}

