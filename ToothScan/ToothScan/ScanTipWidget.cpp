#include "ScanTipWidget.h"

ScanTipWidget::ScanTipWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->InitVariable();
	this->setConnection();
	this->setStyleSheet("background-color:rgb(246,246,246);");
	//this->upperFinishConstructIHM4();
	//this->lowerSplitScanConstructIHM5();
	//this->upperPlaceConstructIHM1();
}

ScanTipWidget::~ScanTipWidget()
{
}

void ScanTipWidget::updatePage()
{
	emit updateModelAngle();
}


void ScanTipWidget::setConnection()
{
	spinCutBox->setRange(-50,50);
	sliderCut->setRange(-50,50);

	QObject::connect(sliderCut, &QSlider::valueChanged, spinCutBox, &QSpinBox::setValue);
	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	QObject::connect(spinCutBox, spinBoxSignal, sliderCut, &QSlider::setValue);
	spinCutBox->setValue(0);
	globalSpinCutValue = 0;
	cutHeightLineEdit->setText(QString::number(globalSpinCutValue, 10));

	connect(timer, SIGNAL(timeout()), this, SLOT(updatePage()));
	timer->start(1000);
}
void ScanTipWidget::InitVariable()
{
	timer = new QTimer(this);

	//top
	QFont ft;
	ft.setPointSize(14);
	primaryTipLabel = new QLabel(this);
	primaryTipLabel->setFont(ft);
	secondTipLabel = new QLabel(this);
	ft.setPointSize(11);
	secondTipLabel->setFont(ft);

	//middle
	imageTipLabel = new QLabel(this);
	imageTipLabel->setScaledContents(true);
	
	compensationButton = new QPushButton(QStringLiteral("����ɨ��"), this);//���Ӳ�ɨ
	compensationButton->setToolTip(QStringLiteral("����ɨ��"));
	discardButton = new QPushButton(QStringLiteral("������ɨ"), this);//������ɨ
	discardButton->setToolTip(QStringLiteral("������ɨ"));
	rotationLabel = new QLabel(QStringLiteral("��ת�Ƕ�:"), this);
	rotationLineEdit = new QLineEdit(this);//��ת�Ƕ�
	rotationLineEdit->setFixedSize(50, 20);
	rotationLineEdit->setStyleSheet("background-color:rgb(255,255,255);");
	waverLineEdit = new QLineEdit(this);//�ڶ��Ƕ�
	waverLabel = new QLabel(QStringLiteral("�ڶ��Ƕ�:"), this);
	waverLineEdit->setFixedSize(50, 20);
	waverLineEdit->setStyleSheet("background-color:rgb(255,255,255);");
	cutHeightLabel = new QLabel(QStringLiteral("�и�߶�:"), this);
	cutHeightLineEdit = new QLineEdit(this);//�и�߶�
	cutHeightLineEdit->setFixedSize(50, 20);
	cutHeightLineEdit->setStyleSheet("background-color:rgb(255,255,255);");
	spinCutBox = new QSpinBox();//�и����
	spinCutBox->setFixedWidth(18);
	sliderCut = new QSlider(Qt::Horizontal);
	cutHeightButton = new QPushButton(QStringLiteral("�и�ģ��"), this);//�и�߶�Ӧ��
	cutHeightButton->setToolTip(QStringLiteral("�и�ģ��"));
	discardCutHeightButton = new QPushButton(QStringLiteral("�����и�"), this);//�����и�߶�Ӧ��
	discardCutHeightButton->setToolTip(QStringLiteral("�����и�"));
	saveCutHeightButton = new QPushButton(QStringLiteral("����ΪĬ���и�߶�"), this);//���浱ǰ�и�߶�
	saveCutHeightButton->setToolTip(QStringLiteral("����ΪĬ���и�߶�"));

	upperShowButton = new QPushButton(this);
	lowerShowButton = new QPushButton(this);

	for (int i = 0; i < 8; i++)
	{
		QLabel *toothQLabel = new QLabel();
		toothQLabel->setFixedSize(40, 40);
		toothQLabel->setStyleSheet("border-width: 2px;border-style: solid;border-color: rgb(255, 128, 128);background-color:rgb(255,255,0);");
		toothList.append(toothQLabel);

		toothList[i]->setObjectName(QString::number(i, 10));
	}

	//bottom
	backStepButton = new QPushButton(this);
	forwardStepButton = new QPushButton(this);	
}

