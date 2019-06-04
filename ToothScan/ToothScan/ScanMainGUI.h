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
//#include "ScanTipWidget.h"

class ScanMainGUI : public QWidget, public QAbstractNativeEventFilter,public IGlWidget
{
	Q_OBJECT

public:
	ScanMainGUI(QWidget *parent = Q_NULLPTR);
	~ScanMainGUI();

	QTimer *timer;

	int globalSpinCutValue = 0;

	bool	bPnP_Arrival = false;
	bool	bPnP_Removal = false;
	bool	bPnP_DevNodeChange = false;
	bool    m_usbDeviceState = false;//�жϿ����Ƿ�������USB

	virtual bool nativeEventFilter(const QByteArray &eventType, void *message, long *) Q_DECL_OVERRIDE;

	void initUSBDevice();
	void installNativeEventFilter();

	vector<shared_ptr<BaseModel>> upper_ModelsVt;
	vector<shared_ptr<BaseModel>> lower_ModelsVt;
	vector<shared_ptr<BaseModel>> all_ModelsVt;

	pCTeethModel upperTeethModel;
	pCTeethModel lowerTeethModel;
	pCTeethModel allTeethModel;

	bool m_bShowOrderInfo;
	std::string m_strOrderInfoPath;

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

	//int upperJawIndex = 1;

	//int lowerJawIndex = 1;

	//int allJawIndex = 1;

	//int chooseJawIndex = 0;//1������ֻɨ��򢣻2����ֻɨ��򢣻3����ɨȫ򢣻

	bool compensationFlag = false;

	float ax = 0, ay = 0;

	TabMainGUI *tabMainPage;
	ControlThread *ControlScanThread;
	ComputeThread *ControlComputeThread;
	QThread *controlScanQThread, *controlComputeQThread;

	//ScanTipWidget *scanTipWidget;

	void initVariable();
	void constructIHM();
	void setConnections();
	//ɨ��ģ��
	//void CalculatePointCloud();
	void splitModelCalculatePointCloud(pCScanTask pScanTask);
	//Mat2QImage
	QImage Mat2QImage(const cv::Mat &InputMat);
	QString filePath;//�����ļ�·��
	QString patientNameQStr;//��������

	//ˮƽ�и�����
	int upperCutModelNum = 0;
	int lowerCutModelNum = 0;
	int allCutModelNum = 0;
	//ɾ�������и�����
	//void deleteAllCutModel();

	pCTeethModel m_pupperTeethModel;
	pCTeethModel m_plowerTeethModel;
	pCTeethModel m_pallTeethModel;
	pCTeethModel m_pLowerDentalImplantModel;
	pCTeethModel m_pUpperDentalImplantModel;
	pCTeethModel m_pUpperJawGingvaModel;
	pCTeethModel m_pLowJawGingvaModel;

	void resetValue();
	void setDentalImplantNextBtnEnable(bool bEnable) {
		ui.DentalImplantNextBtn->setEnabled(true);
	}
signals:
	//void startControlNormalScan(int chooseJawIndex);//��������ɨ���ź�signals
	//void startAllJawNormalScan();
	void startControlCalibrationSignal();//��ʼ�궨�ź�
	//void compensationSignal(int chooseJawIndex);//����ɨ���ź�
	void doScanSignal();
	void cutSurfaceSignal(bool bShow);

	//void gpaMeshSignal(int chooseJawIndex);
	void farRegistrationSignal();

	//void updateMeshModelSingel(int refreshIndex);//ˢ��ģ����ʾ�ź�
	void updateModelsVtSingle();
	void saveModeltoFileSignal();

	void startNormalScan();//��������ɨ���ź�signals
	void compensationScanSignal();//����ɨ���ź�
	void gpaTaskMeshSignal();
	void taskSititchingSignal();
	void taskTeethSititSignal();
	void startAllJawScan();//��������ɨ���ź�signals
	void showOrderInfoSignal(COrderInfo);
	
	void usbDeviceSignal();//�����ж�usbDevice�Ƿ�ɹ��ź�
private:
	Ui::ScanMainGUI ui;

	GLWidget *glWidget;
	//����ģ�Ͳ�����
	//QToolButton *leftWatchButton;
	//QToolButton *rightWatchButton;
	//QToolButton *topWatchButton;
	//QToolButton *bottomWatchButton;
	//QToolButton *frontWatchButton;
	//QToolButton *backWatchButton;
	//QToolButton *enlargeButton;
	//QToolButton *shrinkButton;
	//CTeethImgBtn * m_closeBtn;
	//�ײ�ģ�Ͳ�����
	bool bSelected = false;
	//QToolButton *selectRegionButton;
	//QToolButton *deleteModelButton;

