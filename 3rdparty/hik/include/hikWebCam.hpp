#include <opencv2/opencv.hpp>
#include <iostream>
#include "Windows.h"
#include "HCNetSDK.h"
#include "plaympeg4.h"

namespace hawk {
	class HikWebCam
	{
	public:
		HikWebCam(std::string ip, std::string userName, std::string password, int ipPort);
		~HikWebCam();
		void init();
		static void getFrame(cv::Mat&, int idx);
	private:
		LONG lUserID;					//each cam has one userId
		LONG lRealPlayHandle;			//each cam has a handle
		static HWND hWnd;				//all set tu NULL

		std::string ip_;
		std::string userName_;
		std::string password_;
		int ipPort_;
		
		static std::vector<std::queue<cv::Mat>> framePool;
		static std::vector<LONG> portPool;
		static std::map<LONG, LONG> useridPortMap;

		static void yv12toYUV(char *outYuv, const char *inYv12, int width, int height, int widthStep);
		//callbacks
		///ʵʱ���ص�
		static void CALLBACK fRealDataCallBack(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, void *pUser);
		//����ص� ��ƵΪYUV����(YV12)����ƵΪPCM����
		static void CALLBACK DecCBFun(long nPort, char * pBuf, long nSize, FRAME_INFO * pFrameInfo, long nReserved1, long nReserved2);
		//�쳣�ص�
		static void CALLBACK g_ExceptionCallBack(DWORD dwType, LONG lUserID, LONG lHandle, void *pUser);
	};
}