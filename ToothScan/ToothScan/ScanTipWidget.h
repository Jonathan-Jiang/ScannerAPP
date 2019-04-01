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
#include <Qtimer>

class ScanTipWidget : public QWidget
{
	Q_OBJECT

public:
	ScanTipWidget(QWidget *parent = Q_NULLPTR);
	~ScanTipWidget();
	
	void setConnection();
	int globalSpinCutValue;
	//top
	QLabel *primaryTipLabel;
	QLabel *secondTipLabel;
	
	//middle
	//����
	QLabel *imageTipLabel;
	//��ɨ
	QTimer *timer;
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
	void cutVariable2();//ˮƽ�и�
	void finishVariable3();//���
	void splitScanVariable4();//���

	void placeConstruct1();//����
	void compenConstruct2();//��ɨ
	void cutConstruct2();
	void upperFinishConstruct3();//���
	void lowerFinishConstruct3();//���
	void allFinishConstruct3();//���

	void allPlaceConstructIHM1();//����ȫ�
	
	void allCompenConstructIHM2();//��ɨȫ�

	void allCutConstructIHM3();

	void allPlaceConstructIHM4();//�������
	
	void allCompenConstructIHM5();//��ɨ���

	void allCutConstructIHM6();

	void allPlaceConstructIHM7();//�������

	void allCompenConstructIHM8();//��ɨ���

	void allCutConstructIHM9();

	void allFinishConstructIHM10();//���

	void upperPlaceConstructIHM1();

	void upperCompenConstructIHM2();

	void upperCutConstructIHM3();

	void upperFinishConstructIHM4();

	void lowerPlaceConstructIHM1();

	void lowerCompenConstructIHM2();

	void lowerCutConstructIHM3();

	void lowerFinishConstructIHM4();

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

signals:
	void updateModelAngle();

public slots:
	void updatePage();

private:
	Ui::ScanTipWidget ui;
};
#endif