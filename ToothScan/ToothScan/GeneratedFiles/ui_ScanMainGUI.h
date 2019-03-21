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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
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
    } // retranslateUi

};

namespace Ui {
    class ScanMainGUI: public Ui_ScanMainGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANMAINGUI_H
