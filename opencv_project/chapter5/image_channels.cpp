#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("images/color.jpg", IMREAD_COLOR);
	CV_Assert(image.data);

	Mat bgr[3];
	split(image, bgr);

	imshow("image", image);
	imshow("blue channel", bgr[0]);
	imshow("green channel", bgr[1]);
	imshow("red channel", bgr[2]);
	
	vector<Mat> vecbgr;
	Mat newImage;

	vecbgr.push_back(bgr[0]);
	vecbgr.push_back(bgr[1]);
	vecbgr.push_back(bgr[2]);

	bgr[0] = bgr[0] + 50;		// 블루채널에 50을 더한다
	bgr[1] = bgr[1] + 50;		// 그린채널에 50을 더한다
	bgr[2] = bgr[2] + 50;		// 레드채널에 50을 더한다

	merge(vecbgr, newImage);	// 머지를 사용해 다시 합친다
	imshow("new image", newImage);

	waitKey(0);
	return 0;
}