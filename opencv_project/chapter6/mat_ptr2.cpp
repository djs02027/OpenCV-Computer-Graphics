#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	uchar data[] = {
		1,	2,	3,
		1,	2,	3,
		1,	2,	3,
	};

	Mat m1(3, 3, CV_8UC1, data);
	Mat m2(m1.size(), m1.type());
	Mat m3(m1.size(), CV_64FC3);

	MatConstIterator_<uchar> it_m1 = m1.begin<uchar>();
	MatIterator_<uchar> it_m2 = m2.begin<uchar>();
	Mat_<Vec3d>::iterator it_m3 = m3.begin<Vec3d>();
	//Mat_<Vec3f>::iterator it_m3 = m3.begin<Vec3f>();
	for (; it_m1 != m1.end<uchar>(); ++it_m1, ++it_m2, ++it_m3)
	{
		*it_m2 = *it_m1;
		//이터레이터에 접근시 포인터로 값에 접근할수있음
		(*it_m3)[0] = *it_m1 * 1.1;
		(*it_m3)[1] = *it_m1 * 1.2;
		(*it_m3)[2] = *it_m1 * 1.3;
	}
	

	cout << "m1 = " << endl
		 << m1 << endl;
	cout << "m2 = " << endl
		 << m2 << endl;
	cout << "m3 = " << endl
		 << m3 << endl;
	return 0;

	
}