void ScanTipWidget::placeConstruct1()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget();
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleVWidget = new QWidget();
	QVBoxLayout *middleVLayout = new QVBoxLayout(middleVWidget);
	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	
	middleVLayout->addStretch();
	middleVLayout->addWidget(imageTipLabel);
	middleVLayout->addStretch();
	
	middleHLayout->addStretch();
	middleHLayout->addWidget(middleVWidget);
	middleHLayout->addStretch();

	middleWidget->setFixedSize(300, 500);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	//centerWidget->setObjectName("TipWidget");
	//centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	
	this->setLayout(totalVLayout);
	
}

void ScanTipWidget::compenConstruct2()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	//topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	//topHLayout->addStretch();
	topWidget->setFixedSize(300, 120);

	//middle
	QWidget *middleGWidget = new QWidget();
	QGridLayout *middleGLayout = new QGridLayout(middleGWidget);

	middleGLayout->addWidget(rotationLabel,0,0,1,1);
	middleGLayout->addWidget(rotationLineEdit, 0, 1, 1, 1);
	middleGLayout->addWidget(waverLabel, 0, 2, 1, 1);
	middleGLayout->addWidget(waverLineEdit, 0, 3, 1, 1);
	middleGLayout->addWidget(compensationButton, 1, 0, 1, 2);
	middleGLayout->addWidget(discardButton, 1, 2, 1, 2);
	middleGWidget->setFixedSize(250,150);

	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	middleHLayout->addStretch(2);
	middleHLayout->addWidget(middleGWidget);
	middleHLayout->addStretch(8);
	middleHLayout->setSpacing(0);
	middleHLayout->setMargin(0);
	middleWidget->setFixedSize(300, 450);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	//centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(2);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(3);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	//centerWidget->setObjectName("TipWidget");
	//centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);
	
}

void ScanTipWidget::cutConstruct2()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	//topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	//topHLayout->addStretch();
	topWidget->setFixedSize(300, 120);

	//middle
	QWidget *middleGWidget = new QWidget();
	QGridLayout *middleGLayout = new QGridLayout(middleGWidget);

	QWidget *middleRightBottomHWidget = new QWidget();
	QHBoxLayout *middleRightBottomHLayout = new QHBoxLayout(middleRightBottomHWidget);
	middleRightBottomHWidget->setFixedSize(113, 20);
	middleRightBottomHLayout->addWidget(spinCutBox);
	middleRightBottomHLayout->addWidget(sliderCut);
	middleRightBottomHLayout->setMargin(0);
	middleRightBottomHLayout->setSpacing(0);

	middleGLayout->addWidget(cutHeightLabel, 0, 0, 1, 1);
	middleGLayout->addWidget(cutHeightLineEdit, 0, 1, 1, 1);
	middleGLayout->addWidget(middleRightBottomHWidget, 0, 2, 1, 2);
	middleGLayout->addWidget(cutHeightButton, 1, 0, 1, 2);
	middleGLayout->addWidget(discardCutHeightButton, 1, 2, 1, 2);
	middleGLayout->addWidget(saveCutHeightButton, 2, 0, 1, 4);

	middleGWidget->setFixedSize(250, 150);

	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	middleHLayout->addStretch(2);
	middleHLayout->addWidget(middleGWidget);
	middleHLayout->addStretch(8);
	middleHLayout->setSpacing(0);
	middleHLayout->setMargin(0);
	middleWidget->setFixedSize(300, 450);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	//centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(2);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(3);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	//centerWidget->setObjectName("TipWidget");
	//centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);

}

