#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("images/cons.jpg", 1);
	CV_Assert(image.data);

	Mat  mask(image.size(), CV_8U, Scalar(0));
	mask(Rect(20, 40, 70, 70)).setTo(255);

	Scalar sum_value = sum(image);
	Scalar mean_value1 = mean(image);
	Scalar mean_value2 = mean(image, mask);// 마스크 1 영역만 평균 계산 (AdaptiveTresheild)

	cout << "[sum_value] = " << sum_value << endl;
	cout << "[mean_value1] = " << mean_value1 << endl;
	cout << "[mean_value2] = " << mean_value2 << endl << endl; //평균값

	Mat mean, stddev;
	meanStdDev(image, mean, stddev);
	cout << "[mean] = " << mean << endl;
	cout << "[stddev] = " << stddev << endl << endl;

	meanStdDev(image, mean, stddev, mask);
	cout << "[mean] = " << mean << endl;
	cout << "[stddev] = " << stddev << endl; //표준편차
	rectangle(image, Rect(20, 40, 70, 70), Scalar(0,0,255));

	imshow("image", image),  imshow("mask", mask);	
	waitKey();
	return 0;
}