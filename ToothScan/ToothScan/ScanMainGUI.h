#ifndef SCANMAINGUI_H
#define SCANMAINGUI_H

#include <QWidget>
#include "ui_ScanMainGUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QToolButton>
#include <QDockWidget>
#include <QSpinBox>
#include <QSlider>
#include <QTextEdit>
#include "glwidget.h"
#include "ControlThread.h"
#include "ComputeThread.h"
#include "TabMainGUI.h"
#include "ScanTipWidget.h"

class ScanMainGUI : public QWidget
{
	Q_OBJECT

public:
	ScanMainGUI(QWidget *parent = Q_NULLPTR);
	~ScanMainGUI();

	int globalTipIndex = 0;
	/*globalTipStep����
	globalTipIndex = 1��"���"
	globalTipIndex = 2��"���"
	globalTipIndex = 3��"ȫ�"*/

	int forwardIndex = 0;
	/*forwardSteButton����
	forwardIndex = 1��"ɨ��"
	forwardIndex = 2��"��һ��"
	forwardIndex = 3��"���"*/

	int allJawIndex = 1;
	
	int chooseJawIndex = 0;//1������ֻɨ��򢣻2����ֻɨ��򢣻3����ɨȫ򢣻

	bool compensationFlag = false;

	TabMainGUI *tabMainPage;
	ControlThread *ControlScanThread;
	ComputeThread *ControlComputeThread;
	QThread *controlScanQThread, *controlComputeQThread;

	ScanTipWidget *scanTipWidget;
	
	void initVariable();
	void constructIHM();
	void setConnections();
	//ɨ��ģ��
	void CalculatePointCloud();

signals:
	void startControlNormalScan(int chooseJawIndex);//��������ɨ���ź�signals
	void compensationSignal(int chooseJawIndex);//����ɨ���ź�
	void doScanSignal();
	

private:
	Ui::ScanMainGUI ui;

	GLWidget *glWidget;

	QToolButton *leftWatchButton;
	QToolButton *rightWatchButton;
	QToolButton *topWatchButton;
	QToolButton *bottomWatchButton;
	QToolButton *frontWatchButton;
	QToolButton *backWatchButton;
	//�����ʾ����
	QDockWidget *cameraWindow;
	QPushButton *autoTunePushButton;
	QLabel *cameraImageLabel;
	QSpinBox *spinCameraBox;
	QSlider *sliderCamera;

private slots:
	
	//�궨
	void ToothCalibrateSlot();
	void GlobalCalibrateSlot();

	void updateMeshModel(int refreshIndex, int scanIndex);
	void doScanDialogSlot(QJsonObject scanObj);

	//ɨ��
	void judgeForwardStep();
	void JawScan();
	void compensationScan();
};

#endif