void ScanTipWidget::upperFinishConstruct3()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleVWidget = new QWidget();
	QVBoxLayout *middleVLayout = new QVBoxLayout(middleVWidget);
	middleVLayout->addStretch();
	middleVLayout->addWidget(upperShowButton);
	middleVLayout->addStretch();
	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	middleHLayout->addStretch();
	middleHLayout->addWidget(middleVWidget);
	middleHLayout->addStretch();
	middleWidget->setFixedSize(300, 500);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	//centerWidget->setObjectName("TipWidget");
	//centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);
	
}

void ScanTipWidget::lowerFinishConstruct3()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleVWidget = new QWidget();
	QVBoxLayout *middleVLayout = new QVBoxLayout(middleVWidget);
	middleVLayout->addStretch();
	middleVLayout->addWidget(lowerShowButton);
	middleVLayout->addStretch();
	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	middleHLayout->addStretch();
	middleHLayout->addWidget(middleVWidget);
	middleHLayout->addStretch();
	middleWidget->setFixedSize(300, 500);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	//centerWidget->setObjectName("TipWidget");
	//centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);

}

void ScanTipWidget::allFinishConstruct3()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout();
	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleVWidget = new QWidget();
	QVBoxLayout *middleVLayout = new QVBoxLayout(middleVWidget);
	middleVLayout->addStretch();
	middleVLayout->addWidget(upperShowButton);
	middleVLayout->addWidget(lowerShowButton);
	middleVLayout->addStretch();
	QWidget *middleWidget = new QWidget();
	QHBoxLayout *middleHLayout = new QHBoxLayout(middleWidget);
	middleHLayout->addStretch();
	middleHLayout->addWidget(middleVWidget);
	middleHLayout->addStretch();
	middleWidget->setFixedSize(300, 500);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);
	//centerWidget->setObjectName("TipWidget");
	//centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);

}


void ScanTipWidget::splitScanConstruct1()
{
	if (this->layout() != NULL)
	{
		delete this->layout();
	}
	QVBoxLayout *totalVLayout = new QVBoxLayout(this);

	//total
	QWidget *centerWidget = new QWidget(this);
	QVBoxLayout *centerLayout = new QVBoxLayout(centerWidget);

	//top
	QWidget *topWidget = new QWidget();
	QVBoxLayout *topHLayout = new QVBoxLayout(topWidget);

	topHLayout->addWidget(primaryTipLabel);
	topHLayout->addStretch(1);
	topHLayout->addWidget(secondTipLabel);
	topHLayout->addStretch(2);
	topWidget->setFixedSize(300, 100);

	//middle
	QWidget *middleWidget = new QWidget();
	middleWidget->setFixedSize(300, 500);
	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setParent(middleWidget);
	}
	toothList[0]->setGeometry(125, 105, 20, 20);
	toothList[1]->setGeometry(125, 20, 20, 20);
	toothList[2]->setGeometry(180, 60, 20, 20);
	toothList[3]->setGeometry(205, 120, 20, 20);
	toothList[4]->setGeometry(160, 170, 20, 20);
	toothList[5]->setGeometry(90, 170, 20, 20);
	toothList[6]->setGeometry(45, 120, 20, 20);
	toothList[7]->setGeometry(70, 60, 20, 20);

	//bottom
	QWidget *bottomWidget = new QWidget();
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch(2);
	bottomHLayout->addWidget(backStepButton);
	bottomHLayout->addStretch(9);
	bottomHLayout->addWidget(forwardStepButton);
	bottomHLayout->addStretch(2);
	bottomWidget->setFixedSize(300, 100);

	//total
	centerLayout->addStretch(2);
	centerLayout->addWidget(topWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(middleWidget);
	centerLayout->addStretch(1);
	centerLayout->addWidget(bottomWidget);
	centerLayout->addStretch(2);
	centerLayout->setMargin(0);
	centerLayout->setSpacing(0);

	totalVLayout->addWidget(centerWidget);

	//centerWidget->setObjectName("TipWidget");
	//centerWidget->setStyleSheet("QWidget#TipWidget{border-width: 2px;border-style: solid;border-color: rgb(20,20,20)}");
	this->setLayout(totalVLayout);
}

