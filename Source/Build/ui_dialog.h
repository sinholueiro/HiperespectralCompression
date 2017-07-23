/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *TitleResults;
    QLabel *OriginalSizeLabel;
    QLabel *OriginalBitrateLabel;
    QLabel *ActualSizeLabel;
    QLabel *ActualBitrateLabel;
    QLabel *CompressionRatioLabel;
    QLabel *MSRLabel;
    QLabel *PSNRLabel;
    QPushButton *AcceptButton;
    QLineEdit *OriginalSizeText;
    QLineEdit *OriginalBitrateText;
    QLineEdit *ActualSizeText;
    QLineEdit *ActualBitrateText;
    QLineEdit *CompressionRatioText;
    QLineEdit *MSEText;
    QLineEdit *PSNRText;
    QPushButton *OsizeButton;
    QPushButton *OBitrateButton;
    QPushButton *AsizeButton;
    QPushButton *ABitrateButton;
    QPushButton *CompressRatioButton;
    QPushButton *MSEButton;
    QPushButton *PSNRButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *nextBand;
    QPushButton *prevBand;
    QLabel *bandNumber;
    QPushButton *originalButton;
    QPushButton *newButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(711, 292);
        TitleResults = new QLabel(Dialog);
        TitleResults->setObjectName(QStringLiteral("TitleResults"));
        TitleResults->setGeometry(QRect(30, 10, 63, 20));
        OriginalSizeLabel = new QLabel(Dialog);
        OriginalSizeLabel->setObjectName(QStringLiteral("OriginalSizeLabel"));
        OriginalSizeLabel->setGeometry(QRect(40, 40, 151, 20));
        OriginalBitrateLabel = new QLabel(Dialog);
        OriginalBitrateLabel->setObjectName(QStringLiteral("OriginalBitrateLabel"));
        OriginalBitrateLabel->setGeometry(QRect(40, 70, 151, 20));
        ActualSizeLabel = new QLabel(Dialog);
        ActualSizeLabel->setObjectName(QStringLiteral("ActualSizeLabel"));
        ActualSizeLabel->setGeometry(QRect(40, 100, 151, 20));
        ActualBitrateLabel = new QLabel(Dialog);
        ActualBitrateLabel->setObjectName(QStringLiteral("ActualBitrateLabel"));
        ActualBitrateLabel->setGeometry(QRect(40, 130, 151, 20));
        CompressionRatioLabel = new QLabel(Dialog);
        CompressionRatioLabel->setObjectName(QStringLiteral("CompressionRatioLabel"));
        CompressionRatioLabel->setGeometry(QRect(40, 160, 141, 20));
        MSRLabel = new QLabel(Dialog);
        MSRLabel->setObjectName(QStringLiteral("MSRLabel"));
        MSRLabel->setGeometry(QRect(40, 190, 141, 20));
        PSNRLabel = new QLabel(Dialog);
        PSNRLabel->setObjectName(QStringLiteral("PSNRLabel"));
        PSNRLabel->setGeometry(QRect(40, 220, 181, 20));
        AcceptButton = new QPushButton(Dialog);
        AcceptButton->setObjectName(QStringLiteral("AcceptButton"));
        AcceptButton->setGeometry(QRect(180, 250, 84, 28));
        OriginalSizeText = new QLineEdit(Dialog);
        OriginalSizeText->setObjectName(QStringLiteral("OriginalSizeText"));
        OriginalSizeText->setGeometry(QRect(270, 40, 113, 21));
        OriginalBitrateText = new QLineEdit(Dialog);
        OriginalBitrateText->setObjectName(QStringLiteral("OriginalBitrateText"));
        OriginalBitrateText->setGeometry(QRect(270, 70, 113, 21));
        ActualSizeText = new QLineEdit(Dialog);
        ActualSizeText->setObjectName(QStringLiteral("ActualSizeText"));
        ActualSizeText->setGeometry(QRect(270, 100, 113, 21));
        ActualBitrateText = new QLineEdit(Dialog);
        ActualBitrateText->setObjectName(QStringLiteral("ActualBitrateText"));
        ActualBitrateText->setGeometry(QRect(270, 130, 113, 21));
        CompressionRatioText = new QLineEdit(Dialog);
        CompressionRatioText->setObjectName(QStringLiteral("CompressionRatioText"));
        CompressionRatioText->setGeometry(QRect(270, 160, 113, 21));
        MSEText = new QLineEdit(Dialog);
        MSEText->setObjectName(QStringLiteral("MSEText"));
        MSEText->setGeometry(QRect(270, 190, 113, 21));
        PSNRText = new QLineEdit(Dialog);
        PSNRText->setObjectName(QStringLiteral("PSNRText"));
        PSNRText->setGeometry(QRect(270, 220, 113, 21));
        OsizeButton = new QPushButton(Dialog);
        OsizeButton->setObjectName(QStringLiteral("OsizeButton"));
        OsizeButton->setGeometry(QRect(400, 40, 21, 21));
        OBitrateButton = new QPushButton(Dialog);
        OBitrateButton->setObjectName(QStringLiteral("OBitrateButton"));
        OBitrateButton->setGeometry(QRect(400, 70, 21, 21));
        AsizeButton = new QPushButton(Dialog);
        AsizeButton->setObjectName(QStringLiteral("AsizeButton"));
        AsizeButton->setGeometry(QRect(400, 100, 21, 21));
        ABitrateButton = new QPushButton(Dialog);
        ABitrateButton->setObjectName(QStringLiteral("ABitrateButton"));
        ABitrateButton->setGeometry(QRect(400, 130, 21, 21));
        CompressRatioButton = new QPushButton(Dialog);
        CompressRatioButton->setObjectName(QStringLiteral("CompressRatioButton"));
        CompressRatioButton->setGeometry(QRect(400, 160, 21, 21));
        MSEButton = new QPushButton(Dialog);
        MSEButton->setObjectName(QStringLiteral("MSEButton"));
        MSEButton->setGeometry(QRect(400, 190, 21, 21));
        PSNRButton = new QPushButton(Dialog);
        PSNRButton->setObjectName(QStringLiteral("PSNRButton"));
        PSNRButton->setGeometry(QRect(400, 220, 21, 21));
        scrollArea = new QScrollArea(Dialog);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(440, 50, 241, 191));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 239, 189));
        scrollArea->setWidget(scrollAreaWidgetContents);
        nextBand = new QPushButton(Dialog);
        nextBand->setObjectName(QStringLiteral("nextBand"));
        nextBand->setGeometry(QRect(600, 250, 84, 28));
        prevBand = new QPushButton(Dialog);
        prevBand->setObjectName(QStringLiteral("prevBand"));
        prevBand->setGeometry(QRect(440, 250, 81, 28));
        bandNumber = new QLabel(Dialog);
        bandNumber->setObjectName(QStringLiteral("bandNumber"));
        bandNumber->setGeometry(QRect(540, 250, 41, 31));
        originalButton = new QPushButton(Dialog);
        originalButton->setObjectName(QStringLiteral("originalButton"));
        originalButton->setGeometry(QRect(440, 10, 84, 28));
        newButton = new QPushButton(Dialog);
        newButton->setObjectName(QStringLiteral("newButton"));
        newButton->setGeometry(QRect(600, 10, 84, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        TitleResults->setText(QApplication::translate("Dialog", "Metrics:", Q_NULLPTR));
        OriginalSizeLabel->setText(QApplication::translate("Dialog", "- Original Image Size", Q_NULLPTR));
        OriginalBitrateLabel->setText(QApplication::translate("Dialog", "- Original Bitrate", Q_NULLPTR));
        ActualSizeLabel->setText(QApplication::translate("Dialog", "- Actual Image Size", Q_NULLPTR));
        ActualBitrateLabel->setText(QApplication::translate("Dialog", "- Actual Bitrate", Q_NULLPTR));
        CompressionRatioLabel->setText(QApplication::translate("Dialog", "-Compression Ratio", Q_NULLPTR));
        MSRLabel->setText(QApplication::translate("Dialog", "-MeanSquaredError", Q_NULLPTR));
        PSNRLabel->setText(QApplication::translate("Dialog", "-PeakSignal-to-NoiseRatio", Q_NULLPTR));
        AcceptButton->setText(QApplication::translate("Dialog", "Ok", Q_NULLPTR));
        OsizeButton->setText(QApplication::translate("Dialog", "i", Q_NULLPTR));
        OBitrateButton->setText(QApplication::translate("Dialog", "i", Q_NULLPTR));
        AsizeButton->setText(QApplication::translate("Dialog", "i", Q_NULLPTR));
        ABitrateButton->setText(QApplication::translate("Dialog", "i", Q_NULLPTR));
        CompressRatioButton->setText(QApplication::translate("Dialog", "i", Q_NULLPTR));
        MSEButton->setText(QApplication::translate("Dialog", "i", Q_NULLPTR));
        PSNRButton->setText(QApplication::translate("Dialog", "i", Q_NULLPTR));
        nextBand->setText(QApplication::translate("Dialog", "Next Band", Q_NULLPTR));
        prevBand->setText(QApplication::translate("Dialog", "Prev Band", Q_NULLPTR));
        bandNumber->setText(QApplication::translate("Dialog", "0", Q_NULLPTR));
        originalButton->setText(QApplication::translate("Dialog", "Original", Q_NULLPTR));
        newButton->setText(QApplication::translate("Dialog", "Decomp.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
