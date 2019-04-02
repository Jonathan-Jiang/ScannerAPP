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

	vector<shared_ptr<BaseModel>> upper_ModelsVt;
	vector<shared_ptr<BaseModel>> lower_ModelsVt;
	vector<shared_ptr<BaseModel>> all_ModelsVt;

	pCTeethModel upperTeethModel;
	pCTeethModel lowerTeethModel;
	pCTeethModel allTeethModel;

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

	int upperJawIndex = 1;

	int lowerJawIndex = 1;

	int allJawIndex = 1;
	
	int chooseJawIndex = 0;//1������ֻɨ��򢣻2����ֻɨ��򢣻3����ɨȫ򢣻

	bool compensationFlag = false;

	float ax = 0, ay = 0;

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
	//Mat2QImage
	QImage Mat2QImage(const cv::Mat &InputMat);
	QString filePath;//�����ļ�·��
	QString patientNameQStr;//��������

	//ˮƽ�и�����
	int upperCutModelNum = 0;
	int lowerCutModelNum = 0;
	int allCutModelNum = 0;
	//ɾ�������и�����
	void deleteAllCutModel();
	//���Ӳ�ɨ����
	int addCompensationNum = 0;
	
signals:
	void startControlNormalScan(int chooseJawIndex);//��������ɨ���ź�signals
	void compensationSignal(int chooseJawIndex);//����ɨ���ź�
	void doScanSignal();
	void cutSurfaceSignal(bool bShow);

	void gpaMeshSignal(int chooseJawIndex);
	void saveCutModelSignal();//�����и���ģ��

	void updateMeshModelSingel(int refreshIndex);//ˢ��ģ����ʾ�ź�
	void updateModelsVtSingle();
	void saveModeltoFileSignal();
private:
	Ui::ScanMainGUI ui;

	GLWidget *glWidget;
	//����ģ�Ͳ�����
	QToolButton *leftWatchButton;
	QToolButton *rightWatchButton;
	QToolButton *topWatchButton;
	QToolButton *bottomWatchButton;
	QToolButton *frontWatchButton;
	QToolButton *backWatchButton;
	QToolButton *enlargeButton;
	QToolButton *shrinkButton;
	//�ײ�ģ�Ͳ�����
	bool bSelected = false;
	QToolButton *selectRegionButton;
	QToolButton *deleteModelButton;

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
	//չʾģ��
	void updateMeshModel(int refreshIndex);
	void updateModelsVtSlot();
	void updateCamera();

	void doScanDialogSlot(QJsonObject scanObj);

	//ɨ��
	void judgeForwardStep();
	void JawScan();
	//��ɨ
	void compensationScan();
	//������ɨ
	void discardCompensationSlot();
	void judgeBackStep();

	//����ģ��
	void topModelWatchSlot();
	void bottomModelWatchSlot();
	void leftModelWatchSlot();
	void rightModelWatchSlot();
	void frontModelWatchSlot();
	void backModelWatchSlot();
	void enlargeModelSlot();
	void shrinkModelSlot();

	void selectRegionSlot();
	void deleteSelectedRegionSlot();

	//cutSurface
	void showCutSurfaceSlot(bool bShow);//�и�ģ��

	void moveCutSurfaceSpinSlot();//�����и�ˮƽ��
	void moveCutSurfaceSliderSlot();
	void cutModelSlot();//�и�ģ��
	void setRotationWaverSlot();//��ʾ��ת�Ͱڶ��Ƕ�
	void saveCutModelSlot();//�����и��ģ��
	void discardCutModelSlot();//�����и�ģ��

	//��������ģ�͵��ļ�
	void saveModeltoFileSlot();
	public slots:
	void fontviewBtnClicked();
	void pushBtnClicked();
	void rightViewBtnClicked();
	void leftViewBtnClicked();
	void backViewBtnClicked();
	void jawViewBtnClicked();
	void narrowViewBtnClicked();
	void enlargeViewBtnClicked();
	void modelMoveStateSetBtnClicked();
	void delSelectedBtnClicked();
	void confirmSelectedBtnClicked();
	void bgGroundmoveDownBtnClicked();
	void bgGroundmoveUpBtnClicked();
	void bgGroundShowBtnClicked();
	void cutModelUnderBgBtnClicked();
	void changeBgColorBtnClicked();
};

#endif