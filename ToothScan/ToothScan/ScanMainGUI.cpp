#include "ScanMainGUI.h"

ScanMainGUI::ScanMainGUI(QWidget *parent)
	: QWidget(parent)
{
	
	this->initVariable();
	this->constructIHM();
	//this->setConnections();
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(pushBtnClicked()));
	connect(ui.frontviewBtn, SIGNAL(clicked()), this, SLOT(fontviewBtnClicked()));
	connect(ui.rightViewBtn, SIGNAL(clicked()), this, SLOT(rightViewBtnClicked()));
	connect(ui.leftViewBtn, SIGNAL(clicked()), this, SLOT(leftViewBtnClicked()));
	connect(ui.backViewBtn, SIGNAL(clicked()), this, SLOT(backViewBtnClicked()));
	connect(ui.jawViewBtn, SIGNAL(clicked()), this, SLOT(jawViewBtnClicked()));
	connect(ui.narrowViewBtn, SIGNAL(clicked()), this, SLOT(narrowViewBtnClicked()));
	connect(ui.enlargeViewBtn, SIGNAL(clicked()), this, SLOT(enlargeViewBtnClicked()));
	connect(ui.modelMoveStateSetBtn, SIGNAL(clicked()), this, SLOT(modelMoveStateSetBtnClicked()));
	connect(ui.delSelectedBtn, SIGNAL(clicked()), this, SLOT(delSelectedBtnClicked()));
	connect(ui.confirmSelectedBtn, SIGNAL(clicked()), this, SLOT(delSelectedBtnClicked()));
	connect(ui.bgGroundmoveDownBtn, SIGNAL(clicked()), this, SLOT(bgGroundmoveDownBtnClicked()));
	connect(ui.bgGroundmoveUpBtn, SIGNAL(clicked()), this, SLOT(bgGroundmoveUpBtnClicked()));
	connect(ui.bgGroundShowBtn, SIGNAL(clicked()), this, SLOT(bgGroundShowBtnClicked()));
	connect(ui.cutModelUnderBgBtn, SIGNAL(clicked()), this, SLOT(cutModelUnderBgBtnClicked()));
	connect(ui.changeBgColorBtn, SIGNAL(clicked()), this, SLOT(changeBgColorBtnClicked()));
	
	
	
}

ScanMainGUI::~ScanMainGUI()
{
	if (controlScanQThread->isRunning())
	{
		controlScanQThread->quit();
	}
	controlScanQThread->wait();
	
	if (controlComputeQThread->isRunning())
	{
		controlComputeQThread->quit();
	}
	controlComputeQThread->wait();
}


void ScanMainGUI::initVariable()
{
	glWidget = new GLWidget(this);
	return;
	tabMainPage = new TabMainGUI();
	tabMainPage->showMaximized();

	scanTipWidget = new ScanTipWidget(this);

	//��ʼ���߳�
	ControlScanThread = new ControlThread;
	ControlComputeThread = new ComputeThread;

	cv::Mat model_matrix = cv::Mat::eye(4, 4, CV_64FC1);
	cv::Mat view_matrix = rt_r/*.inv()*/;
	glWidget->SetMatrix(model_matrix, view_matrix);

	//�������̶߳���
	controlScanQThread = new QThread(this);
	controlComputeQThread = new QThread(this);
	//�����̣߳�������ӵ��Զ�����߳��ࣨ������
	ControlScanThread->moveToThread(controlScanQThread);
	ControlComputeThread->moveToThread(controlComputeQThread);

	//cameraWindow
	cameraWindow = new QDockWidget(QStringLiteral("�����ʾ"), this);
	cameraImageLabel = new QLabel(cameraWindow);
	cameraImageLabel->setStyleSheet("background-color:rgb(0,0,0);");
	cameraImageLabel->setScaledContents(true);

	autoTunePushButton = new QPushButton(QStringLiteral("�Զ�����"),cameraWindow);
	spinCameraBox = new QSpinBox(cameraWindow);
	sliderCamera = new QSlider(Qt::Horizontal, cameraWindow);
	spinCameraBox->setRange(0, 130);
	sliderCamera->setRange(0, 130);

	//toptoolButtons
	leftWatchButton = new QToolButton();
	rightWatchButton = new QToolButton();
	topWatchButton = new QToolButton();
	bottomWatchButton = new QToolButton();
	frontWatchButton = new QToolButton();
	backWatchButton = new QToolButton();
	enlargeButton = new QToolButton();
	shrinkButton = new QToolButton();
	//bottomtoolButtons
	selectRegionButton = new QToolButton();
	deleteModelButton = new QToolButton();
}