void ScanTipWidget::placeVariable1()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(true);

	rotationLabel->setVisible(false);
	cutHeightLabel->setVisible(false);

	compensationButton->setVisible(false);//���Ӳ�ɨ
	discardButton->setVisible(false);//������ɨ
	rotationLineEdit->setVisible(false);//��ת�Ƕ�
	rotationLineEdit->setVisible(false);
	waverLineEdit->setVisible(false);//�ڶ��Ƕ�
	waverLabel->setVisible(false);
	cutHeightLineEdit->setVisible(false);//�и�߶�
	spinCutBox->setVisible(false);//�и����
	sliderCut->setVisible(false);
	cutHeightButton->setVisible(false);//�и�߶�Ӧ��
	discardCutHeightButton->setVisible(false);//�����и�߶�Ӧ��
	saveCutHeightButton->setVisible(false);//���浱ǰ�и�߶�

	upperShowButton->setVisible(false);
	lowerShowButton->setVisible(false);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(false);
	}

	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::compenVariable2()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(false);

	compensationButton->setVisible(true);//���Ӳ�ɨ
	discardButton->setVisible(true);//������ɨ
	rotationLineEdit->setVisible(true);//��ת�Ƕ�
	rotationLabel->setVisible(true);
	waverLineEdit->setVisible(true);//�ڶ��Ƕ�
	waverLabel->setVisible(true);

	cutHeightLabel->setVisible(false);
	cutHeightLineEdit->setVisible(false);//�и�߶�
	spinCutBox->setVisible(false);//�и����
	sliderCut->setVisible(false);
	cutHeightButton->setVisible(false);//�и�߶�Ӧ��
	discardCutHeightButton->setVisible(false);//�����и�߶�Ӧ��
	saveCutHeightButton->setVisible(false);//���浱ǰ�и�߶�

	upperShowButton->setVisible(false);
	lowerShowButton->setVisible(false);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(false);
	}
	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::cutVariable2()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(false);

	rotationLabel->setVisible(false);
	
	compensationButton->setVisible(false);//���Ӳ�ɨ
	discardButton->setVisible(false);//������ɨ
	rotationLineEdit->setVisible(false);//��ת�Ƕ�
	rotationLabel->setVisible(false);
	waverLineEdit->setVisible(false);//�ڶ��Ƕ�
	waverLabel->setVisible(false);

	cutHeightLabel->setVisible(true);
	cutHeightLineEdit->setVisible(true);//�и�߶�
	spinCutBox->setVisible(true);//�и����
	sliderCut->setVisible(true);
	cutHeightButton->setVisible(true);//�и�߶�Ӧ��
	discardCutHeightButton->setVisible(true);//�����и�߶�Ӧ��
	saveCutHeightButton->setVisible(true);//���浱ǰ�и�߶�

	upperShowButton->setVisible(false);
	lowerShowButton->setVisible(false);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(false);
	}
	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::finishVariable3()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(false);

	rotationLabel->setVisible(false);
	cutHeightLabel->setVisible(false);
	compensationButton->setVisible(false);//���Ӳ�ɨ
	discardButton->setVisible(false);//������ɨ
	rotationLineEdit->setVisible(false);//��ת�Ƕ�
	rotationLineEdit->setVisible(false);
	waverLineEdit->setVisible(false);//�ڶ��Ƕ�
	waverLabel->setVisible(false);
	cutHeightLineEdit->setVisible(false);//�и�߶�
	spinCutBox->setVisible(false);//�и����
	sliderCut->setVisible(false);
	cutHeightButton->setVisible(false);//�и�߶�Ӧ��
	discardCutHeightButton->setVisible(false);//�����и�߶�Ӧ��
	saveCutHeightButton->setVisible(false);//���浱ǰ�и�߶�

	upperShowButton->setVisible(true);
	lowerShowButton->setVisible(true);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(false);
	}
	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::splitScanVariable4()
{
	primaryTipLabel->setVisible(true);
	secondTipLabel->setVisible(true);

	imageTipLabel->setVisible(false);

	rotationLabel->setVisible(false);
	cutHeightLabel->setVisible(false);
	compensationButton->setVisible(false);//���Ӳ�ɨ
	discardButton->setVisible(false);//������ɨ
	rotationLineEdit->setVisible(false);//��ת�Ƕ�
	rotationLineEdit->setVisible(false);
	waverLineEdit->setVisible(false);//�ڶ��Ƕ�
	waverLabel->setVisible(false);
	cutHeightLineEdit->setVisible(false);//�и�߶�
	spinCutBox->setVisible(false);//�и����
	sliderCut->setVisible(false);
	cutHeightButton->setVisible(false);//�и�߶�Ӧ��
	discardCutHeightButton->setVisible(false);//�����и�߶�Ӧ��
	saveCutHeightButton->setVisible(false);//���浱ǰ�и�߶�

	upperShowButton->setVisible(false);
	lowerShowButton->setVisible(false);

	for (int i = 0; i < 8; i++)
	{
		toothList[i]->setVisible(true);
	}
	backStepButton->setVisible(true);
	forwardStepButton->setVisible(true);
}

