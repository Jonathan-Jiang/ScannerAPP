/********************************************************************************
** Form generated from reading UI file 'ScanMainGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANMAINGUI_H
#define UI_SCANMAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScanMainGUI
{
public:
    QPushButton *leftViewBtn;
    QPushButton *frontviewBtn;
    QPushButton *modelMoveStateSetBtn;
    QPushButton *jawViewBtn;
    QPushButton *rightViewBtn;
    QPushButton *backViewBtn;
    QPushButton *pushButton;
    QPushButton *narrowViewBtn;
    QPushButton *enlargeViewBtn;
    QPushButton *delSelectedBtn;
    QPushButton *confirmSelectedBtn;
    QPushButton *bgGroundmoveUpBtn;
    QPushButton *bgGroundmoveDownBtn;
    QPushButton *bgGroundShowBtn;
    QPushButton *cutModelUnderBgBtn;
    QTextEdit *textEditR;
    QTextEdit *textEditG;
    QTextEdit *textEditB;
    QPushButton *changeBgColorBtn;
    QTextEdit *textEditA;
    QGroupBox *ScanJawGroup;
    QLabel *ScanJawGroupTipImage;
    QPushButton *ScanJawScanBtn;
    QPushButton *ScanJawNextStepBtn;
    QLabel *ScanJawTips;
    QGroupBox *compensationScanPanel;
    QLabel *label_2;
    QPushButton *compensationScanPanelNextBtn;
    QPushButton *compensationScanPanelBackBtn;
    QLabel *compensationScanPanelTipLabel;
    QLabel *label_3;
    QLineEdit *rotationLineEdit;
    QLineEdit *waverLineEdit;
    QLabel *label_4;
    QPushButton *compensationBtn;
    QPushButton *discardBtn;
    QGroupBox *CutJawPanel;
    QLabel *label_5;
    QPushButton *cutPaneNextStepBtn;
    QPushButton *ScanJawNextStepBtn_2;
    QLabel *CutJawPanelTipsLabel;
    QLabel *label_6;
    QSlider *cutHeightSlider;
    QSpinBox *cutHeightSpinBox;
    QPushButton *cutModelBtn;
    QPushButton *unDoCutBtn;
    QPushButton *saveCutHeightCutBtn;
    QGroupBox *CutJawFinishPanel;
    QLabel *CutJawFinishPanelTips;
    QPushButton *CutJawFinishPanelNextStepBtn;
    QPushButton *CutJawFinishPanelBackBtn;
    QLabel *label_8;
    QLabel *CutJawFinishPanelTipImage;
    QGroupBox *StitchingPanel;
    QLabel *CutJawFinishPanelTips_3;
    QPushButton *stitchingPanelBtn;
    QPushButton *CutJawFinishPanelBackBtn_3;
    QLabel *StitchingPanelTips;
    QPushButton *manualStitchingBtn;
    QGroupBox *StitchingFinishPanel;
    QLabel *CutJawFinishPanelTips_5;
    QPushButton *stitchingFNextBtn;
    QPushButton *CutJawFinishPanelBackBtn_5;
    QLabel *StitchingPanelTips_3;
    QPushButton *stitchingUpperJawBtn;
    QPushButton *stitchingLowerJawBtn;
    QGroupBox *OralSubstitutePanel;
    QLabel *CutJawFinishPanelTips_4;
    QPushButton *OralSubstitutePanelNextBtn;
    QPushButton *CutJawFinishPanelBackBtn_4;
    QLabel *OralSubstitutePanel_2;
    QLabel *label;
    QLabel *teethNoLabel5;
    QLabel *teethNoLabel4;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *teethNoLabel3;
    QLabel *teethNoLabel2;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *teethNoLabel1;
    QLabel *teethNoLabel8;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *teethNoLabel6;
    QLabel *label_21;
    QLabel *teethNoLabel7;
    QGroupBox *TeethStitchingPanel;
    QLabel *CutJawFinishPanelTips_8;
    QPushButton *stitchingFNextBtn_2;
    QPushButton *CutJawFinishPanelBackBtn_8;
    QLabel *StitchingPanelTips_4;

    void setupUi(QWidget *ScanMainGUI)
    {
        if (ScanMainGUI->objectName().isEmpty())
            ScanMainGUI->setObjectName(QStringLiteral("ScanMainGUI"));
        ScanMainGUI->resize(1920, 1080);
        ScanMainGUI->setMaximumSize(QSize(1920, 1080));
        leftViewBtn = new QPushButton(ScanMainGUI);
        leftViewBtn->setObjectName(QStringLiteral("leftViewBtn"));
        leftViewBtn->setGeometry(QRect(350, 40, 75, 23));
        frontviewBtn = new QPushButton(ScanMainGUI);
        frontviewBtn->setObjectName(QStringLiteral("frontviewBtn"));
        frontviewBtn->setGeometry(QRect(170, 40, 75, 23));
        modelMoveStateSetBtn = new QPushButton(ScanMainGUI);
        modelMoveStateSetBtn->setObjectName(QStringLiteral("modelMoveStateSetBtn"));
        modelMoveStateSetBtn->setGeometry(QRect(780, 40, 171, 23));
        modelMoveStateSetBtn->setToolTipDuration(-3);
        modelMoveStateSetBtn->setCheckable(true);
        jawViewBtn = new QPushButton(ScanMainGUI);
        jawViewBtn->setObjectName(QStringLiteral("jawViewBtn"));
        jawViewBtn->setGeometry(QRect(520, 40, 75, 23));
        rightViewBtn = new QPushButton(ScanMainGUI);
        rightViewBtn->setObjectName(QStringLiteral("rightViewBtn"));
        rightViewBtn->setGeometry(QRect(260, 40, 75, 23));
        backViewBtn = new QPushButton(ScanMainGUI);
        backViewBtn->setObjectName(QStringLiteral("backViewBtn"));
        backViewBtn->setGeometry(QRect(440, 40, 75, 23));
        pushButton = new QPushButton(ScanMainGUI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 40, 75, 23));
        narrowViewBtn = new QPushButton(ScanMainGUI);
        narrowViewBtn->setObjectName(QStringLiteral("narrowViewBtn"));
        narrowViewBtn->setGeometry(QRect(700, 40, 75, 23));
        enlargeViewBtn = new QPushButton(ScanMainGUI);
        enlargeViewBtn->setObjectName(QStringLiteral("enlargeViewBtn"));
        enlargeViewBtn->setGeometry(QRect(610, 40, 75, 23));
        delSelectedBtn = new QPushButton(ScanMainGUI);
        delSelectedBtn->setObjectName(QStringLiteral("delSelectedBtn"));
        delSelectedBtn->setGeometry(QRect(70, 90, 171, 23));
        delSelectedBtn->setToolTipDuration(-3);
        delSelectedBtn->setCheckable(true);
        confirmSelectedBtn = new QPushButton(ScanMainGUI);
        confirmSelectedBtn->setObjectName(QStringLiteral("confirmSelectedBtn"));
        confirmSelectedBtn->setGeometry(QRect(270, 90, 171, 23));
        confirmSelectedBtn->setToolTipDuration(-3);
        confirmSelectedBtn->setCheckable(true);
        bgGroundmoveUpBtn = new QPushButton(ScanMainGUI);
        bgGroundmoveUpBtn->setObjectName(QStringLiteral("bgGroundmoveUpBtn"));
        bgGroundmoveUpBtn->setGeometry(QRect(490, 90, 131, 23));
        bgGroundmoveDownBtn = new QPushButton(ScanMainGUI);
        bgGroundmoveDownBtn->setObjectName(QStringLiteral("bgGroundmoveDownBtn"));
        bgGroundmoveDownBtn->setGeometry(QRect(650, 90, 211, 23));
        bgGroundShowBtn = new QPushButton(ScanMainGUI);
        bgGroundShowBtn->setObjectName(QStringLiteral("bgGroundShowBtn"));
        bgGroundShowBtn->setGeometry(QRect(880, 90, 211, 23));
        bgGroundShowBtn->setCheckable(true);
        cutModelUnderBgBtn = new QPushButton(ScanMainGUI);
        cutModelUnderBgBtn->setObjectName(QStringLiteral("cutModelUnderBgBtn"));
        cutModelUnderBgBtn->setGeometry(QRect(1110, 90, 211, 23));
        cutModelUnderBgBtn->setCheckable(false);
        textEditR = new QTextEdit(ScanMainGUI);
        textEditR->setObjectName(QStringLiteral("textEditR"));
        textEditR->setGeometry(QRect(1330, 80, 104, 71));
        textEditG = new QTextEdit(ScanMainGUI);
        textEditG->setObjectName(QStringLiteral("textEditG"));
        textEditG->setGeometry(QRect(1440, 80, 104, 71));
        textEditB = new QTextEdit(ScanMainGUI);
        textEditB->setObjectName(QStringLiteral("textEditB"));
        textEditB->setGeometry(QRect(1550, 80, 104, 71));
        changeBgColorBtn = new QPushButton(ScanMainGUI);
        changeBgColorBtn->setObjectName(QStringLiteral("changeBgColorBtn"));
        changeBgColorBtn->setGeometry(QRect(1770, 100, 211, 23));
        changeBgColorBtn->setCheckable(false);
        textEditA = new QTextEdit(ScanMainGUI);
        textEditA->setObjectName(QStringLiteral("textEditA"));
        textEditA->setGeometry(QRect(1660, 80, 104, 71));
        ScanJawGroup = new QGroupBox(ScanMainGUI);
        ScanJawGroup->setObjectName(QStringLiteral("ScanJawGroup"));
        ScanJawGroup->setEnabled(true);
        ScanJawGroup->setGeometry(QRect(0, 0, 301, 513));
        ScanJawGroup->setStyleSheet(QStringLiteral(""));
        ScanJawGroupTipImage = new QLabel(ScanJawGroup);
        ScanJawGroupTipImage->setObjectName(QStringLiteral("ScanJawGroupTipImage"));
        ScanJawGroupTipImage->setGeometry(QRect(10, 80, 271, 291));
        ScanJawGroupTipImage->setPixmap(QPixmap(QString::fromUtf8("Resources/images/alljaw.png")));
        ScanJawGroupTipImage->setScaledContents(true);
        ScanJawScanBtn = new QPushButton(ScanJawGroup);
        ScanJawScanBtn->setObjectName(QStringLiteral("ScanJawScanBtn"));
        ScanJawScanBtn->setGeometry(QRect(190, 470, 75, 23));
        ScanJawNextStepBtn = new QPushButton(ScanJawGroup);
        ScanJawNextStepBtn->setObjectName(QStringLiteral("ScanJawNextStepBtn"));
        ScanJawNextStepBtn->setGeometry(QRect(190, 430, 75, 23));
        ScanJawTips = new QLabel(ScanJawGroup);
        ScanJawTips->setObjectName(QStringLiteral("ScanJawTips"));
        ScanJawTips->setGeometry(QRect(10, 20, 281, 31));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        ScanJawTips->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(14);
        ScanJawTips->setFont(font);
        compensationScanPanel = new QGroupBox(ScanMainGUI);
        compensationScanPanel->setObjectName(QStringLiteral("compensationScanPanel"));
        compensationScanPanel->setEnabled(true);
        compensationScanPanel->setGeometry(QRect(1600, 790, 281, 531));
        label_2 = new QLabel(compensationScanPanel);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 90, 281, 81));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_2->setPalette(palette1);
        label_2->setFont(font);
        label_2->setWordWrap(true);
        compensationScanPanelNextBtn = new QPushButton(compensationScanPanel);
        compensationScanPanelNextBtn->setObjectName(QStringLiteral("compensationScanPanelNextBtn"));
        compensationScanPanelNextBtn->setGeometry(QRect(160, 470, 75, 23));
        compensationScanPanelBackBtn = new QPushButton(compensationScanPanel);
        compensationScanPanelBackBtn->setObjectName(QStringLiteral("compensationScanPanelBackBtn"));
        compensationScanPanelBackBtn->setEnabled(true);
        compensationScanPanelBackBtn->setGeometry(QRect(30, 470, 75, 23));
        compensationScanPanelTipLabel = new QLabel(compensationScanPanel);
        compensationScanPanelTipLabel->setObjectName(QStringLiteral("compensationScanPanelTipLabel"));
        compensationScanPanelTipLabel->setGeometry(QRect(0, 10, 271, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        compensationScanPanelTipLabel->setPalette(palette2);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(18);
        compensationScanPanelTipLabel->setFont(font1);
        compensationScanPanelTipLabel->setScaledContents(false);
        compensationScanPanelTipLabel->setWordWrap(true);
        label_3 = new QLabel(compensationScanPanel);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 190, 61, 21));
        rotationLineEdit = new QLineEdit(compensationScanPanel);
        rotationLineEdit->setObjectName(QStringLiteral("rotationLineEdit"));
        rotationLineEdit->setGeometry(QRect(100, 190, 113, 20));
        waverLineEdit = new QLineEdit(compensationScanPanel);
        waverLineEdit->setObjectName(QStringLiteral("waverLineEdit"));
        waverLineEdit->setGeometry(QRect(100, 230, 113, 20));
        label_4 = new QLabel(compensationScanPanel);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 230, 61, 21));
        compensationBtn = new QPushButton(compensationScanPanel);
        compensationBtn->setObjectName(QStringLiteral("compensationBtn"));
        compensationBtn->setGeometry(QRect(30, 320, 75, 23));
        discardBtn = new QPushButton(compensationScanPanel);
        discardBtn->setObjectName(QStringLiteral("discardBtn"));
        discardBtn->setGeometry(QRect(160, 320, 75, 23));
        CutJawPanel = new QGroupBox(ScanMainGUI);
        CutJawPanel->setObjectName(QStringLiteral("CutJawPanel"));
        CutJawPanel->setEnabled(true);
        CutJawPanel->setGeometry(QRect(1210, 770, 371, 513));
        CutJawPanel->setStyleSheet(QStringLiteral(""));
        label_5 = new QLabel(CutJawPanel);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 90, 281, 51));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_5->setPalette(palette3);
        label_5->setFont(font);
        label_5->setWordWrap(true);
        cutPaneNextStepBtn = new QPushButton(CutJawPanel);
        cutPaneNextStepBtn->setObjectName(QStringLiteral("cutPaneNextStepBtn"));
        cutPaneNextStepBtn->setGeometry(QRect(170, 460, 75, 23));
        ScanJawNextStepBtn_2 = new QPushButton(CutJawPanel);
        ScanJawNextStepBtn_2->setObjectName(QStringLiteral("ScanJawNextStepBtn_2"));
        ScanJawNextStepBtn_2->setGeometry(QRect(40, 460, 75, 23));
        CutJawPanelTipsLabel = new QLabel(CutJawPanel);
        CutJawPanelTipsLabel->setObjectName(QStringLiteral("CutJawPanelTipsLabel"));
        CutJawPanelTipsLabel->setGeometry(QRect(10, 10, 281, 61));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        CutJawPanelTipsLabel->setPalette(palette4);
        CutJawPanelTipsLabel->setFont(font);
        CutJawPanelTipsLabel->setWordWrap(true);
        label_6 = new QLabel(CutJawPanel);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 230, 61, 21));
        cutHeightSlider = new QSlider(CutJawPanel);
        cutHeightSlider->setObjectName(QStringLiteral("cutHeightSlider"));
        cutHeightSlider->setGeometry(QRect(180, 230, 160, 22));
        cutHeightSlider->setMinimum(-50);
        cutHeightSlider->setMaximum(50);
        cutHeightSlider->setOrientation(Qt::Horizontal);
        cutHeightSpinBox = new QSpinBox(CutJawPanel);
        cutHeightSpinBox->setObjectName(QStringLiteral("cutHeightSpinBox"));
        cutHeightSpinBox->setGeometry(QRect(80, 230, 91, 22));
        cutHeightSpinBox->setMinimum(-50);
        cutHeightSpinBox->setMaximum(50);
        cutModelBtn = new QPushButton(CutJawPanel);
        cutModelBtn->setObjectName(QStringLiteral("cutModelBtn"));
        cutModelBtn->setGeometry(QRect(40, 360, 75, 23));
        unDoCutBtn = new QPushButton(CutJawPanel);
        unDoCutBtn->setObjectName(QStringLiteral("unDoCutBtn"));
        unDoCutBtn->setGeometry(QRect(180, 360, 75, 23));
        saveCutHeightCutBtn = new QPushButton(CutJawPanel);
        saveCutHeightCutBtn->setObjectName(QStringLiteral("saveCutHeightCutBtn"));
        saveCutHeightCutBtn->setGeometry(QRect(70, 400, 141, 23));
        CutJawFinishPanel = new QGroupBox(ScanMainGUI);
        CutJawFinishPanel->setObjectName(QStringLiteral("CutJawFinishPanel"));
        CutJawFinishPanel->setEnabled(true);
        CutJawFinishPanel->setGeometry(QRect(1180, 240, 371, 513));
        CutJawFinishPanel->setStyleSheet(QStringLiteral(""));
        CutJawFinishPanelTips = new QLabel(CutJawFinishPanel);
        CutJawFinishPanelTips->setObjectName(QStringLiteral("CutJawFinishPanelTips"));
        CutJawFinishPanelTips->setGeometry(QRect(10, 90, 281, 51));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        CutJawFinishPanelTips->setPalette(palette5);
        CutJawFinishPanelTips->setFont(font);
        CutJawFinishPanelTips->setWordWrap(true);
        CutJawFinishPanelNextStepBtn = new QPushButton(CutJawFinishPanel);
        CutJawFinishPanelNextStepBtn->setObjectName(QStringLiteral("CutJawFinishPanelNextStepBtn"));
        CutJawFinishPanelNextStepBtn->setGeometry(QRect(230, 470, 75, 23));
        CutJawFinishPanelBackBtn = new QPushButton(CutJawFinishPanel);
        CutJawFinishPanelBackBtn->setObjectName(QStringLiteral("CutJawFinishPanelBackBtn"));
        CutJawFinishPanelBackBtn->setGeometry(QRect(30, 470, 75, 23));
        label_8 = new QLabel(CutJawFinishPanel);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 10, 281, 61));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_8->setPalette(palette6);
        label_8->setFont(font);
        label_8->setWordWrap(true);
        CutJawFinishPanelTipImage = new QLabel(CutJawFinishPanel);
        CutJawFinishPanelTipImage->setObjectName(QStringLiteral("CutJawFinishPanelTipImage"));
        CutJawFinishPanelTipImage->setGeometry(QRect(50, 140, 271, 291));
        CutJawFinishPanelTipImage->setPixmap(QPixmap(QString::fromUtf8("Resources/images/alljaw.png")));
        CutJawFinishPanelTipImage->setScaledContents(true);
        StitchingPanel = new QGroupBox(ScanMainGUI);
        StitchingPanel->setObjectName(QStringLiteral("StitchingPanel"));
        StitchingPanel->setEnabled(true);
        StitchingPanel->setGeometry(QRect(810, 320, 371, 513));
        StitchingPanel->setStyleSheet(QStringLiteral(""));
        CutJawFinishPanelTips_3 = new QLabel(StitchingPanel);
        CutJawFinishPanelTips_3->setObjectName(QStringLiteral("CutJawFinishPanelTips_3"));
        CutJawFinishPanelTips_3->setGeometry(QRect(10, 90, 281, 51));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        CutJawFinishPanelTips_3->setPalette(palette7);
        CutJawFinishPanelTips_3->setFont(font);
        CutJawFinishPanelTips_3->setToolTipDuration(-3);
        CutJawFinishPanelTips_3->setWordWrap(true);
        stitchingPanelBtn = new QPushButton(StitchingPanel);
        stitchingPanelBtn->setObjectName(QStringLiteral("stitchingPanelBtn"));
        stitchingPanelBtn->setGeometry(QRect(230, 470, 75, 23));
        CutJawFinishPanelBackBtn_3 = new QPushButton(StitchingPanel);
        CutJawFinishPanelBackBtn_3->setObjectName(QStringLiteral("CutJawFinishPanelBackBtn_3"));
        CutJawFinishPanelBackBtn_3->setGeometry(QRect(30, 470, 75, 23));
        StitchingPanelTips = new QLabel(StitchingPanel);
        StitchingPanelTips->setObjectName(QStringLiteral("StitchingPanelTips"));
        StitchingPanelTips->setGeometry(QRect(10, 10, 281, 61));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        StitchingPanelTips->setPalette(palette8);
        StitchingPanelTips->setFont(font);
        StitchingPanelTips->setWordWrap(true);
        manualStitchingBtn = new QPushButton(StitchingPanel);
        manualStitchingBtn->setObjectName(QStringLiteral("manualStitchingBtn"));
        manualStitchingBtn->setGeometry(QRect(140, 350, 75, 23));
        StitchingFinishPanel = new QGroupBox(ScanMainGUI);
        StitchingFinishPanel->setObjectName(QStringLiteral("StitchingFinishPanel"));
        StitchingFinishPanel->setEnabled(true);
        StitchingFinishPanel->setGeometry(QRect(1540, 240, 371, 513));
        StitchingFinishPanel->setStyleSheet(QStringLiteral(""));
        CutJawFinishPanelTips_5 = new QLabel(StitchingFinishPanel);
        CutJawFinishPanelTips_5->setObjectName(QStringLiteral("CutJawFinishPanelTips_5"));
        CutJawFinishPanelTips_5->setGeometry(QRect(10, 90, 281, 51));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        CutJawFinishPanelTips_5->setPalette(palette9);
        CutJawFinishPanelTips_5->setFont(font);
        CutJawFinishPanelTips_5->setToolTipDuration(-3);
        CutJawFinishPanelTips_5->setWordWrap(true);
        stitchingFNextBtn = new QPushButton(StitchingFinishPanel);
        stitchingFNextBtn->setObjectName(QStringLiteral("stitchingFNextBtn"));
        stitchingFNextBtn->setGeometry(QRect(230, 470, 75, 23));
        CutJawFinishPanelBackBtn_5 = new QPushButton(StitchingFinishPanel);
        CutJawFinishPanelBackBtn_5->setObjectName(QStringLiteral("CutJawFinishPanelBackBtn_5"));
        CutJawFinishPanelBackBtn_5->setGeometry(QRect(30, 470, 75, 23));
        StitchingPanelTips_3 = new QLabel(StitchingFinishPanel);
        StitchingPanelTips_3->setObjectName(QStringLiteral("StitchingPanelTips_3"));
        StitchingPanelTips_3->setGeometry(QRect(10, 10, 281, 61));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        StitchingPanelTips_3->setPalette(palette10);
        StitchingPanelTips_3->setFont(font);
        StitchingPanelTips_3->setWordWrap(true);
        stitchingUpperJawBtn = new QPushButton(StitchingFinishPanel);
        stitchingUpperJawBtn->setObjectName(QStringLiteral("stitchingUpperJawBtn"));
        stitchingUpperJawBtn->setGeometry(QRect(130, 180, 75, 23));
        stitchingUpperJawBtn->setCheckable(true);
        stitchingLowerJawBtn = new QPushButton(StitchingFinishPanel);
        stitchingLowerJawBtn->setObjectName(QStringLiteral("stitchingLowerJawBtn"));
        stitchingLowerJawBtn->setGeometry(QRect(130, 250, 75, 23));
        stitchingLowerJawBtn->setCheckable(true);
        OralSubstitutePanel = new QGroupBox(ScanMainGUI);
        OralSubstitutePanel->setObjectName(QStringLiteral("OralSubstitutePanel"));
        OralSubstitutePanel->setEnabled(true);
        OralSubstitutePanel->setGeometry(QRect(410, 320, 371, 513));
        OralSubstitutePanel->setStyleSheet(QStringLiteral(""));
        CutJawFinishPanelTips_4 = new QLabel(OralSubstitutePanel);
        CutJawFinishPanelTips_4->setObjectName(QStringLiteral("CutJawFinishPanelTips_4"));
        CutJawFinishPanelTips_4->setGeometry(QRect(10, 70, 281, 51));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        CutJawFinishPanelTips_4->setPalette(palette11);
        CutJawFinishPanelTips_4->setFont(font);
        CutJawFinishPanelTips_4->setToolTipDuration(-3);
        CutJawFinishPanelTips_4->setWordWrap(true);
        OralSubstitutePanelNextBtn = new QPushButton(OralSubstitutePanel);
        OralSubstitutePanelNextBtn->setObjectName(QStringLiteral("OralSubstitutePanelNextBtn"));
        OralSubstitutePanelNextBtn->setGeometry(QRect(230, 470, 75, 23));
        CutJawFinishPanelBackBtn_4 = new QPushButton(OralSubstitutePanel);
        CutJawFinishPanelBackBtn_4->setObjectName(QStringLiteral("CutJawFinishPanelBackBtn_4"));
        CutJawFinishPanelBackBtn_4->setGeometry(QRect(30, 470, 75, 23));
        OralSubstitutePanel_2 = new QLabel(OralSubstitutePanel);
        OralSubstitutePanel_2->setObjectName(QStringLiteral("OralSubstitutePanel_2"));
        OralSubstitutePanel_2->setGeometry(QRect(10, 10, 281, 61));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        OralSubstitutePanel_2->setPalette(palette12);
        OralSubstitutePanel_2->setFont(font);
        OralSubstitutePanel_2->setWordWrap(true);
        label = new QLabel(OralSubstitutePanel);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 120, 54, 12));
        teethNoLabel5 = new QLabel(OralSubstitutePanel);
        teethNoLabel5->setObjectName(QStringLiteral("teethNoLabel5"));
        teethNoLabel5->setGeometry(QRect(170, 140, 54, 12));
        teethNoLabel4 = new QLabel(OralSubstitutePanel);
        teethNoLabel4->setObjectName(QStringLiteral("teethNoLabel4"));
        teethNoLabel4->setGeometry(QRect(260, 190, 54, 16));
        label_10 = new QLabel(OralSubstitutePanel);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(300, 170, 54, 12));
        label_11 = new QLabel(OralSubstitutePanel);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(300, 260, 54, 12));
        teethNoLabel3 = new QLabel(OralSubstitutePanel);
        teethNoLabel3->setObjectName(QStringLiteral("teethNoLabel3"));
        teethNoLabel3->setGeometry(QRect(260, 280, 54, 16));
        teethNoLabel2 = new QLabel(OralSubstitutePanel);
        teethNoLabel2->setObjectName(QStringLiteral("teethNoLabel2"));
        teethNoLabel2->setGeometry(QRect(180, 340, 54, 16));
        label_14 = new QLabel(OralSubstitutePanel);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(220, 320, 54, 12));
        label_15 = new QLabel(OralSubstitutePanel);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(120, 320, 54, 12));
        teethNoLabel1 = new QLabel(OralSubstitutePanel);
        teethNoLabel1->setObjectName(QStringLiteral("teethNoLabel1"));
        teethNoLabel1->setGeometry(QRect(80, 340, 54, 16));
        teethNoLabel8 = new QLabel(OralSubstitutePanel);
        teethNoLabel8->setObjectName(QStringLiteral("teethNoLabel8"));
        teethNoLabel8->setGeometry(QRect(170, 240, 54, 16));
        label_18 = new QLabel(OralSubstitutePanel);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(210, 220, 54, 12));
        label_19 = new QLabel(OralSubstitutePanel);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(80, 170, 54, 12));
        teethNoLabel6 = new QLabel(OralSubstitutePanel);
        teethNoLabel6->setObjectName(QStringLiteral("teethNoLabel6"));
        teethNoLabel6->setGeometry(QRect(40, 190, 54, 16));
        label_21 = new QLabel(OralSubstitutePanel);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(80, 260, 54, 12));
        teethNoLabel7 = new QLabel(OralSubstitutePanel);
        teethNoLabel7->setObjectName(QStringLiteral("teethNoLabel7"));
        teethNoLabel7->setGeometry(QRect(40, 280, 54, 16));
        TeethStitchingPanel = new QGroupBox(ScanMainGUI);
        TeethStitchingPanel->setObjectName(QStringLiteral("TeethStitchingPanel"));
        TeethStitchingPanel->setEnabled(true);
        TeethStitchingPanel->setGeometry(QRect(20, 530, 371, 513));
        TeethStitchingPanel->setStyleSheet(QStringLiteral(""));
        CutJawFinishPanelTips_8 = new QLabel(TeethStitchingPanel);
        CutJawFinishPanelTips_8->setObjectName(QStringLiteral("CutJawFinishPanelTips_8"));
        CutJawFinishPanelTips_8->setGeometry(QRect(10, 90, 281, 51));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        CutJawFinishPanelTips_8->setPalette(palette13);
        CutJawFinishPanelTips_8->setFont(font);
        CutJawFinishPanelTips_8->setToolTipDuration(-3);
        CutJawFinishPanelTips_8->setWordWrap(true);
        stitchingFNextBtn_2 = new QPushButton(TeethStitchingPanel);
        stitchingFNextBtn_2->setObjectName(QStringLiteral("stitchingFNextBtn_2"));
        stitchingFNextBtn_2->setGeometry(QRect(230, 470, 75, 23));
        CutJawFinishPanelBackBtn_8 = new QPushButton(TeethStitchingPanel);
        CutJawFinishPanelBackBtn_8->setObjectName(QStringLiteral("CutJawFinishPanelBackBtn_8"));
        CutJawFinishPanelBackBtn_8->setGeometry(QRect(30, 470, 75, 23));
        StitchingPanelTips_4 = new QLabel(TeethStitchingPanel);
        StitchingPanelTips_4->setObjectName(QStringLiteral("StitchingPanelTips_4"));
        StitchingPanelTips_4->setGeometry(QRect(10, 10, 281, 61));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        StitchingPanelTips_4->setPalette(palette14);
        StitchingPanelTips_4->setFont(font);
        StitchingPanelTips_4->setWordWrap(true);
        ScanJawGroup->raise();
        leftViewBtn->raise();
        frontviewBtn->raise();
        modelMoveStateSetBtn->raise();
        jawViewBtn->raise();
        rightViewBtn->raise();
        backViewBtn->raise();
        pushButton->raise();
        narrowViewBtn->raise();
        enlargeViewBtn->raise();
        delSelectedBtn->raise();
        confirmSelectedBtn->raise();
        bgGroundmoveUpBtn->raise();
        bgGroundmoveDownBtn->raise();
        bgGroundShowBtn->raise();
        cutModelUnderBgBtn->raise();
        textEditR->raise();
        textEditG->raise();
        textEditB->raise();
        changeBgColorBtn->raise();
        textEditA->raise();
        compensationScanPanel->raise();
        CutJawPanel->raise();
        CutJawFinishPanel->raise();
        StitchingPanel->raise();
        StitchingFinishPanel->raise();
        OralSubstitutePanel->raise();
        TeethStitchingPanel->raise();

        retranslateUi(ScanMainGUI);

        QMetaObject::connectSlotsByName(ScanMainGUI);
    } // setupUi

    void retranslateUi(QWidget *ScanMainGUI)
    {
        ScanMainGUI->setWindowTitle(QApplication::translate("ScanMainGUI", "ScanMainGUI", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        ScanMainGUI->setToolTip(QApplication::translate("ScanMainGUI", "\347\241\256\350\256\244\351\200\211\346\213\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        leftViewBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\267\246\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        leftViewBtn->setText(QApplication::translate("ScanMainGUI", "leftViewBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        frontviewBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\211\215\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        frontviewBtn->setText(QApplication::translate("ScanMainGUI", "frontview", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        modelMoveStateSetBtn->setToolTip(QApplication::translate("ScanMainGUI", "\346\241\206\351\200\211", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        modelMoveStateSetBtn->setText(QApplication::translate("ScanMainGUI", "selectRegion", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        jawViewBtn->setToolTip(QApplication::translate("ScanMainGUI", "\351\242\214\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        jawViewBtn->setText(QApplication::translate("ScanMainGUI", "jawViewBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        rightViewBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\217\263\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        rightViewBtn->setText(QApplication::translate("ScanMainGUI", "rightViewBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        backViewBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\220\216\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        backViewBtn->setText(QApplication::translate("ScanMainGUI", "backViewBtn", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ScanMainGUI", "ChangeColor", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        narrowViewBtn->setToolTip(QApplication::translate("ScanMainGUI", "\347\274\251\345\260\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        narrowViewBtn->setText(QApplication::translate("ScanMainGUI", "narrowViewBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        enlargeViewBtn->setToolTip(QApplication::translate("ScanMainGUI", "\346\224\276\345\244\247", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        enlargeViewBtn->setText(QApplication::translate("ScanMainGUI", "enlargeViewBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        delSelectedBtn->setToolTip(QApplication::translate("ScanMainGUI", "\346\241\206\351\200\211", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        delSelectedBtn->setText(QApplication::translate("ScanMainGUI", "delSelected", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        confirmSelectedBtn->setToolTip(QApplication::translate("ScanMainGUI", "\347\241\256\350\256\244\351\200\211\346\213\251", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        confirmSelectedBtn->setText(QApplication::translate("ScanMainGUI", "confirmSelected", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        bgGroundmoveUpBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\267\246\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        bgGroundmoveUpBtn->setText(QApplication::translate("ScanMainGUI", "bgGroundmoveUpBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        bgGroundmoveDownBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\267\246\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        bgGroundmoveDownBtn->setText(QApplication::translate("ScanMainGUI", "bgGroundmoveDownBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        bgGroundShowBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\267\246\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        bgGroundShowBtn->setText(QApplication::translate("ScanMainGUI", "bgGroundShowBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        cutModelUnderBgBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\267\246\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        cutModelUnderBgBtn->setText(QApplication::translate("ScanMainGUI", "cutModelUnderBgBtn", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        changeBgColorBtn->setToolTip(QApplication::translate("ScanMainGUI", "\345\267\246\350\247\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        changeBgColorBtn->setText(QApplication::translate("ScanMainGUI", "changeBgColorBtn", Q_NULLPTR));
        ScanJawGroup->setTitle(QString());
        ScanJawGroupTipImage->setText(QString());
        ScanJawScanBtn->setText(QApplication::translate("ScanMainGUI", "\346\211\253\346\217\217", Q_NULLPTR));
        ScanJawNextStepBtn->setText(QApplication::translate("ScanMainGUI", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        ScanJawTips->setText(QApplication::translate("ScanMainGUI", "\344\270\212\351\242\214\346\250\241\345\236\213", Q_NULLPTR));
        compensationScanPanel->setTitle(QString());
        label_2->setText(QApplication::translate("ScanMainGUI", "\346\227\213\350\275\254\346\250\241\345\236\213\345\210\260\344\275\240\346\203\263\350\246\201\345\242\236\345\212\240\346\211\253\346\217\217\347\232\204\344\275\215\347\275\256\357\274\214\351\200\232\350\277\207\342\200\234\345\242\236\345\212\240\350\241\245\346\211\253\342\200\235\345\217\257\346\267\273\345\212\240\346\226\260\346\211\253\346\217\217\346\225\260\346\215\256", Q_NULLPTR));
        compensationScanPanelNextBtn->setText(QApplication::translate("ScanMainGUI", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        compensationScanPanelBackBtn->setText(QApplication::translate("ScanMainGUI", "\345\220\216\351\200\200", Q_NULLPTR));
        compensationScanPanelTipLabel->setText(QApplication::translate("ScanMainGUI", "\344\270\212\351\242\214\346\250\241\345\236\213\346\211\253\346\217\217\345\256\214\346\210\220\357\274\214\345\217\257\344\273\245\345\242\236\345\212\240\346\250\241\345\236\213\346\225\260\346\215\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("ScanMainGUI", "\346\227\213\350\275\254\350\247\222\345\272\246", Q_NULLPTR));
        label_4->setText(QApplication::translate("ScanMainGUI", "\346\221\206\345\212\250\350\247\222\345\272\246", Q_NULLPTR));
        compensationBtn->setText(QApplication::translate("ScanMainGUI", "\345\242\236\345\212\240\346\211\253\346\217\217", Q_NULLPTR));
        discardBtn->setText(QApplication::translate("ScanMainGUI", "\346\222\244\351\224\200\350\241\245\346\211\253", Q_NULLPTR));
        CutJawPanel->setTitle(QString());
        label_5->setText(QApplication::translate("ScanMainGUI", "\350\260\203\346\225\264\346\260\264\345\271\263\345\210\207\345\211\262\345\271\263\351\235\242\347\232\204\344\275\215\347\275\256\357\274\214\351\200\232\350\277\207\342\200\234\345\210\207\345\211\262\346\250\241\345\236\213\342\200\235\345\217\257\344\277\256\345\211\252\346\250\241\345\236\213\346\225\260\346\215\256", Q_NULLPTR));
        cutPaneNextStepBtn->setText(QApplication::translate("ScanMainGUI", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        ScanJawNextStepBtn_2->setText(QApplication::translate("ScanMainGUI", "\345\220\216\351\200\200", Q_NULLPTR));
        CutJawPanelTipsLabel->setText(QApplication::translate("ScanMainGUI", "\344\270\212\345\222\214\346\250\241\345\236\213\345\242\236\345\212\240\346\211\253\346\217\217\345\256\214\346\210\220\357\274\214\345\217\257\344\273\245\346\260\264\345\271\263\345\210\207\345\211\262\346\250\241\345\236\213\346\225\260\346\215\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("ScanMainGUI", "\345\210\207\345\211\262\351\253\230\345\272\246", Q_NULLPTR));
        cutModelBtn->setText(QApplication::translate("ScanMainGUI", "\345\210\207\345\211\262\346\250\241\345\236\213", Q_NULLPTR));
        unDoCutBtn->setText(QApplication::translate("ScanMainGUI", "\346\222\244\351\224\200\345\210\207\345\211\262", Q_NULLPTR));
        saveCutHeightCutBtn->setText(QApplication::translate("ScanMainGUI", "\344\277\235\345\255\230\344\270\272\351\273\230\350\256\244\345\210\207\345\211\262\351\253\230\345\272\246", Q_NULLPTR));
        CutJawFinishPanel->setTitle(QString());
        CutJawFinishPanelTips->setText(QApplication::translate("ScanMainGUI", "\345\217\257\344\273\245\351\200\232\350\277\207\345\267\245\345\205\267\346\240\217\344\277\256\345\211\252\344\270\212\351\242\214\346\250\241\345\236\213\346\225\260\346\215\256", Q_NULLPTR));
        CutJawFinishPanelNextStepBtn->setText(QApplication::translate("ScanMainGUI", "\345\256\214\346\210\220", Q_NULLPTR));
        CutJawFinishPanelBackBtn->setText(QApplication::translate("ScanMainGUI", "\345\220\216\351\200\200", Q_NULLPTR));
        label_8->setText(QApplication::translate("ScanMainGUI", "\346\213\274\346\216\245\345\256\214\346\210\220", Q_NULLPTR));
        CutJawFinishPanelTipImage->setText(QString());
        StitchingPanel->setTitle(QString());
        CutJawFinishPanelTips_3->setText(QApplication::translate("ScanMainGUI", "\345\217\214\345\207\273\350\216\267\345\217\2263\347\273\204\345\257\271\345\272\224\347\202\271", Q_NULLPTR));
        stitchingPanelBtn->setText(QApplication::translate("ScanMainGUI", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        CutJawFinishPanelBackBtn_3->setText(QApplication::translate("ScanMainGUI", "\345\220\216\351\200\200", Q_NULLPTR));
        StitchingPanelTips->setText(QApplication::translate("ScanMainGUI", "\346\213\274\346\216\245\344\270\212\351\242\214\346\250\241\345\236\213", Q_NULLPTR));
        manualStitchingBtn->setText(QApplication::translate("ScanMainGUI", "\346\211\213\345\212\250\346\213\274\346\216\245", Q_NULLPTR));
        StitchingFinishPanel->setTitle(QString());
        CutJawFinishPanelTips_5->setText(QApplication::translate("ScanMainGUI", "\345\217\257\344\273\245\344\277\256\345\211\252\346\250\241\345\236\213\346\225\260\346\215\256", Q_NULLPTR));
        stitchingFNextBtn->setText(QApplication::translate("ScanMainGUI", "\345\256\214\346\210\220", Q_NULLPTR));
        CutJawFinishPanelBackBtn_5->setText(QApplication::translate("ScanMainGUI", "\345\220\216\351\200\200", Q_NULLPTR));
        StitchingPanelTips_3->setText(QApplication::translate("ScanMainGUI", "\345\256\214\346\210\220", Q_NULLPTR));
        stitchingUpperJawBtn->setText(QApplication::translate("ScanMainGUI", "\344\270\212\351\242\214", Q_NULLPTR));
        stitchingLowerJawBtn->setText(QApplication::translate("ScanMainGUI", "\344\270\213\351\242\214", Q_NULLPTR));
        OralSubstitutePanel->setTitle(QString());
        CutJawFinishPanelTips_4->setText(QApplication::translate("ScanMainGUI", "\345\215\225\345\207\273\345\255\224\344\275\215,\345\234\250\346\250\241\345\236\213\344\270\212\346\240\207\350\256\260\347\211\231\351\275\277", Q_NULLPTR));
        OralSubstitutePanelNextBtn->setText(QApplication::translate("ScanMainGUI", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        CutJawFinishPanelBackBtn_4->setText(QApplication::translate("ScanMainGUI", "\345\220\216\351\200\200", Q_NULLPTR));
        OralSubstitutePanel_2->setText(QApplication::translate("ScanMainGUI", "\350\257\267\346\217\222\345\205\245\344\273\243\345\236\213\347\233\230", Q_NULLPTR));
        label->setText(QApplication::translate("ScanMainGUI", "5", Q_NULLPTR));
        teethNoLabel5->setText(QApplication::translate("ScanMainGUI", "17", Q_NULLPTR));
        teethNoLabel4->setText(QApplication::translate("ScanMainGUI", "16", Q_NULLPTR));
        label_10->setText(QApplication::translate("ScanMainGUI", "4", Q_NULLPTR));
        label_11->setText(QApplication::translate("ScanMainGUI", "3", Q_NULLPTR));
        teethNoLabel3->setText(QApplication::translate("ScanMainGUI", "15", Q_NULLPTR));
        teethNoLabel2->setText(QApplication::translate("ScanMainGUI", "14", Q_NULLPTR));
        label_14->setText(QApplication::translate("ScanMainGUI", "2", Q_NULLPTR));
        label_15->setText(QApplication::translate("ScanMainGUI", "1", Q_NULLPTR));
        teethNoLabel1->setText(QApplication::translate("ScanMainGUI", "13", Q_NULLPTR));
        teethNoLabel8->setText(QApplication::translate("ScanMainGUI", "20", Q_NULLPTR));
        label_18->setText(QApplication::translate("ScanMainGUI", "8", Q_NULLPTR));
        label_19->setText(QApplication::translate("ScanMainGUI", "6", Q_NULLPTR));
        teethNoLabel6->setText(QApplication::translate("ScanMainGUI", "18", Q_NULLPTR));
        label_21->setText(QApplication::translate("ScanMainGUI", "7", Q_NULLPTR));
        teethNoLabel7->setText(QApplication::translate("ScanMainGUI", "19", Q_NULLPTR));
        TeethStitchingPanel->setTitle(QString());
        CutJawFinishPanelTips_8->setText(QApplication::translate("ScanMainGUI", "\345\217\214\345\207\273\350\216\267\345\217\2263\347\273\204\345\257\271\345\272\224\347\202\271", Q_NULLPTR));
        stitchingFNextBtn_2->setText(QApplication::translate("ScanMainGUI", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        CutJawFinishPanelBackBtn_8->setText(QApplication::translate("ScanMainGUI", "\345\220\216\351\200\200", Q_NULLPTR));
        StitchingPanelTips_4->setText(QApplication::translate("ScanMainGUI", "\346\211\213\345\212\250\346\213\274\346\216\245", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ScanMainGUI: public Ui_ScanMainGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANMAINGUI_H