void ScanMainGUI::constructIHM()
{
	//glWidget->showMaximized();
	glWidget->setGeometry(0,0,1920,1080);
	glWidget->setWindowSize(QSize(1920, 1080));
	glWidget->showFullScreen();
	return;
	//�������
	cameraWindow->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetClosable); // ����ͣ���������ԣ����ƶ�,�ɹر�
	cameraWindow->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);//���ÿ�ͣ������Ϊ��������ߺ��ұ�
	cameraWindow->setGeometry(0, 0, 320, 276);
	
	cameraImageLabel->setGeometry(0,20,320,256);
	sliderCamera->setGeometry(0, 256, 175, 20);
	spinCameraBox->setGeometry(175, 256, 60, 20);
	autoTunePushButton->setGeometry(235,256,85,20);
	
	//cameraWindow->setContentsMargins(0, 0, 0, 0);
	
	//BottomTool�ײ�������
	leftWatchButton->setFixedSize(40,40);
	leftWatchButton->setIcon(QIcon(":/MainWidget/Resources/images/LeftView.png"));
	leftWatchButton->setIconSize(QSize(leftWatchButton->width(), leftWatchButton->height()));
	leftWatchButton->setStyleSheet("border-style:flat");

	rightWatchButton->setFixedSize(40, 40);
	rightWatchButton->setIcon(QIcon(":/MainWidget/Resources/images/RightView.png"));
	rightWatchButton->setIconSize(QSize(rightWatchButton->width(), rightWatchButton->height()));
	rightWatchButton->setStyleSheet("border-style:flat");

	topWatchButton->setFixedSize(40, 40);
	topWatchButton->setIcon(QIcon(":/MainWidget/Resources/images/TopView.png"));
	topWatchButton->setIconSize(QSize(topWatchButton->width(), topWatchButton->height()));
	topWatchButton->setStyleSheet("border-style:flat");

	bottomWatchButton->setFixedSize(40, 40);
	bottomWatchButton->setIcon(QIcon(":/MainWidget/Resources/images/BottomView.png"));
	bottomWatchButton->setIconSize(QSize(bottomWatchButton->width(), bottomWatchButton->height()));
	bottomWatchButton->setStyleSheet("border-style:flat");

	frontWatchButton->setFixedSize(40, 40);
	frontWatchButton->setIcon(QIcon(":/MainWidget/Resources/images/FrontView.png"));
	frontWatchButton->setIconSize(QSize(topWatchButton->width(), topWatchButton->height()));
	frontWatchButton->setStyleSheet("border-style:flat");

	backWatchButton->setFixedSize(40, 40);
	backWatchButton->setIcon(QIcon(":/MainWidget/Resources/images/BackView.png"));
	backWatchButton->setIconSize(QSize(bottomWatchButton->width(), bottomWatchButton->height()));
	backWatchButton->setStyleSheet("border-style:flat");
	
	enlargeButton->setFixedSize(40, 40);
	enlargeButton->setIcon(QIcon(":/MainWidget/Resources/images/enlarge.png"));
	enlargeButton->setIconSize(QSize(enlargeButton->width(), enlargeButton->height()));
	enlargeButton->setStyleSheet("border-style:flat");

	shrinkButton->setFixedSize(40, 40);
	shrinkButton->setIcon(QIcon(":/MainWidget/Resources/images/shrink.png"));
	shrinkButton->setIconSize(QSize(shrinkButton->width(), shrinkButton->height()));
	shrinkButton->setStyleSheet("border-style:flat");

	selectRegionButton->setFixedSize(40, 40);
	selectRegionButton->setIcon(QIcon(":/MainWidget/Resources/images/SelectRegion.png"));
	selectRegionButton->setIconSize(QSize(enlargeButton->width(), enlargeButton->height()));
	selectRegionButton->setStyleSheet("border-style:flat");

	deleteModelButton->setFixedSize(40, 40);
	deleteModelButton->setIcon(QIcon(":/MainWidget/Resources/images/DeleteSelected.png"));
	deleteModelButton->setIconSize(QSize(shrinkButton->width(), shrinkButton->height()));
	deleteModelButton->setStyleSheet("border-style:flat");

	//����������
	QWidget *topWidget = new QWidget(this);
	QHBoxLayout *topHLayout = new QHBoxLayout(topWidget);
	topHLayout->addStretch();
	topHLayout->addWidget(topWatchButton);
	topHLayout->addWidget(bottomWatchButton);
	topHLayout->addWidget(frontWatchButton);
	topHLayout->addWidget(backWatchButton);
	topHLayout->addWidget(leftWatchButton);
	topHLayout->addWidget(rightWatchButton);
	topHLayout->addWidget(enlargeButton);
	topHLayout->addWidget(shrinkButton);
	topHLayout->addStretch();
	topWidget->setGeometry(0, 10, 1920, 100);

	//�ײ�������
	QWidget *bottomWidget = new QWidget(this);
	QHBoxLayout *bottomHLayout = new QHBoxLayout(bottomWidget);
	bottomHLayout->addStretch();
	bottomHLayout->addWidget(selectRegionButton);
	bottomHLayout->addWidget(deleteModelButton);
	bottomHLayout->addStretch();

	bottomWidget->setGeometry(0, 900, 1920, 100);

	//��ʾ����
	scanTipWidget->setFixedSize(300,700);
	scanTipWidget->setGeometry(1615,80,300,700);
	scanTipWidget->setVisible(false);
}