void ScanTipWidget::allPlaceConstructIHM1()
{
	//ȫ򢡪��������1����������
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("�����ȫ�ģ��"));
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(180, 120);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/alljaw.png"));
	backStepButton->setVisible(false);
	forwardStepButton->setText(QStringLiteral("ɨ  ��"));
	forwardStepButton->setToolTip(QStringLiteral("ɨ  ��"));

	placeConstruct1();
}

void ScanTipWidget::allCompenConstructIHM2()
{
	//ȫ򢡪��������2����������
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("ȫ�ģ��ɨ����ɣ���������ģ������"));
	secondTipLabel->setText(QStringLiteral("��תģ�͵�����Ҫ����ɨ���λ�ã�ͨ�������Ӳ�ɨ���������ɨ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	compenConstruct2();
}

void ScanTipWidget::allCutConstructIHM3()
{
	//ȫ򢡪��������3����������
	cutVariable2();
	primaryTipLabel->setText(QStringLiteral("ȫ�ģ������ɨ����ɣ�����ˮƽ�и�ģ������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("����ˮƽ�и�ƽ���λ�ã�ͨ�����и�ģ�͡����޼�ģ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));

	cutConstruct2();
}

void ScanTipWidget::allPlaceConstructIHM4()
{
	//��򢡪��������4����������
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("���Ƴ�ȫ�Aģ�ͣ��������ģ��"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/lowerjaw.png"));
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("ɨ  ��"));
	forwardStepButton->setToolTip(QStringLiteral("ɨ  ��"));
	placeConstruct1();
}

void ScanTipWidget::allCompenConstructIHM5()
{
	//��򢡪��������5����������
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ��ɨ����ɣ���������ģ������"));
	secondTipLabel->setText(QStringLiteral("��תģ�͵�����Ҫ����ɨ���λ�ã�ͨ�������Ӳ�ɨ���������ɨ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	compenConstruct2();
}

void ScanTipWidget::allCutConstructIHM6()
{
	//��򢡪��������6����������
	cutVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ������ɨ����ɣ�����ˮƽ�и�ģ������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("����ˮƽ�и�ƽ���λ�ã�ͨ�����и�ģ�͡����޼�ģ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	cutConstruct2();
}

void ScanTipWidget::allPlaceConstructIHM7()
{
	//��򢡪��������7����������
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("���Ƴ����ģ�ͣ��������ģ��"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/upperjaw.png"));
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("ɨ  ��"));
	forwardStepButton->setToolTip(QStringLiteral("ɨ  ��"));
	placeConstruct1();
}

void ScanTipWidget::allCompenConstructIHM8()
{
	//��򢡪��������8����������
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ��ɨ����ɣ���������ģ������"));
	secondTipLabel->setText(QStringLiteral("��תģ�͵�����Ҫ����ɨ���λ�ã�ͨ�������Ӳ�ɨ���������ɨ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	compenConstruct2();
}

void ScanTipWidget::allCutConstructIHM9()
{
	//��򢡪��������9����������
	cutVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ������ɨ����ɣ�����ˮƽ�и�ģ������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("����ˮƽ�и�ƽ���λ�ã�ͨ�����и�ģ�͡����޼�ģ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	cutConstruct2();
}

void ScanTipWidget::allFinishConstructIHM10()
{
	//ȫ򢡪��������10����������
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("ƴ�����"));
	secondTipLabel->setText(QStringLiteral("�����޼�ģ������"));
	upperShowButton->setFixedSize(200, 100);
	upperShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/upperjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/upperjaw_yes.png);}");
	lowerShowButton->setFixedSize(200,100);
	lowerShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/lowerjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/lowerjaw_yes.png);}");
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��  ��"));
	forwardStepButton->setToolTip(QStringLiteral("��  ��"));
	allFinishConstruct3();
}

void ScanTipWidget::upperPlaceConstructIHM1()
{
	//��򢡪��������1����������
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("��������ģ��"));
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/upperjaw.png"));
	backStepButton->setVisible(false);
	forwardStepButton->setText(QStringLiteral("ɨ  ��"));
	forwardStepButton->setToolTip(QStringLiteral("ɨ  ��"));
	placeConstruct1();
}

void ScanTipWidget::upperCompenConstructIHM2()
{
	//��򢡪��������2����������
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ��ɨ����ɣ���������ģ������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("��תģ�͵�����Ҫ����ɨ���λ�ã�ͨ�������Ӳ�ɨ���������ɨ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	compenConstruct2();
}

void ScanTipWidget::upperCutConstructIHM3()
{
	//��򢡪��������3����������
	cutVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ������ɨ����ɣ�����ˮƽ�и�ģ������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("����ˮƽ�и�ƽ���λ�ã�ͨ�����и�ģ�͡����޼�ģ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	cutConstruct2();
}

void ScanTipWidget::upperFinishConstructIHM4()
{
	//��򢡪��������4����������
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("ƴ�����"));
	secondTipLabel->setText(QStringLiteral("����ͨ���������޼����ģ������"));
	upperShowButton->setFixedSize(200, 100);
	upperShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/upperjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/upperjaw_yes.png);}");
	lowerShowButton->setVisible(false);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��  ��"));
	forwardStepButton->setToolTip(QStringLiteral("��  ��"));
	upperFinishConstruct3();
}

