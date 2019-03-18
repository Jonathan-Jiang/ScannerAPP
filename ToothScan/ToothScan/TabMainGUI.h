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

#define TOOTHNUM 32

class TabMainGUI : public QWidget
{
	Q_OBJECT

public:
	TabMainGUI(QWidget *parent = Q_NULLPTR);
	~TabMainGUI();

	void initVariable();
	void constructIHM();
	void setConnections();

	QList<QPushButton*> judgeToothList(int id);
	void setSplitToothFalse();

	//�ж��ļ����Ƿ���ڲ������ļ���
	bool isDirExist(QString fullPath);
	void saveSplitModel(int id, cv::FileStorage fWrite);

	void addToothList(int id, int toothButtonIndex);
	void removeToothList(int id, int toothButtonIndex);

	void judgeSplitModelFlag();
	 
	//�ж��Ƿ����㱣�涩����Ϣ����
	bool judgePatientSaveFlag();

public:
	Ui::TabMainGUI ui;
	
	QGridLayout *totalGLayOut;
	QTabWidget *totalTabWidget;

	QWidget *orderInforWidget;
	QWidget *settingWidget;
	QWidget *calibrateWidget;
	QWidget *aboutWidget;

	QVBoxLayout *totalOrderVLayout;
	QGridLayout *totalAboutGLayout;
	//orderInfor��������ؼ�
	//topbutton
	QPushButton *newButton;
	QPushButton *exportButton;
	//QPushButton *saveButton;
	QPushButton *watchButton;
	QPushButton *saveScanButton;
	
	QDateTimeEdit *dateLineEdit;
	QLineEdit *orderLineEdit;
	QLineEdit *patientLineEdit;
	QLineEdit *doctorLineEdit;
	QTextEdit *additionTextEdit;
	QLabel *additionLabel;
	//δ��ģ
	bool unMoulageFlag = false;
	QPushButton *upperJawButton;
	bool upperJawButtonFlag = false;
	QPushButton *lowerJawButton;
	bool lowerJawButtonFlag = false;
	
	//��ģ
	//splitleft
	bool splitModelFlag = false;
	QList<bool> toothFlagList;
	int chooseID = -1;
	QList<QPushButton *> toothList;
	
	
	QList<int> toothID;
	QPushButton *clearAllButton;
	//splitright
	QButtonGroup *toothRadioButtonGroup;
	
	QRadioButton *totalCrownButton;//ȫ��
	QRadioButton *toothCrownButton;//����
	QRadioButton *lossToothButton;//ȱʧ��
	QRadioButton *inlayButton;//Ƕ��
	QRadioButton *facingButton;//����
	QRadioButton *waxTypeButton;//����
	QRadioButton *implantButton;//��ֲ��
	QRadioButton *jawToothButton;//�����

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
	QPushButton *MoulageButton1;
	bool MoulageFlag1 = false;
	QPushButton *MoulageButton2;
	bool MoulageFlag2 = false;
	QPushButton *MoulageButton3;
	bool MoulageFlag3 = false;
	//orderInfor����������Ϣ
	QString orderDate;
	QString orderNumber;
	QString orderPatientName;
	QString orderDoctorName;
	QString orderAddition;
	//QString upperjaw;
	//About����ҳ��ؼ�
	QLabel *aboutTextLabel;
	QLabel *aboutImageLabel;

	//Calibrate�궨ҳ��
	QPushButton *calibratePushButton;
	QPushButton *globalCaliPushButton;

signals:
	void scanDataSignal(QJsonObject scanObj);
	void scanSignal();

public slots:
	//����������Ϣ��
	void PatientInformationSave();
    //δ��ģ
	void UpperJawPress();
	void LowerJawPress();
	//ӡģ
	void MoulagePress1();
	void MoulagePress2();
	void MoulagePress3();
	//��ģ
	void ToothGroupClicked(int id);

	void ToothButtonListPress();
	
	void clearAllButtonPress();

	void ScanDataPackagePress();
};
#endif