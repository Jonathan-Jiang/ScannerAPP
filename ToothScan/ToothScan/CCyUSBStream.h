#ifndef CCYUSBSTREAM_H
#define CCYUSBSTREAM_H

#include <windows.h>
#include <stdio.h>
#include "CyAPI.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <opencv2\opencv.hpp>
#include <string>

namespace Communication
{
	#define MAX_QUEUE_SZ 64
	#define ImageRow 1024
	#define ImageCol 1280
	#define TN 10000
	#define SCALE 256
	#define QueueSize 8
	#define TimeOut 100
	#define ImageQueueSize 12

	using std::cout;
	using std::endl;
	using std::vector;
	using cv::Mat;
	using std::string;

	static uchar OpenDLP[4] = { 0XAA, 0XBB, 0X04, 0X01};
	static uchar CloseDLP[4] = { 0XAA, 0XBB, 0X04, 0X04};
	static uchar RealMode[5] = { 0XAA, 0XBB, 0X05, 0X05, 0X00};
	static uchar TrigerMode[5] = { 0XAA, 0XBB, 0X05, 0X05, 0X01};
	static uchar OpenLight[5] = { 0XAA, 0XBB, 0X05, 0X06, 0X01 };

	static uchar SMReset[4] = { 0XAA, 0XBB, 0X04, 0X03};
	static uchar SMRotOneDeg[9] = { 0XAA, 0XBB, 0X09, 0X02, 0X00, 0X00, 0X00, 0X00, 0X00 };

	class CCyUSBStream
	{
		public:
			 CCyUSBStream();
			 ~CCyUSBStream();
		
			 int InitCyUSBParameter();//��ʼ��USB
			 void OpenDLPFunction();//�򿪹��
			 void ClosedDLPFunction();//�رչ��
			 void ResetDLPFunction();//�����λ
			 void TestDLPFunction();//���

			//ʵʱ��ʾ
			 void RealModeFuction();//ʵʱ��ȡ����
			 bool initRealTimeParameter();//ʵʱ��ʼ��
			 bool realTimeImageStream(cv::Mat &v_img_L, cv::Mat &v_img_R);//��ȡ���������һ��ͼ��
			 void clearRealTimeStream();//����ʵʱ������

			 //triggerģʽȡһ���Ƕ�����
			 void TriggerModeFunction();//��Ϊtriggerģʽ��ȡ����
			 bool SMRotOneDegFunction(double v_ddeg_x, bool v_bpositiveOrien_x, double v_ddeg_y, bool v_bpositiveOrien_y, bool v_bcali, vector<cv::Mat> &img_L_set, vector<cv::Mat> &img_R_set);
			//���Ƶ����ת
			//v_ddeg_x��������ת�Ƕȣ� v_bpositiveOrien_x�������Ƿ���ת��trueΪ��ת��falseΪ��ת����
			//v_ddeg_y��С�����ת�Ƕȣ� v_bpositiveOrien_y��С����Ƿ���ת��trueΪ��ת��falseΪ��ת���� 
			//v_bcali���Ƿ�Ϊ�궨����ת����trueΪ�궨��ת��falseΪɨ����ת����
			void AbortXferLoop();//�����ڴ�

		private:
			CCyUSBDevice *m_USBDevice;
			CCyUSBEndPoint *m_EndPtIn;
			CCyUSBEndPoint *m_EndPtOut;
			PUCHAR *m_buffers;
			CCyIsoPktInfo	**m_isoPktInfos;
			PUCHAR			*m_contexts;
			OVERLAPPED		m_inOvLap[MAX_QUEUE_SZ];
			
			long m_endptInLength;
			int m_validTotalBuffersSize;

			UCHAR *m_totalRealTimeBuffers;
			UCHAR *m_totalScanImageBuffers;
			UCHAR *m_totalCalibImageBuffers;

			bool m_startSave = false;
			//leftcamera
			vector<cv::Mat> m_img_L_set;
			
			int m_left_CAFlag = 0;
			bool m_left_start = false;
			bool m_left_start_row = false;
			bool m_left_end = false;
			Mat m_left_PerImage;
			Mat	m_left_image_raw;
			int m_left_im_u;
			int m_left_im_v;
			int m_left_bmpNum = 1;
			//rightcamera
			vector<cv::Mat> m_img_R_set;
			int m_right_CAFlag = 0;
			bool m_right_start = false;
			bool m_right_start_row = false;
			bool m_right_end = false;
			Mat m_right_PerImage;
			Mat	m_right_image_raw;
			int m_right_im_u;
			int m_right_im_v;
			int m_right_bmpNum = 1;

			void triggerScanImageStream();
			void triggerCalibImageStream();
			void AbortXferLoopIn(int pending);//�����ڴ�

			void TakeValidRealTimeInfo(long length);
			void TakeValidCalibInfo(long length);
			void TakeValidScanInfo(long length);
			void TakeInitFlag(byte *inBuf, long length, int &statPosition);
			void TakeValidImage(Mat &PerImage, vector<cv::Mat> &img_set);
			void TakeValidImage(Mat &PerImage, Mat &image_raw);
	};
}
#endif //CCYUSBSTREAM_H