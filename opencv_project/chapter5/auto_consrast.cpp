#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("images/minMax.jpg", IMREAD_GRAYSCALE);
	
	double minVal, maxVal;
	minMaxIdx(image, &minVal, &maxVal);

	double ratio = (maxVal - minVal)/ 255.0 ;
	Mat  dst = (image - minVal) / ratio;

	cout << "ratio  = " << ratio << endl; 	// ratio: 0.301961
	cout << "min value  = " << minVal << endl; 	// min: 0
	cout << "max value  = " << maxVal << endl;	// max: 77

	imshow("image", image);
	imshow("dst" , dst );
	waitKey();
	return 0;
}