void ScanMainGUI::setConnections()
{
	QObject::connect(sliderCamera, &QSlider::valueChanged, spinCameraBox, &QSpinBox::setValue);
	void (QSpinBox:: *spinBoxSignal)(int) = &QSpinBox::valueChanged;
	QObject::connect(spinCameraBox, spinBoxSignal, sliderCamera, &QSlider::setValue);
	spinCameraBox->setValue(35);
	
	//����������Ϣ
	connect(tabMainPage, SIGNAL(scanDataSignal(QJsonObject)), this, SLOT(doScanDialogSlot(QJsonObject)));

	//ɨ����ʾҳ��
	connect(scanTipWidget->forwardStepButton,SIGNAL(clicked()),this,SLOT(judgeForwardStep()));//ɨ�� ��� ��һ�� ��ť
	connect(scanTipWidget->backStepButton, SIGNAL(clicked()), this, SLOT(judgeBackStep()));//���� ��ť
	//����ɨ��
	connect(scanTipWidget->compensationButton, SIGNAL(clicked()), this, SLOT(compensationScan()));
	//������ɨ
	connect(scanTipWidget->discardButton, SIGNAL(clicked()), this, SLOT(discardCompensationSlot()));

	connect(scanTipWidget,SIGNAL(updateModelAngle()),this,SLOT(setRotationWaverSlot()));//RotationAndWaver

	//MeshandGpa
	connect(this, SIGNAL(gpaMeshSignal(int)), ControlComputeThread, SLOT(GPAMeshing(int)));
	//�����и��ģ��
	connect(this, SIGNAL(saveCutModelSignal()), this, SLOT(saveCutModelSlot()));
	//��������ģ�͵��ļ�
	connect(this, SIGNAL(saveModeltoFileSignal()), this, SLOT(saveModeltoFileSlot()));

	//ɨ����ƺͼ���
	connect(this, SIGNAL(compensationSignal(int)), ControlScanThread, SLOT(compensationControlScan()));
	connect(this, SIGNAL(compensationSignal(int)), ControlComputeThread, SLOT(compensationComputeScan(int)));
	connect(this, SIGNAL(startControlNormalScan(int)), ControlScanThread, SLOT(controlNormalScan()));
	connect(this, SIGNAL(startControlNormalScan(int)), ControlComputeThread, SLOT(controlComputeScan(int)));
	connect(ControlComputeThread, SIGNAL(computeFinish()), this, SLOT(JawScan()));
	//չʾģ��
	connect(ControlComputeThread, SIGNAL(showModeltoGlSingel(int)),this, SLOT(updateMeshModel(int)));
	connect(this, SIGNAL(updateMeshModelSingel(int)), this, SLOT(updateMeshModel(int)));
	connect(this, SIGNAL(updateModelsVtSingle()), this, SLOT(updateModelsVtSlot()));
	connect(ControlComputeThread, SIGNAL(cameraShowSignal()), this, SLOT(updateCamera()));

	//Calibrate�궨��ҳ��
	connect(tabMainPage->calibratePushButton, SIGNAL(clicked()), this, SLOT(ToothCalibrateSlot()));
	connect(tabMainPage->globalCaliPushButton, SIGNAL(clicked()), this, SLOT(GlobalCalibrateSlot()));

	//ģ�͹���������
	connect(this->topWatchButton,SIGNAL(clicked()), this, SLOT(topModelWatchSlot()));
	connect(this->bottomWatchButton, SIGNAL(clicked()), this, SLOT(bottomModelWatchSlot()));
	connect(this->leftWatchButton, SIGNAL(clicked()), this, SLOT(leftModelWatchSlot()));
	connect(this->rightWatchButton, SIGNAL(clicked()), this, SLOT(rightModelWatchSlot()));
	connect(this->frontWatchButton, SIGNAL(clicked()), this, SLOT(frontModelWatchSlot()));
	connect(this->backWatchButton, SIGNAL(clicked()), this, SLOT(backModelWatchSlot()));
	connect(this->enlargeButton, SIGNAL(clicked()), this, SLOT(enlargeModelSlot()));
	connect(this->shrinkButton, SIGNAL(clicked()), this, SLOT(shrinkModelSlot()));
	connect(this->selectRegionButton, SIGNAL(clicked()), this, SLOT(selectRegionSlot()));
	connect(this->deleteModelButton, SIGNAL(clicked()), this, SLOT(deleteSelectedRegionSlot()));

	//ˮƽ����
	connect(this, SIGNAL(cutSurfaceSignal(bool)), this, SLOT(showCutSurfaceSlot(bool)));
	connect(scanTipWidget->spinCutBox, SIGNAL(valueChanged(int)), this, SLOT(moveCutSurfaceSpinSlot()));
	connect(scanTipWidget->sliderCut, SIGNAL(valueChanged(int)), this, SLOT(moveCutSurfaceSliderSlot()));
	connect(scanTipWidget->cutHeightButton, SIGNAL(clicked()), this, SLOT(cutModelSlot()));
	connect(scanTipWidget->discardCutHeightButton, SIGNAL(clicked()), this, SLOT(discardCutModelSlot()));
}

void ScanMainGUI::ToothCalibrateSlot()
{
	ControlScanThread->controlCalibrationScan();
}

void ScanMainGUI::GlobalCalibrateSlot()
{
	ControlScanThread->controlGlobalCaliScan();
}

void ScanMainGUI::CalculatePointCloud()
{
	if (controlScanQThread->isRunning() == true && controlComputeQThread->isRunning() == true)  //�ж��߳�ռ��
	{
		emit startControlNormalScan(chooseJawIndex);
		return;
	}
	if (controlScanQThread->isRunning() == false)
	{
		//�������̣߳���û�������̴߳�����
		controlScanQThread->start();
		ControlScanThread->setFlage(false);
	}
	if (controlComputeQThread->isRunning() == false)
	{
		//�������̣߳���û�������̴߳�����
		controlComputeQThread->start();
		ControlComputeThread->setFlage(false);
	}
	emit startControlNormalScan(chooseJawIndex);
}

void ScanMainGUI::updateMeshModel(int refreshIndex)
{
	if (refreshIndex == 1)
	{
		glWidget->m_ModelsVt.clear();
	}
	
	if (chooseJawIndex == 1)
	{
		if (refreshIndex == 2 && glWidget->m_ModelsVt.size() != 0)
		{
			/*for (int i = 0; i < glWidget->m_ModelsVt.size(); i++)
			{
				upper_ModelsVt.push_back(glWidget->m_ModelsVt[i]);
			}*/
			upper_ModelsVt = glWidget->m_ModelsVt;
			glWidget->m_ModelsVt.clear();
		}
		if (ControlComputeThread->upper_mModel.size() != 0)
		{
			int scan_index = ControlComputeThread->upper_mModel.size() - 1;
			glWidget->mm = ControlComputeThread->upper_mModel[scan_index];
		}
		else
		{
			glWidget->update();
			this->showMaximized();
			return;
		}
		upperTeethModel = glWidget->makeObject();
	}
	else if (chooseJawIndex == 2)
	{
		if (refreshIndex == 2 && glWidget->m_ModelsVt.size() != 0)
		{
			/*for (int i = 0; i < glWidget->m_ModelsVt.size(); i++)
			{
				lower_ModelsVt.push_back(glWidget->m_ModelsVt[i]);
			}*/
			lower_ModelsVt = glWidget->m_ModelsVt;
			glWidget->m_ModelsVt.clear();
		}
		if (ControlComputeThread->lower_mModel.size() != 0)
		{
			int scan_index = ControlComputeThread->lower_mModel.size() - 1;
			glWidget->mm = ControlComputeThread->lower_mModel[scan_index];
		}
		else
		{
			glWidget->update();
			this->showMaximized();
			return;
		}
		lowerTeethModel = glWidget->makeObject();
	}
	else if (chooseJawIndex == 3)
	{
		if (refreshIndex == 2 && glWidget->m_ModelsVt.size() != 0)
		{
			/*for (int i = 0; i < glWidget->m_ModelsVt.size(); i++)
			{
				all_ModelsVt.push_back(glWidget->m_ModelsVt[i]);
			}*/
			all_ModelsVt = glWidget->m_ModelsVt;
			glWidget->m_ModelsVt.clear();
		}
		if (ControlComputeThread->all_mModel.size() != 0)
		{
			int scan_index = ControlComputeThread->all_mModel.size() - 1;
			glWidget->mm = ControlComputeThread->all_mModel[scan_index];
		}
		else
		{
			glWidget->update();
			this->showMaximized();
			return;
		}
		allTeethModel = glWidget->makeObject();
	}
	
	this->showMaximized();
}

