#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int  main()
{
	Mat  image(300, 500, CV_8UC1, Scalar(255));
	Point2f  center(250, 150), pts[4];
	Size2f  size(300, 100);
	RotatedRect  rot_rect(center, size, 20);

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0, 0, 255), 1);
	circle(image, rot_rect.center, 3, Scalar(255,0,0), FILLED);

	rot_rect.points(pts);
	for (int i = 0; i < 4; i++)
	{
		circle(image, pts[i], 4, Scalar(0), 1);
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0,255,0), 2);
	}
	// line(image, pts[0],pts[1], Scalar(0,255,0), FILLED);
	imshow("회전사각형", image);
	waitKey(0);
	return 0;
}