#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{

	//https://m.blog.naver.com/PostView.nhn?blogId=samsjang&logNo=220503082434&referrerCode=0&searchKeyword=opencv ����
	Mat image1 = imread("images/add2.jpg", IMREAD_GRAYSCALE);
	Mat image2 = imread("images/add1.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!(image1.empty() || image2.empty()));

	double alpha = 0.6, beta = 0.7;

	Mat add_img1 = image1 + image2;
	Mat add_img2 = image1 * 0.5 + image2 * 0.5; //�̹����� ����(0.5) ��Ӱ� �� �̹���1�� �̹���2�� ����
	Mat add_img3 = image1 * alpha + image2 * (1 - alpha);
	
	Mat add_img4, sub_img1, sub_img2;;
	addWeighted(image1, alpha, image2, beta, 0, add_img4); //�Ӱ谪�� �־��ָ� �ٷ� ���

	imshow("image1", image1),	imshow("image2", image2);
	imshow("add_img1", add_img1),	imshow("add_img2", add_img2);
	imshow("add_img3", add_img3),	imshow("add_img4", add_img4);
	waitKey(0);
	return 0;
}