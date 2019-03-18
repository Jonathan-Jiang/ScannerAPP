#ifndef SCANTIPWIDGET_H
#define SCANTIPWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include "ui_ScanTipWidget.h"

class ScanTipWidget : public QWidget
{
	Q_OBJECT

public:
	ScanTipWidget(QWidget *parent = Q_NULLPTR);
	~ScanTipWidget();
	
	//top
	QLabel *primaryTipLabel;
	QLabel *secondTipLabel;
	
	//middle
	//����
	QLabel *imageTipLabel;
	//��ɨ
	QPushButton *compensationButton;//���Ӳ�ɨ
	QPushButton *discardButton;//������ɨ
	QLabel *rotationLabel;//��ת�Ƕ�
	QLineEdit *rotationLineEdit;//��ת�Ƕ�
	QLabel *waverLabel;//�ڶ��Ƕ�
	QLineEdit *waverLineEdit;//�ڶ��Ƕ�
	QLabel *cutHeightLabel;//�и�߶�
	QLineEdit *cutHeightLineEdit;//�и�߶�
	QSpinBox *spinCutBox;//�и����
	QSlider *sliderCut;
	QPushButton *cutHeightButton;//�и�߶�Ӧ��
	QPushButton *discardCutHeightButton;//�����и�߶�Ӧ��
	QPushButton *saveCutHeightButton;//���浱ǰ�и�߶�

	QPushButton *upperShowButton;//���
	QPushButton *lowerShowButton;

	//bottom
	QPushButton *backStepButton;
	QPushButton *forwardStepButton;

	//alljaw
	void InitVariable();//������ʼ��

	void placeVariable1();//����
	void compenVariable2();//��ɨ
	void finishVariable3();//���
	void splitScanVariable4();//���

	void placeConstruct1();//����
	void compenConstruct2();//��ɨ
	void finishConstruct3();//���

	void allPlaceConstructIHM1();//����ȫ�
	
	void allCompenConstructIHM2();//��ɨȫ�

	void allPlaceConstructIHM3();//�������
	
	void allCompenConstructIHM4();//��ɨ���

	void allPlaceConstructIHM5();//�������

	void allCompenConstructIHM6();//��ɨ���

	void allFinishConstructIHM7();//���

	void upperPlaceConstructIHM1();

	void upperCompenConstructIHM2();

	void lowerPlaceConstructIHM1();

	void lowerCompenConstructIHM2();

	//split��ģ 
	//����
	QList<QLabel *> toothList;

	void splitScanConstruct1();

	void upperSplitScanConstructIHM5();
	void upperSplitRemoveConstructIHM6();
	void upperSplitFinishConstructIHM7();
	void lowerSplitScanConstructIHM5();
	void lowerSplitRemoveConstructIHM6();
	void lowerSplitFinishConstructIHM7();
	void allSplitFinishConstructIHM8();
private:
	Ui::ScanTipWidget ui;
};
#endif