void ScanMainGUI::doScanDialogSlot(QJsonObject scanObj)
{
	scanTipWidget->setVisible(true);
	cout <<"caseType"<< scanObj.value("caseType").toInt() << endl;
	cout << "upperJaw" << scanObj.value("upperJaw").toInt() << endl;
	filePath = scanObj.value("filePath").toString();//�����ļ�·�� 
	patientNameQStr = scanObj.value("patientName").toString();
	if (scanObj.value("caseType").toInt() == 1)
	{
		if (scanObj.value("upperJaw").toInt() == 1)
		{
			scanTipWidget->upperPlaceConstructIHM1();
			globalTipIndex = 1;
			forwardIndex = 1;
			chooseJawIndex = 1;
		}
		else if (scanObj.value("lowerJaw").toInt() == 1)
		{
			scanTipWidget->lowerPlaceConstructIHM1();
			globalTipIndex = 2;
			forwardIndex = 1;
			chooseJawIndex = 2;
		}
		else if (scanObj.value("allJaw").toInt() == 1)
		{
			scanTipWidget->allPlaceConstructIHM1();
			globalTipIndex = 3;
			forwardIndex = 1;
			chooseJawIndex = 3;
		}
	}
	else if (scanObj.value("caseType").toInt() == 2)
	{

	}
	tabMainPage->hide();
	this->showMaximized();
	scanTipWidget->showMaximized();
}

void ScanMainGUI::judgeForwardStep()
{
	scanTipWidget->setVisible(false);
	cout <<"forwardIndex: "<< forwardIndex << endl;
	if (forwardIndex == 1)
	{
		if (allJawIndex == 4 || allJawIndex == 7)
		{
			bool bShow = false;
			glWidget->showBkGround(false);
			glWidget->update();
		}
		CalculatePointCloud();
	}
	else if (forwardIndex == 2)
	{
		emit gpaMeshSignal(chooseJawIndex);
	}
	else if (forwardIndex == 3)
	{
		JawScan();
	}
	else if (forwardIndex == 4)
	{
		emit saveModeltoFileSignal();
		scanTipWidget->setVisible(false);
	}
}

void ScanMainGUI::JawScan()
{
	scanTipWidget->setVisible(true);
	if (globalTipIndex == 1)
	{
		if (compensationFlag == true)
		{
			--upperJawIndex;
		}
		if (upperJawIndex == 1)
		{
			scanTipWidget->upperCompenConstructIHM2();
			forwardIndex = 2;
			compensationFlag = false;
		}
		else if (upperJawIndex == 2)
		{
			scanTipWidget->upperCutConstructIHM3();
			forwardIndex = 3;
			emit cutSurfaceSignal(true);
		}
		else if (upperJawIndex == 3)
		{
			scanTipWidget->upperFinishConstructIHM4();
			forwardIndex = 4;
			emit cutSurfaceSignal(false);
		}
		++upperJawIndex;
	}
	else if (globalTipIndex == 2)
	{
		if (compensationFlag == true)
		{
			--lowerJawIndex;
		}

		if (lowerJawIndex == 1)
		{
			scanTipWidget->lowerCompenConstructIHM2();
			forwardIndex = 2;
			compensationFlag = false;
		}
		else if (lowerJawIndex == 2)
		{
			scanTipWidget->lowerCutConstructIHM3();
			forwardIndex = 3;
			emit cutSurfaceSignal(true);
		}
		else if (lowerJawIndex == 3)
		{
			scanTipWidget->lowerFinishConstructIHM4();
			forwardIndex = 4;
			emit cutSurfaceSignal(false);
		}
		++lowerJawIndex;
	}
	else if (globalTipIndex == 3)
	{
		if (compensationFlag == true)
		{
			--allJawIndex;
		}
		if (allJawIndex == 1)
		{
			scanTipWidget->allCompenConstructIHM2();
			forwardIndex = 2;
			compensationFlag = false;
		}
		else if (allJawIndex == 2)
		{
			scanTipWidget->allCutConstructIHM3();
			forwardIndex = 3;
			emit cutSurfaceSignal(true);
		}
		else if (allJawIndex == 3)
		{
			scanTipWidget->allPlaceConstructIHM4();
			forwardIndex = 1;
			chooseJawIndex = 2;
			emit cutSurfaceSignal(false);
		}
		else if (allJawIndex == 4)
		{
			scanTipWidget->allCompenConstructIHM5();
			forwardIndex = 2;
			compensationFlag = false;
		}
		else if (allJawIndex == 5)
		{
			scanTipWidget->allCutConstructIHM6();
			forwardIndex = 3;
			emit cutSurfaceSignal(true);
		}
		else if (allJawIndex == 6)
		{
			scanTipWidget->allPlaceConstructIHM7();
			forwardIndex = 1;
			chooseJawIndex = 1;
			emit cutSurfaceSignal(false);
		}
		else if (allJawIndex == 7)
		{
			scanTipWidget->allCompenConstructIHM8();
			forwardIndex = 2;
			compensationFlag = false;
		}
		else if (allJawIndex == 8)
		{
			scanTipWidget->allCutConstructIHM9();
			forwardIndex = 3;
			emit cutSurfaceSignal(true);
		}
		else if (allJawIndex == 9)
		{
			scanTipWidget->allFinishConstructIHM10();
			forwardIndex = 4;
			emit cutSurfaceSignal(false);
		}
		allJawIndex++;
	}
	
	this->showMaximized();
	scanTipWidget->showMaximized();
}

