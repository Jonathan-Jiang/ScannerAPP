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

class TabMainGUI : public QWidget
{
	Q_OBJECT

public:
	TabMainGUI(QWidget *parent = Q_NULLPTR);
	~TabMainGUI();

	void initVariable();
	void constructIHM();
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
	QPushButton *upperJawButton;
	QPushButton *lowerJawButton;
	//��ģ

	//ӡģ
	QPushButton *MoulageButton;

	//orderInfor����������Ϣ
	QString orderDate;
	QString orderNumber;
	QString orderPatientName;
	QString orderDoctorName;
	QString orderAddition;

	//About����ҳ��ؼ�
	QLabel *aboutTextLabel;
	QLabel *aboutImageLabel;

public slots:
	//����������Ϣ��
void PatientInformationSave();
};
