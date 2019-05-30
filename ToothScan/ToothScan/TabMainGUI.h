#ifndef TABMAINGUI_H
#define TABMAINGUI_H

#include <QWidget>
#include "ui_TabMainGUI.h"
#include <QTabWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QDateTimeEdit>
#include <QDateTime>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <QButtonGroup>
#include <QCheckBox>
#include <QRadioButton>
#include <QGroupBox>
#include <QDebug>
#include <qdir.h>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QMessageBox>
#include <iostream>
#include <QFileDialog>
#include <QDockWidget>
#include "TaskManager.h"
#include "ImageBtn.h"
#include "HeaderBtn.h"

#define TOOTHNUM 32

class TabMainGUI : public QWidget
{
	Q_OBJECT

public:
	TabMainGUI(QWidget *parent = Q_NULLPTR);
	~TabMainGUI();

	bool m_usbDeviceState = false;//�жϿ����Ƿ�������USB,��ScanMainGUI�����ر�����ֵ

	void initVariable();
	void constructIHM();
	void setConnections();

	QList<QPushButton*> *judgeToothList(int id);
	void setSplitToothFalse();

	//�ж��ļ����Ƿ���ڲ������ļ���
	bool isDirExist(QString fullPath);
	void saveSplitModel(int id, cv::FileStorage fWrite);

	void addToothList(int id, int toothButtonIndex);
	void removeToothList(int id, int toothButtonIndex);

	void judgeSplitModelFlag();
	 
	//�ж��Ƿ����㱣�涩����Ϣ����
	bool judgePatientSaveFlag();

	//ת��Ϊ�����ַ���
	QByteArray ToChineseStr(const QString &chineseString);

	QString lastDateTimeStr;//���¶���ʱ���ַ���
	QString fileQStr;//�����ļ�·��
	QString filePath = "./ScanData/";//�ļ�Ŀ¼·��

	//��ȡ������Ϣ�ļ�
	void readFileStorage(QString fPath);

public:
	Ui::TabMainGUI ui;
	
	//QGridLayout *totalGLayOut;
	//QTabWidget *totalTabWidget;

	//QWidget *orderInforWidget;
	//QWidget *settingWidget;
	//QWidget *calibrateWidget;
	//QWidget *aboutWidget;

	//QVBoxLayout *totalOrderVLayout;
	//QGridLayout *totalAboutGLayout;
	//orderInfor��������ؼ�
	//topbutton
	//QPushButton *newButton;
	//QPushButton *exportButton;
	//QPushButton *saveButton;
	//QPushButton *watchButton;
	//QPushButton *saveScanButton;
	//QPushButton *saveButton;
	//CTeethImgBtn * m_closeBtn;
	
	//QDateTimeEdit *dateLineEdit;
	//QLineEdit *orderLineEdit;
	//QLineEdit *patientLineEdit;
	//QLineEdit *doctorLineEdit;
	//QLineEdit *operatorLineEdit;
	//QTextEdit *additionTextEdit;
	//QLabel *additionLabel;
	//δ��ģ
	bool unMoulageFlag = false;
	//QPushButton *upperJawButton;
	bool upperJawButtonFlag = false;
	//QPushButton *lowerJawButton;
	bool lowerJawButtonFlag = false;
	
	//��ģ
	//splitleft
	bool splitModelFlag = false;
	QList<bool> toothFlagList;
	int chooseID = -1;
	QList<CTeethImgBtn *> toothList;
	
	QList<int> toothID;
	//QPushButton *clearAllButton;
	//splitright
	QButtonGroup *toothRadioButtonGroup;//��ģ�зŹ���ѡ���ButtonGroup
	
	CImageBtn *totalCrownButton;//ȫ��
	CImageBtn *toothCrownButton;//����
	CImageBtn *lossToothButton;//ȱʧ��
	CImageBtn *inlayButton;//Ƕ��
	QCheckBox *facingButton;//����
	QCheckBox *waxTypeButton;//����
	QCheckBox *implantButton;//��ֲ��
	CImageBtn *jawToothButton;//�����

	QList<QPushButton*> totalCrownList;
	QList<QPushButton*> toothCrownList;
	QList<QPushButton*> lossToothList;
	QList<QPushButton*> inlayList;
	QList<QPushButton*> facingList;
	QList<QPushButton*> waxTypeList;
	QList<QPushButton*> implantList;
	QList<QPushButton*> jawToothList;

	//ӡģ
	bool doMoulageFlag = false;
	//QPushButton *MoulageButton1;
	bool MoulageFlag1 = false;
	//QPushButton *MoulageButton2;
	bool MoulageFlag2 = false;
	//QPushButton *MoulageButton3;
	bool MoulageFlag3 = false;
	//orderInfor����������Ϣ
	QString orderDate;
	QString orderNumber;
	QString orderPatientName;
	QString orderDoctorName;
	QString orderAddition;
	QString orderOperatorName;
	//QString upperjaw;
	//About����ҳ��ؼ�
	//QLabel *aboutTextLabel;
	//QLabel *aboutImageLabel;

	//Calibrate�궨ҳ��
	//QPushButton *calibratePushButton;
	//QPushButton *globalCaliPushButton;
	//QLabel *leftCameraLable;
	//QLabel *rightCameraLable;
	
	QTabWidget *rightTabWidget;

	//������ҳ��
	//QButtonGroup *settingButtonGroup;
	//QCheckBox *textureCheckBox;
	//QCheckBox *ACheckBox;
	//QCheckBox *BCheckBox;
	//QCheckBox *saveSpliteModelCheckBox;
	//QLabel *scanDataPathLabel;
	//QLineEdit *scanDataPathEdit;
	//QPushButton *choosePathButton;
	pCScanTask m_pTeethScanTaskArray[32];
	eScanType m_eScanType;

	/*��������ҳ��*/
	//����
	QButtonGroup *headerButtonGroup;
	CHeaderCheckBtn * m_orderMgrBtn;
	CHeaderCheckBtn * m_settingMgrBtn;
	CHeaderCheckBtn * m_calibrationMgrBtn;
	CHeaderCheckBtn * m_aboutMgrBtn;
	//�Ҳ�
	QButtonGroup *rightButtonGroup;


signals:
	void scanDataSignal(QJsonObject scanObj);
	void showOrderInfoSignal(COrderInfo orderInfo);
	void scanSignal();
	//�������
	void exportUpperJawSignal();
	//�������
	void exportLowerJawSignal();
	//����ӡģ1
	void exportFirstMoulageSignal();
	//����ӡģ2
	void exportSecondMoulageSignal();
	//����ӡģ3
	void exportThirdMoulageSignal();

public slots:
	/*��������ҳ��*/
	void showOrderInforGroupBox();//�򿪶���������ҳ��
	void newButtonClickedSlot();//�½��ļ�
	void openFileDialogSlot();//�����ļ�
	//����������Ϣ��
	void PatientInformationSave();
	void OrderPreview();
	void closeBtnClicked();
    //δ��ģ
	void showUnModelGroupBox();//ѡ��δ��ģ����
	void UpperJawPress();
	void LowerJawPress();
	//ӡģ
	void showMoulageGroupBox();//ѡ��ӡģ����

	void MoulagePress1();
	void MoulagePress2();
	void MoulagePress3();
	//��ģ
	void showSpliteModelGroupBox();//ѡ���ģ����

	void ToothGroupClicked(int id);

	void ToothButtonListPress();
	
	void clearAllButtonPress();

	void ScanDataPackagePress();

	//void settingButtonClicked(QAbstractButton *button);

	void saveSpliteModelCheckBoxClicked(int);
	
	/*�궨��ҳ��*/
	void showCalibrationGroupBox();
	
	/*������ҳ��*/
	void showAboutGroupBox();

	/*������ҳ��*/
	void showSettingGroupBox();//��������ҳ��
								 
	void openDirectoryDialogSlot(); //��·�����ļ�
};
#endif