void ScanMainGUI::deleteAllCutModel()
{
	if (chooseJawIndex == 1)
	{
		if (upperCutModelNum > 0)
		{
			for (int i = 0; i < upperCutModelNum; i++)
			{
				ControlComputeThread->upper_mModel.pop_back();
			}
		}
	}
	else if (chooseJawIndex == 2)
	{
		if (lowerCutModelNum > 0)
		{
			for (int i = 0; i < lowerCutModelNum; i++)
			{
				ControlComputeThread->lower_mModel.pop_back();
			}
		}	
	}
	else if (chooseJawIndex == 3)
	{
		if (allCutModelNum > 0)
		{
			for (int i = 0; i < lowerCutModelNum; i++)
			{
				ControlComputeThread->all_mModel.pop_back();
			}
		}
	}	
}

void ScanMainGUI::judgeBackStep()
{
	scanTipWidget->setVisible(true);
	if (globalTipIndex == 1)
	{
		if (upperJawIndex == 2)
		{
			scanTipWidget->upperPlaceConstructIHM1();
			globalTipIndex = 1;
			forwardIndex = 1;
			chooseJawIndex = 1;
			ControlComputeThread->upper_mModel.clear();
			ControlComputeThread->upper_points_cloud_end2.clear();
			ControlComputeThread->upper_points_cloud_globle2.clear();
			cameraImageLabel->setStyleSheet("background-color:rgb(0,0,0);");
			emit updateMeshModelSingel(1);
		}
		else if (upperJawIndex == 3)
		{
			scanTipWidget->upperCompenConstructIHM2();
			forwardIndex = 2;
			compensationFlag = false;
			//ControlComputeThread->upper_mModel.pop_back();
			deleteAllCutModel();
			emit cutSurfaceSignal(false);
			emit updateModelsVtSingle();
		}
		else if (upperJawIndex == 4)
		{
			scanTipWidget->upperCutConstructIHM3();
			forwardIndex = 3;
			//ControlComputeThread->upper_mModel.pop_back();
			emit cutSurfaceSignal(true);
			emit updateMeshModelSingel(1);
		}
		--upperJawIndex;
	}
	else if (globalTipIndex == 2)
	{
		if (lowerJawIndex == 2)
		{
			scanTipWidget->lowerPlaceConstructIHM1();
			globalTipIndex = 2;
			forwardIndex = 1;
			chooseJawIndex = 2;
			ControlComputeThread->lower_mModel.clear();
			ControlComputeThread->lower_points_cloud_end2.clear();
			ControlComputeThread->lower_points_cloud_globle2.clear();
			cameraImageLabel->setStyleSheet("background-color:rgb(0,0,0);");
			emit updateMeshModelSingel(1);
		}
		else if (lowerJawIndex == 3)
		{
			scanTipWidget->lowerCompenConstructIHM2();
			forwardIndex = 2;
			compensationFlag = false;
			//ControlComputeThread->lower_mModel.pop_back();
			deleteAllCutModel();
			emit cutSurfaceSignal(false);
			emit updateModelsVtSingle();
		}
		else if (lowerJawIndex == 4)
		{
			scanTipWidget->lowerCutConstructIHM3();
			forwardIndex = 3;
			//ControlComputeThread->lower_mModel.pop_back();
			emit cutSurfaceSignal(true);
			emit updateMeshModelSingel(1);
		}
		--lowerJawIndex;
	}
	else if (globalTipIndex == 3)
	{
		if (allJawIndex == 2)
		{
			scanTipWidget->allPlaceConstructIHM1();
			globalTipIndex = 3;
			forwardIndex = 1;
			chooseJawIndex = 3;
			ControlComputeThread->all_mModel.clear();
			ControlComputeThread->all_points_cloud_end2.clear();
			ControlComputeThread->all_points_cloud_globle2.clear();
			cameraImageLabel->setStyleSheet("background-color:rgb(0,0,0);");
			emit updateMeshModelSingel(1);
		}
		else if (allJawIndex == 3)
		{
			scanTipWidget->allCompenConstructIHM2();
			forwardIndex = 2;
			compensationFlag = false;
			//ControlComputeThread->all_mModel.pop_back();
			deleteAllCutModel();
			emit cutSurfaceSignal(false);
			emit updateModelsVtSingle();
		}
		else if (allJawIndex == 4)
		{
			scanTipWidget->allCutConstructIHM3();
			forwardIndex = 3;
			//ControlComputeThread->all_mModel.pop_back();
			emit cutSurfaceSignal(true);
			emit updateMeshModelSingel(1);
		}
		else if (allJawIndex == 5)
		{
			scanTipWidget->allPlaceConstructIHM4();
			forwardIndex = 1;
			chooseJawIndex = 2;
			ControlComputeThread->lower_mModel.clear();
			ControlComputeThread->lower_points_cloud_end2.clear();
			ControlComputeThread->lower_points_cloud_globle2.clear();
			emit cutSurfaceSignal(false);
			emit updateMeshModelSingel(1);
		}
		else if (allJawIndex == 6)
		{
			scanTipWidget->allCompenConstructIHM5();
			forwardIndex = 2;
			compensationFlag = false;
			//ControlComputeThread->lower_mModel.pop_back();
			deleteAllCutModel();
			emit cutSurfaceSignal(false);
			emit updateModelsVtSingle();
		}
		else if (allJawIndex == 7)
		{
			scanTipWidget->allCutConstructIHM6();
			forwardIndex = 3;
			//ControlComputeThread->lower_mModel.pop_back();
			emit cutSurfaceSignal(true);
			emit updateMeshModelSingel(1);
		}
		else if (allJawIndex == 8)
		{
			scanTipWidget->allPlaceConstructIHM7();
			forwardIndex = 1;
			chooseJawIndex = 1;
			ControlComputeThread->upper_mModel.clear();
			ControlComputeThread->upper_points_cloud_end2.clear();
			ControlComputeThread->upper_points_cloud_globle2.clear();
			emit cutSurfaceSignal(false);
			emit updateMeshModelSingel(1);
		}
		else if (allJawIndex == 9)
		{
			scanTipWidget->allCompenConstructIHM8();
			forwardIndex = 2;
			compensationFlag = false;
			//ControlComputeThread->upper_mModel.pop_back();
			deleteAllCutModel();
			emit cutSurfaceSignal(false);
			emit updateModelsVtSingle();
		}
		else if (allJawIndex == 10)
		{
			scanTipWidget->allCutConstructIHM9();
			forwardIndex = 3;
			//ControlComputeThread->upper_mModel.pop_back();
			emit cutSurfaceSignal(true);
			emit updateMeshModelSingel(1);
		}
		--allJawIndex;
	}

	this->showMaximized();
	scanTipWidget->showMaximized();
}

