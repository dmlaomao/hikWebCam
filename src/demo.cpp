#include <opencv2/opencv.hpp>
#include <iostream>  
#include <hikWebCam.hpp>

using namespace cv;
using namespace std;

#define POSTER 1
#define SHELF 1
#define OFFICE 1
#define CORRIDER 1

int main() {
	Mat frame0, frame1, frame2, frame3;
	Mat img0, img1, img2, img3;

#if POSTER
	hawk::HikWebCam webCam0("your_ip_192.168.1.1", "your_usr_admin", "your_pwd_admin", 8000);		//poster
	webCam0.init();
#endif
#if SHELF
	hawk::HikWebCam webCam1("your_ip_192.168.1.2", "your_usr_admin", "your_pwd_admin", 8000);		//shelf
	webCam1.init();
#endif
#if OFFICE
	hawk::HikWebCam webCam2("your_ip_192.168.1.3", "your_usr_admin", "your_pwd_admin", 8000);		//office
	webCam2.init();
#endif
#if CORRIDER
	hawk::HikWebCam webCam3("your_ip_192.168.1.4", "your_usr_admin", "your_pwd_admin", 8000);		//corrider
	webCam3.init();
#endif 
	while (true) {
#if POSTER
		webCam0.getFrame(frame0, 0);
		if (frame0.cols > 0) {
			resize(frame0, img0, Size(), 0.5, 0.5);
			imshow("posters", img0);
		}
#endif
#if SHELF
		webCam1.getFrame(frame1, 1);
		if (frame1.cols > 0) {
			resize(frame1, img1, Size(), 0.5, 0.5);
			imshow("shelf", img1);
		}
#endif
#if OFFICE
		webCam1.getFrame(frame2, 2);
		if (frame2.cols > 0) {
			resize(frame2, img2, Size(), 0.5, 0.5);
			imshow("office", img2);
		}
#endif
#if CORRIDER
		webCam1.getFrame(frame3, 3);
		if (frame3.cols > 0) {
			resize(frame3, img3, Size(), 0.5, 0.5);
			imshow("corrider", img3);
		}
#endif
		waitKey(20);
	}
	cout << "Perfect!" << endl;
	return 1;
}