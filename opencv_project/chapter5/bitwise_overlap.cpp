#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("images/bit_test.jpg", IMREAD_COLOR);
	Mat logo = imread("images/logo.jpg", IMREAD_COLOR);
	CV_Assert(image.data && logo.data);			// �� ���� �� �ϳ��� ���������� �ҷ����� ���ϸ� ����ó��.
	Mat logo_th, masks[5], background, foreground, dst;		// �ΰ� ������Ȧ���ؼ� ����ȭ ó��, ����ũ ���� 5�� ��Ƴ��� ���, ����, ����� ���, ��� ���
	
	threshold(logo, logo_th, 70, 255, THRESH_BINARY); // �ΰ� ���� ����ȭ, �Ӱ谪 70(�����δ� 0) �ִ밪 255
	split(logo_th, masks);						// �ΰ��� ä�� �и�

	// imshow("logo_th ch0", masks[0]);
	// imshow("logo_th ch1", masks[1]);
	// imshow("logo_th ch2", masks[2]);

	bitwise_or(masks[0], masks[1], masks[3]);	// ������� ����ũ
	imshow("logo_th ch0|ch1", masks[3]);

	bitwise_or(masks[2], masks[3], masks[3]);
	// imshow("logo_th ch0|ch3", masks[4]);

	bitwise_not(masks[3], masks[4]);			// ������ ����ũ
	// imshow("logo_th !ch4", masks[5]);

	Point center1 = image.size()/ 2;			// ���� �߽���ǥ
	Point center2 = logo.size() / 2;;			// �ΰ� �߽���ǥ
	Point start = center1 - center2;
	Rect roi(start, logo.size());				// �ΰ� ��ġ�� ���ɿ���

	//��Ʈ���� ����ŷ�� �̿��� ���� ������ ����
	bitwise_and(logo, logo, foreground, masks[3]);
	// imshow("original logo", logo);
	// imshow("foreground of roi", foreground);

	bitwise_and(image(roi), image(roi), background, masks[4]);
	// imshow("image", image);
	// imshow("image of roi", image(roi));
	// imshow("background of roi", background);

	add(background, foreground, dst);			// �ΰ� ����� ��� �ռ�
	imshow("background", background);
	imshow("foreground", foreground);
	imshow("dst", dst);

	dst.copyTo(image(roi));						// �ΰ� �ռ� ������ ���ɿ����� ����
	imshow("image", image);
	
	//imshow("background", background);
	//imshow("foreground", foreground);
	//imshow("dst", dst);
	//imshow("image", image);
	waitKey();
	return 0;
}