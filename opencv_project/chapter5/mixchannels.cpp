#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat ch0(3, 4, CV_8U, Scalar(10));
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));
	Mat ch_012;

	vector<Mat> vec_012;
	vec_012.push_back(ch0);		// 벡터에 행렬 추가
	vec_012.push_back(ch1);
	vec_012.push_back(ch2);
	merge(vec_012, ch_012);

	Mat ch_02(ch_012.size(), CV_8UC2);	// 2ch
	Mat  ch_1(ch_012.size(), CV_8UC1);	// 1ch

	Mat out[] = { ch_02, ch_1 };	// 2ch, 1ch

	// 원본 0 -> 출력 0, 원본 2 -> 출력 1, 원본 1 -> 출력 2
	int from_to[] = { 0, 0, 2, 1, 1, 2 };

	mixChannels(&ch_012, 1, out, 2, from_to, 3);

	cout << "[ch_012] = " << endl << ch_012 << endl << endl;
	cout << "[ch_02] = " << endl << ch_02 << endl;
	cout << "[ch_1] = " << endl << ch_1 << endl ;

	// --- 2 --- //
	Mat  ch_0a(ch_012.size(), CV_8UC1);	// 1ch
	Mat  ch_1a(ch_012.size(), CV_8UC1);	// 1ch
	Mat  ch_2a(ch_012.size(), CV_8UC1);	// 1ch

	Mat out_a[] = { ch_0a, ch_1a, ch_2a };	// 1ch, 1ch, 1ch

	// 원본 0 -> 출력 0, 원본 2 -> 출력 1, 원본 1 -> 출력 2
	int from_to_a[] = { 0, 0, 2, 1, 1, 2 };

	mixChannels(&ch_012, 1, out_a, 3, from_to_a, 3);	// 인자값들이 서로 쌍을 이뤄야함 Mat out_a[]이 3개라 3, int from_to_a[]가 3쌍이라 3

	cout << "[ch_0a] = " << endl << ch_0a << endl ;
	cout << "[ch_1a] = " << endl << ch_1a << endl ;
	cout << "[ch_2a] = " << endl << ch_2a << endl ;
	return 0;
}