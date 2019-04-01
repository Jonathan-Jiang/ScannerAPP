#ifndef ControlThread_H
#define ControlThread_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QSemaphore>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <iostream>

//#include "VTK_render.h"
#include "./include/3DScan.h"
//#include "3DScan_cuda.cuh"
#include "Spinnaker.h"
#include "SpinGenApi/SpinnakerGenApi.h"

#include <opencv2\opencv.hpp>

#define IMG_ROW    1024
#define IMG_COL   1280

#define EXPOSURETIME 16666

#define CALI_ROTATE_POS_CNT 12    //����궨���̵�λ���� 13
#define SCAN_ROTATE_POS_CNT 12    //����ɨ����̵�λ���� 11

#define CALI_ROTATE_POS_CNT2 11    //����궨���̵�λ���� 13
#define SCAN_ROTATE_POS_CNT2 10    //����ɨ����̵�λ���� 11    

extern int DataSize;
//extern int BufferSize;
extern unsigned char *totalNormalScanImageBuffer;
extern scan::RasterScan *rs;

extern cv::Mat rt_r;
extern std::vector<cv::Mat> scanner_rt;

extern float c_scan_x;
extern float c_scan_y;

extern QSemaphore freeSpace;
extern QSemaphore usedSpace;

static byte OpenDLP[5] = { 0xaa,0xbb,0x05,0x01,0x00 }; //����������DLP
static byte CloseDLP[5] = { 0xaa,0xbb,0x05,0x01,0x01 }; //�ر�DLP
static byte ProjectOneSet_CALI_MAX[11] = { 0xaa,0xbb,0x0b,0x01,0x02,  0xdf,0x02, 0xa2,0x03, 0x84,0x03 }; //�궨
static byte ProjectOneSet_CALI_MID[11] = { 0xaa,0xbb,0x0b,0x01,0x02,  0xf5,0x00, 0x36,0x01, 0x2c,0x01 }; //�궨
static byte ProjectOneSet_CALI_MIN[11] = { 0xaa,0xbb,0x0b,0x01,0x02,  0x83,0x00, 0x9e,0x00, 0x99,0x00 }; //�궨
static byte ProjectOneSet_SCAN_MAX[11] = { 0xaa,0xbb,0x0b,0x01,0x03,  0xdf,0x02, 0xa2,0x03, 0x84,0x03 }; //ɨ��
static byte ProjectOneSet_SCAN_MID[11] = { 0xaa,0xbb,0x0b,0x01,0x03,  0xf5,0x00, 0x36,0x01, 0x2c,0x01 }; //ɨ��
static byte ProjectOneSet_SCAN_MIN[11] = { 0xaa,0xbb,0x0b,0x01,0x03,  0x83,0x00, 0x9e,0x00, 0x99,0x00 }; //ɨ��


static byte WhiteDisplay[5] = { 0xaa,0xbb,0x05,0x01,0x05 }; //��ʾ����
//С���
static byte SMYEnable[5] = { 0xaa,0xbb,0x05,0x02,0x00 }; //ʹ��
static byte SMYDisable[5] = { 0xaa,0xbb,0x05,0x02,0x01 }; //ʧ��
static byte SMYRotOneDegPos[9] = { 0xaa,0xbb,0x09,0x02,0x02,0x00,0x00,0x00,0x00 }; //���������תһ���̶��Ƕ� deg = SMXRotOneDeg[5] * 256 + SMXRotOneDeg[6]
static byte SMYRotOneDegNeg[9] = { 0xaa,0xbb,0x09,0x02,0x02,0x01,0x00,0x00,0x00 }; //���������תһ���̶��Ƕ� deg = SMXRotOneDeg[5] * 256 + SMXRotOneDeg[6]
static byte SMYRotOneCirclePos[6] = { 0xaa,0xbb,0x06,0x02,0x03,0x00 }; //���������תһȦ
static byte SMYRotOneCircleNeg[6] = { 0xaa,0xbb,0x06,0x02,0x03,0x01 }; //���������תһȦ
//����
static byte SMXEnable[5] = { 0xaa,0xbb,0x05,0x03,0x00 }; //ʹ��
static byte SMXDisable[5] = { 0xaa,0xbb,0x05,0x03,0x01 }; //ʧ��
static byte SMXRotOneDegPos[9] = { 0xaa,0xbb,0x09,0x03,0x02,0x00,0x00,0x00,0x00 }; //���������תһ���̶��Ƕ� deg = SMXRotOneDeg[5] * 256 + SMXRotOneDeg[6]
static byte SMXRotOneDegNeg[9] = { 0xaa,0xbb,0x09,0x03,0x02,0x01,0x00,0x00,0x00 }; //���������תһ���̶��Ƕ� deg = SMXRotOneDeg[5] * 256 + SMXRotOneDeg[6]
static byte SMXRotOneCirclePos[6] = { 0xaa,0xbb,0x06,0x03,0x03,0x00 }; //���������תһȦ
static byte SMXRotOneCircleNeg[6] = { 0xaa,0xbb,0x06,0x03,0x03,0x01 }; //���������תһȦ

