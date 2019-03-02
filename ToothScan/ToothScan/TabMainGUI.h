#pragma once

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
class TabMainGUI : public QWidget
{
	Q_OBJECT

public:
	TabMainGUI(QWidget *parent = Q_NULLPTR);
	~TabMainGUI();

	void initVariable();
	void constructIHM();
	void setConnections();

	void judgeToothList(int id, QList<QPushButton*> &toothButtonList);
	void setSplitToothFalse();
	void judgeFinalSplitModelFlag(QList<int> &chooseToothNum);

private:
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
	QPushButton *saveButton;
	QPushButton *watchButton;
	QPushButton *scanButton;
	//PatientInformation *patientInformation;
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
	//bool splitModelFlag = false;

	int chooseID = -1;
	QList<QPushButton *> toothList;
	QList<bool> toothFlagList;
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

	void Tooth11Press();
	void Tooth12Press();
	void Tooth13Press();
	void Tooth14Press();
	void Tooth15Press();
	void Tooth16Press();
	void Tooth17Press();
	void Tooth18Press();

	void Tooth21Press();
	void Tooth22Press();
	void Tooth23Press();
	void Tooth24Press();
	void Tooth25Press();
	void Tooth26Press();
	void Tooth27Press();
	void Tooth28Press();

	void Tooth31Press();
	void Tooth32Press();
	void Tooth33Press();
	void Tooth34Press();
	void Tooth35Press();
	void Tooth36Press();
	void Tooth37Press();
	void Tooth38Press();

	void Tooth41Press();
	void Tooth42Press();
	void Tooth43Press();
	void Tooth44Press();
	void Tooth45Press();
	void Tooth46Press();
	void Tooth47Press();
	void Tooth48Press();

	void clearAllButtonPress();
};