void ScanMainGUI::compensationScan()
{
	compensationFlag = true;
	//float ax = 0, ay = 0;
	//glWidget->GetMotorRot(ax, ay);
	c_scan_x = ax;
	c_scan_y = ay;
	cout << "c_scan_x: " << c_scan_x << "; c_scan_y: " << c_scan_y;
	if (c_scan_x>-90 && c_scan_x<90)
	{
		if (controlScanQThread->isRunning() == true && controlComputeQThread->isRunning() == true)  //�ж��߳�ռ��
		{
			emit compensationSignal(chooseJawIndex);
			return;
		}
		if(controlScanQThread->isRunning() == false)
		{
			//�������̣߳���û�������̴߳�����
			controlScanQThread->start();
			ControlScanThread->setFlage(false);
		}
		if (controlComputeQThread->isRunning() == false)
		{
			//�������̣߳���û�������̴߳�����
			controlComputeQThread->start();
			ControlComputeThread->setFlage(false);
		}
		emit compensationSignal(chooseJawIndex);
	}
}

void ScanMainGUI::discardCompensationSlot()
{
	if (chooseJawIndex == 1)
	{
		if (ControlComputeThread->addUpperCompensationNum > 0)
		{
			ControlComputeThread->upper_mModel.pop_back();
			glWidget->m_ModelsVt.pop_back();
			glWidget->update();
			--ControlComputeThread->addUpperCompensationNum;
		}
		else
		{
			QMessageBox box(QMessageBox::Warning, QStringLiteral("��ʾ"), QStringLiteral("���û����ɨ����!"));
			box.setStandardButtons(QMessageBox::Yes);
			box.setButtonText(QMessageBox::Yes, QStringLiteral("ȷ ��"));
			box.exec();
		}
	}
	else if (chooseJawIndex == 2)
	{
		if (ControlComputeThread->addLowerCompensationNum > 0)
		{
			ControlComputeThread->lower_mModel.pop_back();
			glWidget->m_ModelsVt.pop_back();
			glWidget->update();
			--ControlComputeThread->addLowerCompensationNum;
		}
		else
		{
			QMessageBox box(QMessageBox::Warning, QStringLiteral("��ʾ"), QStringLiteral("���û����ɨ����!"));
			box.setStandardButtons(QMessageBox::Yes);
			box.setButtonText(QMessageBox::Yes, QStringLiteral("ȷ ��"));
			box.exec();
		}
	}
	else if (chooseJawIndex == 3)
	{
		if (ControlComputeThread->addAllCompensationNum > 0)
		{
			ControlComputeThread->all_mModel.pop_back();
			glWidget->m_ModelsVt.pop_back();
			glWidget->update();
			--ControlComputeThread->addAllCompensationNum;
		}
		else
		{
			QMessageBox box(QMessageBox::Warning, QStringLiteral("��ʾ"), QStringLiteral("ȫ�û����ɨ����!"));
			box.setStandardButtons(QMessageBox::Yes);
			box.setButtonText(QMessageBox::Yes, QStringLiteral("ȷ ��"));
			box.exec();
		}
	}
}

void ScanMainGUI::topModelWatchSlot()
{
	glWidget->upwardView();
}

void ScanMainGUI::bottomModelWatchSlot()
{
	glWidget->overView();
}

void ScanMainGUI::leftModelWatchSlot()
{
	glWidget->leftView();
}

void ScanMainGUI::rightModelWatchSlot()
{
	glWidget->rightView();
}

void ScanMainGUI::frontModelWatchSlot()
{
	glWidget->mainView();
}

void ScanMainGUI::backModelWatchSlot()
{
	glWidget->backView();
}

void ScanMainGUI::enlargeModelSlot()
{
	glWidget->enlargeView();
}

void ScanMainGUI::shrinkModelSlot()
{
	glWidget->shrinkView();
}

void ScanMainGUI::selectRegionSlot()
{
	if (bSelected == false)
	{
		bSelected = true;
	}
	else
	{
		bSelected = false;
	}
	glWidget->selectRegion(bSelected);
}

void ScanMainGUI::deleteSelectedRegionSlot()
{
	glWidget->delSelected();
}

void ScanMainGUI::showCutSurfaceSlot(bool bShow)
{
	glWidget->showBkGround(bShow);
	glWidget->update();
}