//static int SMX_CALI_ROTATE_DEGREE[CALI_ROTATE_POS_CNT] = { 45, -90, 45, 45, -90, 45, 45, -90, 45, 45, 135, 135, 45 };
//static int SMY_CALI_ROTATE_DEGREE[CALI_ROTATE_POS_CNT] = { 0,  0,  45,  0,  0,  45,  0,  0,  -60, 0,  0,  0,  -30 };
//static int SM_CALI_BRIGHTNESS[CALI_ROTATE_POS_CNT] = { 3,  3,  1,  1,  1,  2,  2,  2,  2,  2,  3,  2,  3 };//���ȵȼ���3������1ΪĬ��
//
//static int SMX_SCAN_ROTATE_DEGREE[SCAN_ROTATE_POS_CNT] = { 90, -45, -45, -45, -45, -45, -45, -135, 0,   0,  -45 };
//static int SMY_SCAN_ROTATE_DEGREE[SCAN_ROTATE_POS_CNT] = { 30, 0,   0,   0,   0,   0,   0,   0,    -30, 80, -80 };
//static int SM_SCAN_BRIGHTNESS[SCAN_ROTATE_POS_CNT] = { 2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2 };//���ȵȼ���3������1ΪĬ��

static int SMY_CALI_ROTATE_DEGREE[CALI_ROTATE_POS_CNT] = { 30, -60, -150, -45, -90, 0,-45, -45, 0, 45, 45, -45 };
static int SMX_CALI_ROTATE_DEGREE[CALI_ROTATE_POS_CNT] = { 0,  0,  0,  0,  0,  -30,  0,  0,  60,  0,  0, -30 };
static int SM_CALI_BRIGHTNESS[CALI_ROTATE_POS_CNT] = { 2,  2,  2,  2,  3,  3,  3,  2,  2,  2,  2,  2 };//���ȵȼ���3������1ΪĬ��

																									   //static int SMX_SCAN_ROTATE_DEGREE[SCAN_ROTATE_POS_CNT] = { 15, 30,   0,   0,   0,   0,   0,   0,    35, 0,  0, -80 };
static int SMY_SCAN_ROTATE_DEGREE[SCAN_ROTATE_POS_CNT] = { 0, 45, 45, 45, 45, 45, 45, 45, 115, -70,  -70,  70 };
static int SMX_SCAN_ROTATE_DEGREE[SCAN_ROTATE_POS_CNT] = { -45, 0,   0,   0,   0,   0,   0,   0,    -35, 0,  0, 80 };
static int SM_SCAN_BRIGHTNESS[SCAN_ROTATE_POS_CNT] = { 1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1, 1 };//���ȵȼ���3������1ΪĬ��

static int SMY_CALI_ROTATE_DEGREE2[CALI_ROTATE_POS_CNT2] = { 0,   0,  -30,  30,-25,   0,  25, -30,   0,  30,    0 };
static int SMX_CALI_ROTATE_DEGREE2[CALI_ROTATE_POS_CNT2] = { 0, 30,  30, 30, 20,  20,  20,  10,  10,  10,    0 };
static int SM_CALI_BRIGHTNESS2[CALI_ROTATE_POS_CNT2] = { 2,   2,    2,   2,  2,   2,   2,   2,   2,   2,    0 };//���ȵȼ���3������1ΪĬ��

																												//static int SMX_SCAN_ROTATE_DEGREE[SCAN_ROTATE_POS_CNT] = { 15, 30,   0,   0,   0,   0,   0,   0,    35, 0,  0, -80 };
static int SMY_SCAN_ROTATE_DEGREE2[SCAN_ROTATE_POS_CNT2] = { 0,/*-60,   0,  60, -50,   0,  50,*/   0, -45, -90, -135,  45,  90, 135,175, 0 };
static int SMX_SCAN_ROTATE_DEGREE2[SCAN_ROTATE_POS_CNT2] = { 0,/* 30,  30,  30,  20,  20,  20,*/ -40, -40, -40,  -40, -40, -40, -40,-40, 0 };

static int SM_SCAN_BRIGHTNESS2[SCAN_ROTATE_POS_CNT2] = { 2,/*  2,   2,   2,   2,   2,   2,*/   3,   3,   3,    3,   3,   3,   3,  3, 2 }; //���ȵȼ���3������1ΪĬ��
////static int SMX_SCAN_ROTATE_DEGREE[SCAN_ROTATE_POS_CNT] = { 15, 30,   0,   0,   0,   0,   0,   0,    35, 0,  0, -80 };
//static int SMX_SCAN_ROTATE_DEGREE2[SCAN_ROTATE_POS_CNT2] = { 0,-60,   0,  60, -50,   0,  50,   0, -40,  -80, -140,    40,   80,  140, 0 };
//static int SMY_SCAN_ROTATE_DEGREE2[SCAN_ROTATE_POS_CNT2] = { 0, 30,  30,  30,  20,  20,  20, -30, -30,  -30,  -30,  -30,  -30,  -30,  0 };
//static int SM_SCAN_BRIGHTNESS2[SCAN_ROTATE_POS_CNT2] = { 2,  2,   2,   2,   2,   2,   2,   3,   3,    3,    3,    3,   3,    3,  2 };//���ȵȼ���3������1ΪĬ��


