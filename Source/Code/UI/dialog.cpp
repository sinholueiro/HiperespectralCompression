#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QWindow>
#include <cstdlib>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->OriginalSizeText->setReadOnly(true);
    ui->OriginalBitrateText->setReadOnly(true);
    ui->ActualSizeText->setReadOnly(true);
    ui->ActualBitrateText->setReadOnly(true);
    ui->CompressionRatioText->setReadOnly(true);
    ui->MSEText->setReadOnly(true);
    ui->PSNRText->setReadOnly(true);
    ui->prevBand->setEnabled(false);
    ui->originalButton->setEnabled(false);
    ui->newButton->setEnabled(true);
    select=1;
    ui->bandNumber->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    this->setWindowTitle("Performance Evalutaion Metrics");
    ui->originalButton->setEnabled(false);
    ui->newButton->setEnabled(false);
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::on_AcceptButton_clicked(){
    delete this;
}

void Dialog::on_OsizeButton_clicked(){
    QMessageBox::information(this,"Help","Input image size in bytes.");
}

void Dialog::on_OBitrateButton_clicked(){
    QMessageBox::information(this,"Help","Input's pixel size in bits.");
}

void Dialog::on_AsizeButton_clicked(){
    QMessageBox::information(this,"Help","Output image size in bytes.");
}

void Dialog::on_ABitrateButton_clicked(){
    QMessageBox::information(this,"Help","Output's pixel size in bits.");
}

void Dialog::on_CompressRatioButton_clicked(){
    QMessageBox::information(this,"Help","Cefficient between the input image size and the output image size.");
}

void Dialog::on_MSEButton_clicked(){
    QMessageBox::information(this,"Help","Average of the squares of the errors.");
}

void Dialog::on_PSNRButton_clicked(){
    QMessageBox::information(this,"Help","Ratio between the original value of a signal and the actal value of a corrupting signal.");
}

void Dialog::setText(char *text,int num){
    switch (num){
        case 1:
            this->ui->OriginalSizeText->setText(text);
            break;
        case 2:
            this->ui->OriginalBitrateText->setText(text);
            break;
        case 3:
            this->ui->ActualSizeText->setText(text);
            break;
        case 4:
            this->ui->ActualBitrateText->setText(text);
            break;
        case 5:
            this->ui->CompressionRatioText->setText(text);
            break;
        case 6:
            this->ui->MSEText->setText(text);
            break;
        case 7:
            this->ui->PSNRText->setText(text);
            break;
    }
}

void Dialog::graphFunc(QLabel *label){
    this->label=label;
    this->ui->scrollArea->setWidget(label);
}

void Dialog::setParams(unsigned char *imageData,int w,int h, int b, int selector){
    if(selector==1){
        this->data = new unsigned char[(w*h*b)];
        this->data = imageData;
        this->width=w;
        this->height=h;
        this->bands=b;
        this->actual=0;
    }else{
        this->dataNew = new unsigned char[(w*h*b)];
        this->dataNew = imageData;
        this->ui->newButton->setEnabled(true);
    }
}

void Dialog::on_nextBand_clicked()
{
    if(actual<(bands-1)){
        actual = actual+1;
        unsigned char *newData;
        newData=(unsigned char*)malloc(sizeof(unsigned char)*width*height);

        for(int i=0;i<width*height;i++){
            if(select==1){
                newData[i]=data[i + actual*width*height];
            }else{
                newData[i]=dataNew[i + actual*width*height];
            }
        }
        QImage image(newData,width,height,QImage::Format_Indexed8);
        label->setPixmap(QPixmap::fromImage(image));
        this->ui->prevBand->setEnabled(true);
        this->ui->bandNumber->setText(QString::number(actual));
    }
    if(actual==bands-1){
        this->ui->nextBand->setEnabled(false);
    }
}

void Dialog::on_prevBand_clicked()
{
    if(actual>0){
        actual=actual-1;
        unsigned char *newData;
        newData=(unsigned char*)malloc(sizeof(unsigned char)*width*height);

        for(int i=0;i<width*height;i++){
            if(select==1){
                newData[i]=data[i + actual*width*height];
            }else{
                newData[i]=dataNew[i + actual*width*height];
            }
        }
        QImage image(newData,width,height,QImage::Format_Indexed8);
        label->setPixmap(QPixmap::fromImage(image));
        this->ui->nextBand->setEnabled(true);
        this->ui->bandNumber->setText(QString::number(actual));
    }
    if(actual==0){
        this->ui->prevBand->setEnabled(false);
    }
}

void Dialog::on_originalButton_clicked()
{
    this->select=1;
    this->actual=0;
    this->ui->prevBand->setEnabled(false);
    this->ui->nextBand->setEnabled(true);

    QImage image(data,width,height,QImage::Format_Indexed8);
    label->setPixmap(QPixmap::fromImage(image));
    this->ui->bandNumber->setText(QString::number(0));
    this->ui->originalButton->setEnabled(false);
    this->ui->newButton->setEnabled(true);
}

void Dialog::on_newButton_clicked()
{
    this->select=2;
    this->actual=0;
    this->ui->prevBand->setEnabled(false);
    this->ui->nextBand->setEnabled(true);

    QImage image(dataNew,width,height,QImage::Format_Indexed8);
    label->setPixmap(QPixmap::fromImage(image));
    this->ui->bandNumber->setText(QString::number(0));
    this->ui->originalButton->setEnabled(true);
    this->ui->newButton->setEnabled(false);
}
