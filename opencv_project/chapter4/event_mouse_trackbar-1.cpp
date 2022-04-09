#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

string title = "밝기변경", bar_name = "Brightness Value"; // 전역변수 선언
Mat image;

void onChange(int value, void *userdata)
{
	int add_value = value - 130;
	string text = "add value " + to_string(add_value);
	cout << text << endl;

	Mat tmp = image + add_value;
	Point shade = Point(52, 52);
	int font = FONT_HERSHEY_PLAIN;

	putText(tmp, text, shade, font, 1.8, Scalar(0, 0, 0), 2);
	imshow(title, tmp);
}

void onMouse(int event, int x, int y, int flags, void *param)
{
	if (event == EVENT_RBUTTONDOWN)
	{
		add(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
	else if (event == EVENT_LBUTTONDOWN)
	{
		subtract(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0));
		imshow(title, image);
	}
}

int main()
{
	int value = 130;
	image = Mat(300, 400, CV_8UC1, Scalar(120));

	namedWindow(title, WINDOW_NORMAL);
	createTrackbar(bar_name, title, &value, 255, onChange);
	setMouseCallback(title, onMouse, 0);

	imshow(title, image);
	waitKey(0);
	return 0;
}