using namespace std;
using namespace Spinnaker;
using namespace Spinnaker::GenApi;
using namespace Spinnaker::GenICam;

enum triggerType
{
	SOFTWARE,
	HARDWARE
};

//const triggerType chosenTrigger = SOFTWARE;
const triggerType chosenTrigger = HARDWARE;

class ControlThread : public QObject
{
	Q_OBJECT

public:
	ControlThread(QObject *parent=0);
	~ControlThread();

	int point_cloud_index;
	bool serial_port_open;
	vector<bool> point_cloud_right;
	QMutex* mutex;

	QSerialPort *serial;

	vector<vector<double>> points_cloud_globle;

	float l_scan_x;
	float l_scan_y;
	float l_scan_z;
	
	float c_scan_z;
	//float c_scan_x;
	//float c_scan_y;

	void setFlage(bool flag = true);  //���ñ�־λ����ʱ�ر����߳�

	bool  isStop;

public slots:
	void controlNormalScan();
	void controlCalibrationScan();
	void controlGlobalCaliScan();
	void compensationControlScan();

private:

	void InitParameters();
	void OpenOrCloseSerialPort();
	void WriteByte(byte* szWriteBuffer, int number);
	int ReadData(byte* RXBuff);
	
	/*****************************1��������ú���*******************************************/
	//1.1 �����������
	int ConfigureTrigger(INodeMap & nodeMap, CameraPtr pCam);
	//1.2 ��λ����
	int ResetTrigger(INodeMap & nodeMap, CameraPtr pCam);
	//1.3 ������ͼ���ȡ����
	int AcquireImages(CameraPtr pCam, INodeMap & nodeMap, INodeMap & nodeMapTLDevice, gcstring deviceSerialNumber, int index, ImagePtr &convertedImage);
	//1.4 �������ͼƬ���
	int ConfigureCustomImageSettings(INodeMap & nodeMap);
	//1.5 �ع�ʱ������
	int ConfigureExposure(INodeMap & nodeMap);

	void getfirstimage();

	///*****************************2�����ڳ�ʼ������*******************************************/
	//HANDLE hComm;
	//OVERLAPPED OverLapped;
	//COMSTAT Comstat;
	//DWORD dwCommEvents;
	////2.1 �򿪴���
	//bool OpenPort();
	////2.2 ���ô���
	//bool SetupDCB(int rate_arg);
	////2.3 ���ó�ʱʱ��
	//bool SetupTimeout(DWORD ReadInterval, DWORD ReadTotalMultiplier, DWORD ReadTotalConstant, DWORD WriteTotalMultiplier, DWORD WriteTotalConstant);
	////2.4 ���ڽ���
	//void ReceiveWaitChar();
	////2.5 ���ڽ��գ����ص�ǰ�������е������ֽ�������󲻳���128�ֽ�
	//void ReceiveChar(byte RXBuff[]);
	////2.6 ��ȡ��ǰ���ջ������е��ֽ���
	//int ReceiveBufferNum();
	////2.7 ���ڷ���
	//bool WriteStr(char* szWriteBuffer);
	//bool WriteByte(byte* szWriteBuffer, DWORD dwSend);
	////2.8 ���ڳ�ʼ��ȫ����
	//void serialPortInit();

	/*****************************3����λ����������*******************************************/
	//3.1���������תһ���Ƕ� (1:x 2:y) //����дһ�����������ȷ�����תָ�Ȼ���ں���������ʱ�ȴ���ת������Ȼ��return
	void cameraInitParameters();

	bool SMX_RotOneDeg(double deg);
	bool SMY_RotOneDeg(double deg);
	//3.2���ʹ��
	void SM_Enable();
	//3.3���ʧ��
	void SM_Disable();
	//3.4DLPͶӰһ��궨ͼƬ
	void DLP_ProjectOneSet_Cali(int caliCnt, vector<cv::Mat> &img_L_set, vector<cv::Mat> &img_R_set);
	//3.5DLPͶӰһ��ɨ��ͼƬ
	void DLP_ProjectOneSet_Scan(int scanCnt, vector<cv::Mat> &img_L_set, vector<cv::Mat> &img_R_set);

	void DLP_ProjectOneSet_Global(int scanCnt, vector<cv::Mat> &img_L_set, vector<cv::Mat> &img_R_set);
};

#endif // ControlThread_H