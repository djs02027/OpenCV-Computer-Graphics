#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int  main()
{
	Size2d  sz(100.5, 60.6);
	Point2f  pt1(20.f, 30.f), pt2(100.f, 200.f);

	// Rect_ ��ü �⺻ ���� ���
	Rect_<int>    rect1(10, 10, 30, 50); // x��ǥ y��ǥ �ʺ� ����  
	Rect_<float>   rect2(pt1, pt2);
	Rect_<double> rect3(Point2d(20.5, 10), sz);

	// ���� ���� ��� & ���� ����
	Rect   rect4 = rect1 + (Point)pt1; //int�� ���� ����
	Rect2f rect5 = rect2 + (Size2f)sz; // float ���� ����
	Rect2d rect6 = rect1 & (Rect)rect2; // double ���� ����

	// ��� ���
	cout << "rect3 = " << rect3.x << "," << rect3.y << ", ";
	cout << rect3.width << "x" << rect3.height << endl;
	cout << "rect4 = " << rect4.tl() << "  " << rect4.br() << endl;
	cout << "rect5 ũ�� = " << rect5.size() << endl;
	cout << "[rect6] = " << rect6 << endl;

	Mat image(500, 500, CV_8SC3, Scalar(255,255,255));
	Scalar red(0,0,255);
	Scalar blue(255,0,0);
	Scalar green(0,255,0);
	Scalar purple(255,0,255);
	Scalar yellow(0,255,255);
	Scalar cyan(255,255,0);

	rectangle(image, rect1, red);
	rectangle(image, rect2, blue);
	rectangle(image, rect3, green);
	rectangle(image, rect4, purple);
	rectangle(image, rect5, yellow);

	rect6 += Size2d(-2.0, -2.0);
	rect6 += Point2d(1,1);
	rectangle(image, rect6, cyan, FILLED, 0); 


	imshow("�簢�� �ǽ�", image);

	waitKey(0);




	return 0;
}