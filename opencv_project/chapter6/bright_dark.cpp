#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("images/bright.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!image.empty());

	Mat dst1 = image + 100;
	Mat dst2 = image - 100;
	Mat dst3 = 255 - image;

	Mat dst4(image.size(), image.type());
	Mat dst5(image.size(), image.type());

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols; j++)
		{	 //dst4의경우 255값이 넘어가는 값이 까맣게 나옴
			// dst4.at<uchar>(i, j) = image.at<uchar>(i, j) + 100;
			//255가 넘어간 값을 255로 보장함 saturate_cast를 통해 255값을 캐스팅 해줌
					dst4.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) + 100);
			dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
		}
	}

	imshow("원 영상", image);
	imshow("dst1 - 밝게", dst1);
	imshow("dst2 - 어둡게", dst2);
	imshow("dst3 - 반전", dst3);
	imshow("dst4 - 밝게", dst4);
	imshow("dst5 - 반전", dst5);
	waitKey();
	
	return 0;


}