void ScanMainGUI::moveCutSurfaceSpinSlot()
{
	int curValue = scanTipWidget->spinCutBox->value();
	scanTipWidget->cutHeightLineEdit->setText(QString::number(curValue, 10));
	if (curValue > scanTipWidget->globalSpinCutValue)
	{
		glWidget->bgGroundmoveUp();
		scanTipWidget->globalSpinCutValue = curValue;
	}
	else if(curValue < scanTipWidget->globalSpinCutValue)
	{
		glWidget->bgGroundmoveDown();
		scanTipWidget->globalSpinCutValue = curValue;
	}
	
}

void ScanMainGUI::moveCutSurfaceSliderSlot()
{
	int curValue = scanTipWidget->sliderCut->value();
	scanTipWidget->cutHeightLineEdit->setText(QString::number(curValue, 10));
	if (curValue > scanTipWidget->globalSpinCutValue)
	{
		glWidget->bgGroundmoveUp();
		scanTipWidget->globalSpinCutValue = curValue;
	}
	else if (curValue < scanTipWidget->globalSpinCutValue)
	{
		glWidget->bgGroundmoveDown();
		scanTipWidget->globalSpinCutValue = curValue;
	}
}

void ScanMainGUI::cutModelSlot()
{
	glWidget->cutModelUnderBg();
	emit saveCutModelSignal();
}

void ScanMainGUI::setRotationWaverSlot()
{
	glWidget->GetMotorRot(ax, ay);
	
	while (ay<-180||ay>180)
	{
		if (ay>180)
		{
			float temp = ay - 180;
			ay = -180 + temp;
		}
		if (ay<-180)
		{
			float temp = ay + 180;
			ay = 180 + temp;
		}
	}
	
	scanTipWidget->rotationLineEdit->setText(QString("%1").arg(ay));
	scanTipWidget->waverLineEdit->setText(QString("%1").arg(ax));

	ax -= 68.3;
}

void ScanMainGUI::updateCamera()
{
	QImage cameraImage;
	cameraImage = Mat2QImage(ControlComputeThread->camera_image);
	cameraImageLabel->setPixmap(QPixmap::fromImage(cameraImage));
	cameraImageLabel->setScaledContents(true);
}

QImage ScanMainGUI::Mat2QImage(const cv::Mat &InputMat)
{
	cv::Mat TmpMat;
	// convert the color space to RGB
	if (InputMat.channels() == 1)
	{
		cv::cvtColor(InputMat, TmpMat, CV_GRAY2RGB);
	}
	else
	{
		cv::cvtColor(InputMat, TmpMat, CV_BGR2RGB);
	}
	// construct the QImage using the data of the mat, while do not copy the data
	QImage Result = QImage((const uchar*)(TmpMat.data), TmpMat.cols, TmpMat.rows,QImage::Format_RGB888);
	// deep copy the data from mat to QImage
	Result.bits();
	return Result;
}

void ScanMainGUI::saveCutModelSlot()
{
	if (chooseJawIndex == 1)
	{
		/*int size = glWidget->m_ModelsVt.size();
		glWidget->m_ModelsVt[size - 1];*/
		orth::MeshModel mm;
		upperTeethModel->getMeshModel(mm);
		ControlComputeThread->upper_mModel.push_back(mm);
		++upperCutModelNum;
	}
	else if (chooseJawIndex == 2)
	{
		orth::MeshModel mm;
		lowerTeethModel->getMeshModel(mm);
		ControlComputeThread->lower_mModel.push_back(mm);
		++lowerCutModelNum;
	}
	else if (chooseJawIndex == 3)
	{
		orth::MeshModel mm;
		allTeethModel->getMeshModel(mm);
		ControlComputeThread->all_mModel.push_back(mm);
		++allCutModelNum;
	}
	emit updateMeshModelSingel(1);
}