void ScanTipWidget::lowerPlaceConstructIHM1()
{
	//��򢡪��������1����������
	placeVariable1();
	primaryTipLabel->setText(QStringLiteral("��������ģ��"));
	secondTipLabel->setVisible(false);
	imageTipLabel->setFixedSize(200, 130);
	imageTipLabel->setPixmap(QPixmap(":/MainWidget/Resources/images/lowerjaw.png"));
	backStepButton->setVisible(false);
	forwardStepButton->setText(QStringLiteral("ɨ  ��"));
	forwardStepButton->setToolTip(QStringLiteral("ɨ  ��"));
	placeConstruct1();
}

void ScanTipWidget::lowerCompenConstructIHM2()
{
	//��򢡪��������2����������
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ��ɨ����ɣ���������ģ������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("��תģ�͵�����Ҫ����ɨ���λ�ã�ͨ�������Ӳ�ɨ���������ɨ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	compenConstruct2();
}

void ScanTipWidget::lowerCutConstructIHM3()
{
	//��򢡪��������3����������
	cutVariable2();
	primaryTipLabel->setText(QStringLiteral("���ģ������ɨ����ɣ�����ˮƽ�и�ģ������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setText(QStringLiteral("����ˮƽ�и�ƽ���λ�ã�ͨ�����и�ģ�͡����޼�ģ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	cutConstruct2();
}

void ScanTipWidget::lowerFinishConstructIHM4()
{
	//��򢡪��������4����������
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("ƴ�����"));
	secondTipLabel->setText(QStringLiteral("�����޼����ģ������"));
	upperShowButton->setVisible(false);
	lowerShowButton->setFixedSize(200, 100);
	lowerShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/lowerjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/lowerjaw_yes.png);}");
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��  ��"));
	forwardStepButton->setToolTip(QStringLiteral("��  ��"));
	lowerFinishConstruct3();
}

