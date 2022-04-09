#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("images/pixel_test.jpg", IMREAD_GRAYSCALE);
	if (image.empty())
	{
		cout << "������ ���� �� �߽��ϴ�." << endl;
		exit(1);
	}

	Rect roi(135, 95, 20, 15);
	Mat roi_img = image(roi); //���ɿ��� <Mat����>
	cout << "[roi_img] =" << endl;

	for (int i = 0; i < roi_img.rows; i++)
	{
		for (int j = 0; j < roi_img.cols; j++)
		{
			cout.width(5);
			cout << (int)roi_img.at<uchar>(i, j);
		}
		cout << endl;
	}
	//cout << roi_img << endl << endl;

	rectangle(image, roi, Scalar(255), 1);
	imshow("image", image);
	resize(roi_img, roi_img, Size(roi_img.cols*8, roi_img.rows*8));
	imshow("roi image", roi_img);

	waitKey();
	return 0;
}