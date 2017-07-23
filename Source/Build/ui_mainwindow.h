/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *BrowseButton;
    QLineEdit *ImagePath;
    QLabel *label0;
    QPushButton *CompressButton;
    QLabel *label1;
    QLabel *IWidthLabel;
    QLabel *IHeightLabel;
    QLineEdit *IWidthData;
    QLineEdit *IHeightData;
    QLabel *IBandsLabel;
    QLineEdit *IBandsData;
    QLabel *ISizeLabel;
    QLineEdit *ISizeData;
    QLabel *ISignedLabel;
    QLabel *ModeLabel;
    QComboBox *ModeBox;
    QLabel *EndianLabel;
    QLabel *OrganizationLabel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonSigned1;
    QRadioButton *radioButtonSigned2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonLittleEndian;
    QRadioButton *radioButtonBigEndian;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButtonBIP;
    QRadioButton *radioButtonBSQ;
    QPushButton *WidthHelp;
    QPushButton *DataHelp;
    QPushButton *BandsHelp;
    QPushButton *HeightHelp;
    QPushButton *SignedHelp;
    QPushButton *OrganizationHelp;
    QPushButton *EndianHelp;
    QPushButton *ModeHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(434, 437);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        BrowseButton = new QPushButton(centralWidget);
        BrowseButton->setObjectName(QStringLiteral("BrowseButton"));
        BrowseButton->setGeometry(QRect(280, 50, 91, 28));
        ImagePath = new QLineEdit(centralWidget);
        ImagePath->setObjectName(QStringLiteral("ImagePath"));
        ImagePath->setGeometry(QRect(30, 50, 231, 28));
        label0 = new QLabel(centralWidget);
        label0->setObjectName(QStringLiteral("label0"));
        label0->setGeometry(QRect(30, 30, 121, 20));
        CompressButton = new QPushButton(centralWidget);
        CompressButton->setObjectName(QStringLiteral("CompressButton"));
        CompressButton->setGeometry(QRect(160, 380, 81, 28));
        label1 = new QLabel(centralWidget);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(30, 100, 151, 20));
        IWidthLabel = new QLabel(centralWidget);
        IWidthLabel->setObjectName(QStringLiteral("IWidthLabel"));
        IWidthLabel->setGeometry(QRect(50, 130, 101, 21));
        IHeightLabel = new QLabel(centralWidget);
        IHeightLabel->setObjectName(QStringLiteral("IHeightLabel"));
        IHeightLabel->setGeometry(QRect(50, 160, 101, 20));
        IWidthData = new QLineEdit(centralWidget);
        IWidthData->setObjectName(QStringLiteral("IWidthData"));
        IWidthData->setGeometry(QRect(200, 130, 131, 21));
        IHeightData = new QLineEdit(centralWidget);
        IHeightData->setObjectName(QStringLiteral("IHeightData"));
        IHeightData->setGeometry(QRect(200, 160, 131, 21));
        IBandsLabel = new QLabel(centralWidget);
        IBandsLabel->setObjectName(QStringLiteral("IBandsLabel"));
        IBandsLabel->setGeometry(QRect(50, 190, 101, 20));
        IBandsData = new QLineEdit(centralWidget);
        IBandsData->setObjectName(QStringLiteral("IBandsData"));
        IBandsData->setGeometry(QRect(200, 190, 131, 21));
        ISizeLabel = new QLabel(centralWidget);
        ISizeLabel->setObjectName(QStringLiteral("ISizeLabel"));
        ISizeLabel->setGeometry(QRect(50, 220, 101, 20));
        ISizeData = new QLineEdit(centralWidget);
        ISizeData->setObjectName(QStringLiteral("ISizeData"));
        ISizeData->setGeometry(QRect(200, 220, 131, 21));
        ISignedLabel = new QLabel(centralWidget);
        ISignedLabel->setObjectName(QStringLiteral("ISignedLabel"));
        ISignedLabel->setGeometry(QRect(50, 250, 111, 20));
        ModeLabel = new QLabel(centralWidget);
        ModeLabel->setObjectName(QStringLiteral("ModeLabel"));
        ModeLabel->setGeometry(QRect(50, 340, 63, 20));
        ModeBox = new QComboBox(centralWidget);
        ModeBox->setObjectName(QStringLiteral("ModeBox"));
        ModeBox->setGeometry(QRect(200, 340, 131, 21));
        EndianLabel = new QLabel(centralWidget);
        EndianLabel->setObjectName(QStringLiteral("EndianLabel"));
        EndianLabel->setGeometry(QRect(50, 280, 91, 20));
        OrganizationLabel = new QLabel(centralWidget);
        OrganizationLabel->setObjectName(QStringLiteral("OrganizationLabel"));
        OrganizationLabel->setGeometry(QRect(50, 310, 141, 20));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(200, 245, 122, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(4);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        radioButtonSigned1 = new QRadioButton(layoutWidget);
        radioButtonSigned1->setObjectName(QStringLiteral("radioButtonSigned1"));

        horizontalLayout->addWidget(radioButtonSigned1);

        radioButtonSigned2 = new QRadioButton(layoutWidget);
        radioButtonSigned2->setObjectName(QStringLiteral("radioButtonSigned2"));

        horizontalLayout->addWidget(radioButtonSigned2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(200, 277, 131, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButtonLittleEndian = new QRadioButton(layoutWidget1);
        radioButtonLittleEndian->setObjectName(QStringLiteral("radioButtonLittleEndian"));

        horizontalLayout_2->addWidget(radioButtonLittleEndian);

        radioButtonBigEndian = new QRadioButton(layoutWidget1);
        radioButtonBigEndian->setObjectName(QStringLiteral("radioButtonBigEndian"));

        horizontalLayout_2->addWidget(radioButtonBigEndian);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(200, 307, 134, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        radioButtonBIP = new QRadioButton(layoutWidget2);
        radioButtonBIP->setObjectName(QStringLiteral("radioButtonBIP"));

        horizontalLayout_3->addWidget(radioButtonBIP);

        radioButtonBSQ = new QRadioButton(layoutWidget2);
        radioButtonBSQ->setObjectName(QStringLiteral("radioButtonBSQ"));

        horizontalLayout_3->addWidget(radioButtonBSQ);

        WidthHelp = new QPushButton(centralWidget);
        WidthHelp->setObjectName(QStringLiteral("WidthHelp"));
        WidthHelp->setGeometry(QRect(350, 130, 21, 21));
        DataHelp = new QPushButton(centralWidget);
        DataHelp->setObjectName(QStringLiteral("DataHelp"));
        DataHelp->setGeometry(QRect(350, 220, 21, 21));
        BandsHelp = new QPushButton(centralWidget);
        BandsHelp->setObjectName(QStringLiteral("BandsHelp"));
        BandsHelp->setGeometry(QRect(350, 190, 21, 21));
        HeightHelp = new QPushButton(centralWidget);
        HeightHelp->setObjectName(QStringLiteral("HeightHelp"));
        HeightHelp->setGeometry(QRect(350, 160, 21, 21));
        SignedHelp = new QPushButton(centralWidget);
        SignedHelp->setObjectName(QStringLiteral("SignedHelp"));
        SignedHelp->setGeometry(QRect(350, 250, 21, 21));
        OrganizationHelp = new QPushButton(centralWidget);
        OrganizationHelp->setObjectName(QStringLiteral("OrganizationHelp"));
        OrganizationHelp->setGeometry(QRect(350, 310, 21, 21));
        EndianHelp = new QPushButton(centralWidget);
        EndianHelp->setObjectName(QStringLiteral("EndianHelp"));
        EndianHelp->setGeometry(QRect(350, 280, 21, 21));
        ModeHelp = new QPushButton(centralWidget);
        ModeHelp->setObjectName(QStringLiteral("ModeHelp"));
        ModeHelp->setGeometry(QRect(350, 340, 21, 21));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        BrowseButton->setText(QApplication::translate("MainWindow", "Browse", Q_NULLPTR));
        label0->setText(QApplication::translate("MainWindow", "Input RAW Image", Q_NULLPTR));
        CompressButton->setText(QApplication::translate("MainWindow", "Compress!", Q_NULLPTR));
        label1->setText(QApplication::translate("MainWindow", "Image Characteristics", Q_NULLPTR));
        IWidthLabel->setText(QApplication::translate("MainWindow", "- Width", Q_NULLPTR));
        IHeightLabel->setText(QApplication::translate("MainWindow", "- Height", Q_NULLPTR));
        IBandsLabel->setText(QApplication::translate("MainWindow", "- Bands", Q_NULLPTR));
        ISizeLabel->setText(QApplication::translate("MainWindow", "- Data Size", Q_NULLPTR));
        ISignedLabel->setText(QApplication::translate("MainWindow", "- Signed Data", Q_NULLPTR));
        ModeLabel->setText(QApplication::translate("MainWindow", "- Mode", Q_NULLPTR));
        EndianLabel->setText(QApplication::translate("MainWindow", "- Endianness", Q_NULLPTR));
        OrganizationLabel->setText(QApplication::translate("MainWindow", "- Image Organization", Q_NULLPTR));
        radioButtonSigned1->setText(QApplication::translate("MainWindow", "Yes     ", Q_NULLPTR));
        radioButtonSigned2->setText(QApplication::translate("MainWindow", "No", Q_NULLPTR));
        radioButtonLittleEndian->setText(QApplication::translate("MainWindow", "Little  ", Q_NULLPTR));
        radioButtonBigEndian->setText(QApplication::translate("MainWindow", "Big", Q_NULLPTR));
        radioButtonBIP->setText(QApplication::translate("MainWindow", "BIP     ", Q_NULLPTR));
        radioButtonBSQ->setText(QApplication::translate("MainWindow", "BSQ", Q_NULLPTR));
        WidthHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
        DataHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
        BandsHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
        HeightHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
        SignedHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
        OrganizationHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
        EndianHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
        ModeHelp->setText(QApplication::translate("MainWindow", "i", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