	//�����ʾ����
	//QDockWidget *cameraWindow;
	//QPushButton *autoTunePushButton;
	//QLabel *cameraImageLabel;
	//QSpinBox *spinCameraBox;
	//QSlider *sliderCamera;
	bool m_bsplitModelFlag;	//��ģ
	private slots:
	void closeBtnClicked();
	//�궨
	void ToothCalibrateSlot();
	//void GlobalCalibrateSlot();
	void calibImageCameraSlot(int endFlag);//���±궨�����Ƭ

	//չʾģ��
	//void updateMeshModel(int refreshIndex);
	//void updateModelsVtSlot();
	void updateCamera();
	void updateRegMeshSlot();

	//��ɺ���ʾ������ģ�Ͱ�ť
	//void ShowHideUpperModel();//��ʾ�����������
	//void ShowHideLowerModel();//��ʾ�����������

	void doScanDialogSlot(QJsonObject scanObj);

	
	//��ɨ
	//void compensationScan();
	//������ɨ
	//void discardCompensationSlot();

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
	//void cutModelSlot();//�и�ģ��
	void setRotationWaverSlot();//��ʾ��ת�Ͱڶ��Ƕ�
	//void saveCutModelSlot();//�����и��ģ��
	//void discardCutModelSlot();//�����и�ģ��

	//��������ģ�͵��ļ�
	//void saveModeltoFileSlot();

	void scanJawScanBtnClick();
	void ScanJawBackStepBtnClick();
	void ShowLastScanTask(bool bCurrentTaskSame = false);
	
	void compensationBtnClick();
	void discardBtnClick();		//������ɨ
	void compensationScanPanelNextBtnClick();
	void compensationScanPanelBackBtnClick();
	void cutModelBtnClick();
	void unDoCutBtnClick();
	void saveCutHeightCutBtnClick();
	void cutPaneNextStepBtnClick();
	void cutPanelBackBtnClick();
	void CutJawFinishPanelNextStepBtnClick();
	void stitchingPanelBtnClick();
	void stitchingBackBtnClick();
	void stitchingUpperJawBtnClick();
	void stitchingUpperJawDenBtnClick();
	void stitchingUpperJawGingivaBtnClick();
	void stitchingLowerJawBtnClick();
	void stitchingLowerJawDenBtnClick();
	void stitchingLowerJawGingivaBtnClick();
	void stitchingFNextBtnClick();
	void OralSubstitutePanelNextBtnClick();
	void oralSubstitutePanelBackBtnClick();
	void teethStitchingPanelBackBtnClick();
	void cutJawFinishPanelBackBtnClick();
	void stitchingFinishPanelBackBtnClick();	
	void teethStitchingPanelNextBtnClick();
	void saveModelFile(pCScanTask pTask);
	void saveModelFile(std::string strPath, pCTeethModel pTask);
	void saveDenModelFile(pCScanTask pTask);//��ֲ��
	bool isModelFileExit(pCScanTask &pTask);
	void loadModelFile(pCScanTask &pTask);
	void hideAllPanel();
	void showScanJawGroup(bool bBack = false);
	void showcompensationScanPanel(bool bBack = false);
	void showCutJawPanel(bool bBack = false);
	void showOralSubstitutePanel(bool bBack = false);
	void showStitchingFinishPanel(bool bBack = false);
	void showSubstitutePanel(bool bBack = false);
	void showDentalImplantPanel(bool bBack = false);
	void movecutHeightSpinBoxSlot();//�����и�ˮƽ��
	void movecutHeightSliderSlot();
	void ToothButtonListPress();
	public slots:
	void updateTaskModel();
	void meshFinishSlot();
	void StitchFinishSlot();
	void taskTeethSititFinishSlot();
	void recallWindow();

	void showOrderInfo(COrderInfo orderInfo);
	void upperJawBtnBtnClick();
	void upperJawDenBtnClick();
	void upperJawGinBtnClick();
	void lowJawBtnClick();
	void lowJawDenBtnClick();
	void lowJawGinBtnClick();
	void DentalImplantNextBtnClick();
	void DentalImplantPanelBackBtnClick();
	void DentalImplantFinishNextBtnClick();
	void DentalImplantFinishBackBtnClick();
	

	void progressBarSetSlot(int min, int max, bool bVisible);
	
	void usbDeviceSlot();//�����ʱ����ʾ�Ƿ�USB���ӳɹ�
						 //ɨ��
	void JawScanFinish();
};

#endif