void ScanMainGUI::discardCutModelSlot()
{
	if (chooseJawIndex == 1)
	{
		if (upperCutModelNum > 0)
		{
			ControlComputeThread->upper_mModel.pop_back();
			--upperCutModelNum;
			emit updateMeshModelSingel(1);
		}
		else
		{
			QMessageBox box(QMessageBox::Warning, QStringLiteral("��ʾ"), QStringLiteral("���û���и�ģ��!"));
			box.setStandardButtons(QMessageBox::Yes);
			box.setButtonText(QMessageBox::Yes, QStringLiteral("ȷ ��"));
			box.exec();
			//QMessageBox::warning(NULL, QStringLiteral("��ʾ"), QStringLiteral("���û���и�ģ��!"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		}
	}
	else if (chooseJawIndex == 2)
	{
		if (lowerCutModelNum > 0)
		{
			ControlComputeThread->lower_mModel.pop_back();
			--lowerCutModelNum;
			emit updateMeshModelSingel(1);
		}
		else
		{
			QMessageBox box(QMessageBox::Warning, QStringLiteral("��ʾ"), QStringLiteral("���û���и�ģ��!"));
			box.setStandardButtons(QMessageBox::Yes);
			box.setButtonText(QMessageBox::Yes, QStringLiteral("ȷ ��"));
			box.exec();
		}
	}
	else if (chooseJawIndex == 3)
	{
		if (allCutModelNum > 0)
		{
			ControlComputeThread->all_mModel.pop_back();
			--allCutModelNum;
			emit updateMeshModelSingel(1);
		}
		else
		{
			QMessageBox box(QMessageBox::Warning, QStringLiteral("��ʾ"), QStringLiteral("ȫ�û���и�ģ��!"));
			box.setStandardButtons(QMessageBox::Yes);
			box.setButtonText(QMessageBox::Yes, QStringLiteral("ȷ ��"));
			box.exec();
		}
	}

}

void ScanMainGUI::updateModelsVtSlot()
{
	glWidget->m_ModelsVt.clear();
	if (chooseJawIndex == 1)
	{
		/*for (int i = 0; i < upper_ModelsVt.size(); i++)
		{
			glWidget->m_ModelsVt.push_back(upper_ModelsVt[i]);
		}*/
		glWidget->m_ModelsVt = upper_ModelsVt;
	}
	else if (chooseJawIndex == 2)
	{
		glWidget->m_ModelsVt = lower_ModelsVt;
	}
	else if (chooseJawIndex == 3)
	{
		glWidget->m_ModelsVt = all_ModelsVt;
	}
	glWidget->update();
	this->showMaximized();
}

void ScanMainGUI::saveModeltoFileSlot()
{
	if (chooseJawIndex == 1)
	{
		int mModelVSize = ControlComputeThread->upper_mModel.size();
		/*for (int index = 0; index < mModelVSize - 1; index++)
		{
			orth::ModelIO model_io(&ControlComputeThread->upper_mModel[index]);
			std::string fileStr = filePath.toStdString() + tabMainPage->ToChineseStr(patientNameQStr).data() + "_UpperJaw_" + std::to_string(index) + ".stl";
			cout << "fileStr: " << fileStr << endl;
			model_io.writeModel(fileStr,"stl");
		}*/
		orth::ModelIO finish_model_io(&ControlComputeThread->upper_mModel[mModelVSize-1]);
		std::string modelNameStr = filePath.toStdString() + tabMainPage->ToChineseStr(patientNameQStr).data() + "_FinalUpperJawModel.stl";
		cout << "pathname: " << modelNameStr << endl;
		finish_model_io.writeModel(modelNameStr, "stl");
	}
	else if (chooseJawIndex == 2)
	{
		int mModelVSize = ControlComputeThread->lower_mModel.size();
		/*for (int index = 0; index < mModelVSize - 1; index++)
		{
			orth::ModelIO model_io(&ControlComputeThread->lower_mModel[index]);
			std::string fileStr = filePath.toStdString() + tabMainPage->ToChineseStr(patientNameQStr).data() + "_LowerJaw_" + std::to_string(index) + ".stl";
			model_io.writeModel(fileStr, "stl");
		}*/
		orth::ModelIO finish_model_io(&ControlComputeThread->lower_mModel[mModelVSize - 1]);
		std::string modelNameStr = filePath.toStdString() + tabMainPage->ToChineseStr(patientNameQStr).data() + "_FinalLowerJawModel.stl";
		cout << "pathname: " << modelNameStr << endl;
		finish_model_io.writeModel(modelNameStr, "stl");
	}
	else if (chooseJawIndex == 3)
	{
		int mModelVSize = ControlComputeThread->all_mModel.size();
		/*for (int index = 0; index < mModelVSize - 1; index++)
		{
			orth::ModelIO model_io(&ControlComputeThread->all_mModel[index]);
			std::string fileStr = filePath.toStdString() + tabMainPage->ToChineseStr(patientNameQStr).data() + "_AllJaw_" + std::to_string(index) + ".stl";
			model_io.writeModel(fileStr, "stl");
		}*/
		orth::ModelIO finish_model_io(&ControlComputeThread->all_mModel[mModelVSize - 1]);
		std::string modelNameStr = filePath.toStdString() + tabMainPage->ToChineseStr(patientNameQStr).data() + "_FinalAllJawModel.stl";
		cout << "pathname: " << modelNameStr << endl;
		finish_model_io.writeModel(modelNameStr, "stl");
	}
}

void ScanMainGUI::fontviewBtnClicked()
{
	//glWidget->frontView();
	glWidget->mainView();
}

void ScanMainGUI::pushBtnClicked()
{
	cout << "pushBtnClicked" << endl;
// 	QColor clearColor(Qt::GlobalColor::white);
// 	glWidget->setClearColor(clearColor);
	glWidget->upwardView();
}

void ScanMainGUI::rightViewBtnClicked()
{
	glWidget->rightView();
}

void ScanMainGUI::leftViewBtnClicked()
{
	glWidget->leftView();
}

void ScanMainGUI::backViewBtnClicked()
{
	glWidget->backView();
}

void ScanMainGUI::jawViewBtnClicked()
{
	//glWidget->jawView();
	glWidget->overView();
}

void ScanMainGUI::narrowViewBtnClicked()
{
	glWidget->shrinkView();
}

void ScanMainGUI::enlargeViewBtnClicked()
{
	glWidget->enlargeView();
}

void ScanMainGUI::modelMoveStateSetBtnClicked()
{
	//glWidget->setModelMoveState(ui.modelMoveStateSetBtn->isChecked());
	glWidget->selectRegion(ui.modelMoveStateSetBtn->isChecked());
}

void ScanMainGUI::delSelectedBtnClicked()
{
	glWidget->delSelected();
}

void ScanMainGUI::confirmSelectedBtnClicked()
{
	glWidget->confirmSelRegion();
}
void ScanMainGUI::bgGroundmoveDownBtnClicked()
{
	glWidget->bgGroundmoveDown();
}

void ScanMainGUI::bgGroundmoveUpBtnClicked()
{
	glWidget->bgGroundmoveUp();
}
void ScanMainGUI::bgGroundShowBtnClicked()
{
	glWidget->bgGroundmoveUp();
	glWidget->showBkGround(ui.bgGroundShowBtn->isChecked());
}

void ScanMainGUI::cutModelUnderBgBtnClicked()
{
	glWidget->cutModelUnderBg();
}

void ScanMainGUI::changeBgColorBtnClicked()
{
	float r = ui.textEditR->toPlainText().toFloat()/255,
		g = ui.textEditG->toPlainText().toFloat()/255,
		b = ui.textEditB->toPlainText().toFloat()/255,
		alpa = ui.textEditA->toPlainText().toFloat()/255;
	glWidget->setBgColor(QVector4D(r,g,b,alpa));
}
