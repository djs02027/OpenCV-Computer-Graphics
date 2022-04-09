#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("images/flip_test.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img;
	flip(image, x_axis, 0);
	flip(image, y_axis, 1);
	flip(image, xy_axis, -1);

	repeat(image, 1, 2, rep_img);
	transpose(image, trans_img);

	imshow("image", image);
	imshow("x_axis", x_axis);		// x축기준 상하반전
	imshow("y_axis", y_axis);		// y축기준 좌우반전
	imshow("xy_axis", xy_axis);		// 좌우상하반전
	imshow("rep_img", rep_img);		// 반복 복사
	imshow("trans_img", trans_img);		// 시계 반대방향 90도 회전

	Matx33d m(1, 4, 7, 2, 5, 8, 3, 6, 9);	// 대각선으로 반전
	cout << m << endl;

	Matx33d m2;
	transpose(m, m2);
	cout << m2 << endl;

	Matx33d m3;
	transpose(m2, m3);
	cout << m3 << endl;

	waitKey();		// 이미지가 꺼지지 않게 함
	return 0;
}