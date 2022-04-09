#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// void bgr2hsi(Mat img, Mat &hsv) 
// {
// 	hsv = Mat(img.size(), CV_32FC3);		// 

// 	for (int i = 0; i < img.rows; i++) {
// 		for (int j = 0; j < img.cols; j++)
// 		{
// 			float B = img.at<Vec3b>(i, j)[0];
// 			float G = img.at<Vec3b>(i, j)[1];
// 			float R = img.at<Vec3b>(i, j)[2];

// 			float s = 1 - 3 * min(R, min(G, B)) / (R + B + G);
// 			float v = (R + G + B) / 3.0f;

// 			float tmp1 = ((R - G) + (R - B)) * 0.5f;
// 			float tmp2 = sqrt((R - G) * (R - B) + (G - B) * (G - B));
// 			float angle = (float)acos(tmp1 / tmp2) * (180.f / CV_PI);
// 			float h = (B <= G) ? angle : 360 - angle;

// 			hsv.at<Vec3f>(i, j) = Vec3f(h / 2, s * 255, v);
// 		}
// 	}
// 	hsv.convertTo(hsv, CV_8U);
// }

// int main()
// {
// 	Mat BGR_img = imread("images/color_space.jpg", IMREAD_COLOR);
// 	CV_Assert(BGR_img.data);

// 	Mat HSI_img, HSV_img, hsi[3], hsv[3];

// 	bgr2hsi(BGR_img, HSI_img);
// 	cvtColor(BGR_img, HSV_img, CV_BGR2HSV);
// 	split(HSI_img, hsi);
// 	split(HSV_img, hsv);
	
// 	imshow("BGR_img", BGR_img);
// 	imshow("Hue", hsi[0]);									// 사용자 정의함수 이용 
// 	imshow("Saturation", hsi[1]);
// 	imshow("Intensity", hsi[2]);
// 	imshow("OpenCV_Hue", hsv[0]);						// OpenCV 제공함수 이용
// 	imshow("OpenCV_Saturation", hsv[1]);
// 	imshow("OpenCV_Value", hsv[2]);
// 	waitKey();
// 	return 0;
// }
int main()
{
	Mat BGR_img = imread("images/color_space.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Mat HSV_img, hsv[3],Convert_img;
	cvtColor(BGR_img,HSV_img,CV_BGR2HSV);
	// bgr2hsi(BGR_img, HSI_img);
	cvtColor(BGR_img, HSV_img, CV_BGR2HSV);
	// split(HSI_img, hsi);
	split(HSV_img, hsv);
	//밝기증가
	// hsv[2]= hsv[2]+70;
	threshold(hsv[2],hsv[2],128,255,THRESH_BINARY);
	//merge->Convert_img
	merge(hsv, 3, Convert_img); //배열에대한 머지를 할때는 숫자를 넣으면 됨
	//hsv->BGR로변환
	cvtColor(Convert_img, Convert_img, CV_HSV2BGR);

	imshow("BGR_img", BGR_img);
	// imshow("Hue", hsi[0]);									// ����� �����Լ� �̿� 
	// imshow("Saturation", hsi[1]);
	// imshow("Intensity", hsi[2]);
	imshow("OpenCV_Hue", hsv[0]);						// OpenCV �����Լ� �̿�
	imshow("OpenCV_Saturation", hsv[1]);
	imshow("convert",Convert_img);
	imshow("OpenCV_Value", hsv[2]);
	waitKey();
	return 0;
}