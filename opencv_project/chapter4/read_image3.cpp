#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void print_matInfo(string name, Mat img)
{
	string str;
	int depth = img.depth();

	if (depth == CV_8U)
		str = "CV_8U";
	else if (depth == CV_8S)
		str = "CV_8S";
	else if (depth == CV_16U)
		str = "CV_16U";
	else if (depth == CV_16S)
		str = "CV_16S";
	else if (depth == CV_32S)
		str = "CV_32S";
	else if (depth == CV_32F)
		str = "CV_32F";
	else if (depth == CV_64F)
		str = "CV_64F";
	cout << name;
	cout << format(": depth(%d) channels(%d) -> ?λ£ν: ", depth, img.channels());
	cout << str << "C" << img.channels() << endl;
}

int main()
{
	string filename1 = "images/read_16.tif"; // 16λΉνΈ ??
	string filename2 = "images/read_32.tif"; // 32λΉνΈ ??
	Mat color2unchanged1 = imread(filename1, IMREAD_UNCHANGED);
	Mat color2unchanged2 = imread(filename2, IMREAD_UNCHANGED);
	CV_Assert(color2unchanged1.data && color2unchanged2.data);

	Rect roi(100, 100, 1, 1);
	cout << "16/32λΉνΈ ?? ?? ¬ μ’ν (100,100) ??κ°? " << endl;
	cout << "color2unchanged1 " << color2unchanged1(roi) << endl;
	cout << "color2unchanged2  " << color2unchanged2(roi) << endl;

	print_matInfo("color2unchanged1", color2unchanged1);
	print_matInfo("color2unchanged2", color2unchanged2);
	imshow("color2unchanged1", color2unchanged1);
	imshow("color2unchanged2", color2unchanged2);
	waitKey(0);
	return 0;
}