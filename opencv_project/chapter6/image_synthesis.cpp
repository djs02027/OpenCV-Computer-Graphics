#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{

	//https://m.blog.naver.com/PostView.nhn?blogId=samsjang&logNo=220503082434&referrerCode=0&searchKeyword=opencv 참고
	Mat image1 = imread("images/add2.jpg", IMREAD_GRAYSCALE);
	Mat image2 = imread("images/add1.jpg", IMREAD_GRAYSCALE);
	CV_Assert(!(image1.empty() || image2.empty()));

	double alpha = 0.6, beta = 0.7;

	Mat add_img1 = image1 + image2;
	Mat add_img2 = image1 * 0.5 + image2 * 0.5; //이미지를 절반(0.5) 어둡게 한 이미지1과 이미지2를 더함
	Mat add_img3 = image1 * alpha + image2 * (1 - alpha);
	
	Mat add_img4, sub_img1, sub_img2;;
	addWeighted(image1, alpha, image2, beta, 0, add_img4); //임계값을 넣어주면 바로 출력

	imshow("image1", image1),	imshow("image2", image2);
	imshow("add_img1", add_img1),	imshow("add_img2", add_img2);
	imshow("add_img3", add_img3),	imshow("add_img4", add_img4);
	waitKey(0);
	return 0;
}