void ScanTipWidget::upperSplitScanConstructIHM5()
{
	splitScanVariable4();

	primaryTipLabel->setText(QStringLiteral("���Ƴ����ģ�ͣ����������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	splitScanConstruct1();
}

void ScanTipWidget::upperSplitRemoveConstructIHM6()
{
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("����ģ��"));
	secondTipLabel->setText(QStringLiteral("��תģ�͵�����Ҫ����ɨ���λ�ã�ͨ�������Ӳ�ɨ���������ɨ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	compenConstruct2();
}

void ScanTipWidget::upperSplitFinishConstructIHM7()
{
	//ȫ򢡪��������7����������
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("���ƴ�����"));
	secondTipLabel->setText(QStringLiteral("�����޼�ģ������"));
	upperShowButton->setFixedSize(200, 100);
	upperShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/upperjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/upperjaw_yes.png);}");
	lowerShowButton->setVisible(false);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��  ��"));
	forwardStepButton->setToolTip(QStringLiteral("��  ��"));
	upperFinishConstruct3();
}

void ScanTipWidget::lowerSplitScanConstructIHM5()
{
	splitScanVariable4();
	splitScanConstruct1();
	primaryTipLabel->setText(QStringLiteral("���Ƴ����ģ�ͣ����������"));
	primaryTipLabel->adjustSize();
	primaryTipLabel->setWordWrap(true);
	secondTipLabel->setVisible(false);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	
}

void ScanTipWidget::lowerSplitRemoveConstructIHM6()
{
	compenVariable2();
	primaryTipLabel->setText(QStringLiteral("����ģ��"));
	secondTipLabel->setText(QStringLiteral("��תģ�͵�����Ҫ����ɨ���λ�ã�ͨ�������Ӳ�ɨ���������ɨ������"));
	secondTipLabel->adjustSize();
	secondTipLabel->setWordWrap(true);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��һ��"));
	forwardStepButton->setToolTip(QStringLiteral("��һ��"));
	compenConstruct2();
}

void ScanTipWidget::lowerSplitFinishConstructIHM7()
{
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("���ƴ�����"));
	secondTipLabel->setText(QStringLiteral("�����޼�ģ������"));
	lowerShowButton->setFixedSize(200, 100);
	lowerShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/lowerjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/lowerjaw_yes.png);}");
	upperShowButton->setVisible(false);
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��  ��"));
	forwardStepButton->setToolTip(QStringLiteral("��  ��"));
	lowerFinishConstruct3();
}

void ScanTipWidget::allSplitFinishConstructIHM8()
{
	finishVariable3();
	primaryTipLabel->setText(QStringLiteral("ƴ�����"));
	secondTipLabel->setText(QStringLiteral("�����޼�ģ������"));
	upperShowButton->setFixedSize(200, 100);
	upperShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/upperjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/upperjaw_yes.png);}");
	lowerShowButton->setFixedSize(200, 100);
	lowerShowButton->setStyleSheet("QPushButton{border-image: url(:/MainWidget/Resources/images/lowerjaw_no.png);}"
		"QPushButton:hover{border-image: url(:/MainWidget/Resources/images/lowerjaw_yes.png);}");
	backStepButton->setText(QStringLiteral("��  ��"));
	backStepButton->setToolTip(QStringLiteral("��  ��"));
	forwardStepButton->setText(QStringLiteral("��  ��"));
	forwardStepButton->setToolTip(QStringLiteral("��  ��"));

	allFinishConstruct3();
}