#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	//순수한 검은 색을 출력하기위해 CMY색공간에서 K값을 검은색으로 표현
	Mat BGR_img = imread("images/color_model.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Scalar white(255, 255, 255);
	Mat CMY_img = white - BGR_img;
	Mat CMY_arr[3];
	split(CMY_img, CMY_arr);

	Mat black;
	min(CMY_arr[0], CMY_arr[1], black);
	min(black, CMY_arr[2], black);

	CMY_arr[0] = CMY_arr[0] - black;
	CMY_arr[1] = CMY_arr[1] - black;
	CMY_arr[2] = CMY_arr[2] - black;

	imshow("black", black);
	imshow("Yellow", CMY_arr[0]);
	imshow("Magenta", CMY_arr[1]);
	imshow("Cyan", CMY_arr[2]);
	waitKey();
	return 0;
}