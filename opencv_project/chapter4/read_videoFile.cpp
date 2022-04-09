#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void put_string(Mat &frame, string text, Point pt, int value)
{
	text += to_string(value);
	Point shade = pt + Point(2, 2);
	int font = FONT_HERSHEY_PLAIN;
	putText(frame, text, shade, font, 1.8, Scalar(0, 0, 0), 2);
	putText(frame, text, pt, font, 1.8, Scalar(120, 200, 90), 2);
}

int main()
{
	VideoCapture capture;
	capture.open("images/video_file.avi");
	CV_Assert(capture.isOpened());

	double frame_rate = capture.get(CV_CAP_PROP_FPS);
	int delay = 1000 / frame_rate;
	int frame_cnt = 0;
	Mat frame;

	while (capture.read(frame))
	{
		if (waitKey(delay) >= 0)
			break;

		if (frame_cnt < 100) //원본재생
			;
		else if (frame_cnt < 200) // RED를 100만큼 뺀 영상 출력
			frame -= Scalar(0, 0, 100);
			rectangle(frame, Rect(5,5,100,100), Scalar(255,225,255),2);
		else if (frame_cnt < 300) //BULE를 100만큼 더한 영상을 출력
			frame += Scalar(100, 0, 0);
		else if (frame_cnt < 400) //영상을 50% 밝게
			frame = frame * 1.5;
		else if (frame_cnt < 500) //영상을 50% 어둡게
			frame = frame * 0.5;

		put_string(frame, "frame_cnt ", Point(20, 50), frame_cnt++);
		imshow("동영상 파일읽기", frame);
	}
	return 0;
}