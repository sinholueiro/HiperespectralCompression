#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qfiledialog.h>
#include <qmessagebox.h>
#include <unistd.h>
#include <pwd.h>
#include <iostream>
#include <QGroupBox>
#include <QProcess>
#include <stdio.h>

#include "normalize.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow){
        ui->setupUi(this);
        ui->radioButtonSigned1->setChecked(true);
        ui->radioButtonLittleEndian->setChecked(true);
        ui->radioButtonBIP->setChecked(true);
        ui->ModeBox->addItem("2D Singlebands");
        ui->ModeBox->addItem("2D Multiband");
        ui->ModeBox->addItem("3D Volume");
    }

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_BrowseButton_clicked(){
    struct passwd *usuario;
    uid_t numero=getuid();
    usuario = getpwuid(numero);
    string path = usuario->pw_name;
    path = "/home/" + path;
    const char *ruta = path.c_str();

    QString filename = NULL;
    filename = QFileDialog::getOpenFileName(this,tr("Seleccionar Imagen"),ruta,"All (*.*)");

    if(filename==NULL){
        QMessageBox::information(this,"Error","No image selected.");
    }else{
        this->ui->ImagePath->setText(filename);
    }
}

void MainWindow::on_CompressButton_clicked()
{
    int width=-1;
    int height=-1;
    int bands=-1;
    int size=-1;
    int dataSigned=-1;
    int endianness=-1;
    int bip2bsq=-1;
    int mode=-1;
    QString input=NULL;
    QString output=NULL;

    //Comprobar texto
    if(this->ui->ImagePath->text() == NULL){
        QMessageBox::information(this,"Error","No image selected.");
    }else{
        input=this->ui->ImagePath->text();
    }

    //Comprobar ancho
    if(input==NULL){
    }
    else if(this->ui->IWidthData->text() == NULL){
        QMessageBox::information(this,"Error","The width has not been set.");
    }else{
        char *p;
        char *num;
        QByteArray ba = this->ui->IWidthData->text().toLatin1();
        num=ba.data();
        width=strtol(num,&p,10);
        if (*p != 0){
            width=-1;
            QMessageBox::information(this,"Error","The width has to be a number.");
        }
    }

    //Comprobar alto
    if(width==-1){
    }else if(this->ui->IHeightData->text() == NULL){
        QMessageBox::information(this,"Error","The height has not been set.");
    }else{
        char *p;
        char *num;
        QByteArray ba = this->ui->IHeightData->text().toLatin1();
        num=ba.data();
        height=strtol(num,&p,10);
        if (*p != 0){
            height=-1;
            QMessageBox::information(this,"Error","The height has to be a number.");
        }
    }

    //Comprobar bandas
    if(height==-1){
    }else if(this->ui->IBandsData->text() == NULL){
        QMessageBox::information(this,"Error","The bands have not been set.");
    }else{
        char *p;
        char *num;
        QByteArray ba = this->ui->IBandsData->text().toLatin1();
        num=ba.data();
        bands=strtol(num,&p,10);
        if (*p != 0){
            bands=-1;
            QMessageBox::information(this,"Error","The bands have to be a number.");
        }
    }

    //Comprobar tamaño
    if(bands==-1){
    }else if(this->ui->ISizeData->text() == NULL){
        QMessageBox::information(this,"Error","The pixel size has not been set.");
    }else{
        char *p;
        char *num;
        QByteArray ba = this->ui->ISizeData->text().toLatin1();
        num=ba.data();
        size=strtol(num,&p,10);
        if (*p != 0){
            size=-1;
            QMessageBox::information(this,"Error","The pixel size has to be a number.");
        }
    }

    //Comprobar signo
    if(size==-1){
    }else if(this->ui->radioButtonSigned1->isChecked()){
        dataSigned=1;
    }else{
        dataSigned=0;
    }

    //Comprobar endianness
    if(size==-1){
    }else if(this->ui->radioButtonLittleEndian->isChecked()){
        endianness=1;
    }else{
        endianness=0;
    }

    //Comprobar transformación
    if(size==-1){
    }else if(this->ui->radioButtonBIP->isChecked()){
        bip2bsq=0;
    }else{
        bip2bsq=1;
    }

    //Comprobar modo
    if(size==-1){
    }else if(this->ui->ModeBox->currentIndex()==0){
        mode=1;
        output=this->ui->ImagePath->text()+".jp2";
    }else if(this->ui->ModeBox->currentIndex()==1){
        mode=2;
        output=this->ui->ImagePath->text()+".jp2";
    }else if(this->ui->ModeBox->currentIndex()==2){
        mode=3;
        output=this->ui->ImagePath->text()+".jp3d";
    }

    //Ejecutar compresión
    if(size==-1){
    }else{
        this->ui->CompressButton->setText("Wait!");
        this->ui->CompressButton->setEnabled(false);
        dialogo = new Dialog();

        //Execute the compression program
        QString program = "./build/ImageCompressionMerge "+input+" "+output+" "+
                QString::number(width)+" "+QString::number(height)+" "+QString::number(bands)+" "+QString::number(size)+" "+
                QString::number(dataSigned)+" "+QString::number(mode)+" "+QString::number(endianness)+" "+QString::number(bip2bsq);
        process = new QProcess();
        process->start(program);
        process->waitForFinished(-1);

        QString outputProgram = process->readAllStandardOutput();
        char *worker = new char[outputProgram.toStdString().length() + 1];
        strcpy(worker, outputProgram.toStdString().c_str());

        char *result;
        result = strtok(worker,"\n");

        for(int i=1;i<8;i++){
            dialogo->setText(result,i);
            result = strtok(NULL,"\n");
        }

        //Read original image from source
        FILE *fp;
        fp = fopen(input.toStdString().c_str(),"r");

        unsigned char *imageData;
        imageData = (unsigned char *)malloc(sizeof(unsigned char)*width*height*bands);
        readImage(fp,imageData,width,height,bands,dataSigned,endianness,bip2bsq);
        fclose(fp);

        dialogo->setParams(imageData,width,height,bands,1);

        if(mode==2){
            //Read new image from source
            QString compressName = input + ".jp2.raw";

            FILE *fp2;
            fp2 = fopen(compressName.toStdString().c_str(),"r");

            unsigned char *imageData2;
            imageData2 = (unsigned char *)malloc(sizeof(unsigned char)*width*height*bands);
            readImage(fp2,imageData2,width,height,bands,dataSigned,1,1);
            fclose(fp2);

            dialogo->setParams(imageData2,width,height,bands,2);
        }

        //Show image
        QImage image(imageData,width,height,QImage::Format_Indexed8);
        QLabel *myLabel = new QLabel(this);
        myLabel->setPixmap(QPixmap::fromImage(image));
        myLabel->setScaledContents(true);
        myLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

        dialogo->graphFunc(myLabel);
        dialogo->show();

        this->ui->CompressButton->setText("Compress!");
        this->ui->CompressButton->setEnabled(true);
    }
}

void MainWindow::on_WidthHelp_clicked(){
    QMessageBox::information(this,"Help","Integer that tells the image width.");
}

void MainWindow::on_HeightHelp_clicked(){
    QMessageBox::information(this,"Help","Integer that tells the image height.");
}

void MainWindow::on_BandsHelp_clicked(){
    QMessageBox::information(this,"Help","Integer that tells the image bands.");
}

void MainWindow::on_DataHelp_clicked(){
    QMessageBox::information(this,"Help","Integer that tells the pixel size.");
}

void MainWindow::on_SignedHelp_clicked(){
    QMessageBox::information(this,"Help","Choose if the data is signed or not.");
}

void MainWindow::on_EndianHelp_clicked(){
    QMessageBox::information(this,"Help","Indicate if the data is LittleEndian or BigEndian.");
}

void MainWindow::on_OrganizationHelp_clicked(){
    QMessageBox::information(this,"Help","Indicate the internal image data structure: BIP(the data is divided in arrays that have the data of all band of a determined position) option reorder the data to BSQ (the data is divided in bands).");
}

void MainWindow::on_ModeHelp_clicked(){
   QMessageBox::information(this,"Help","Encoder mode. 2D Singlebands encodes bands one by one. 2D Multiband encodes all the bands as a whole. 3D Volume enconde the image as a tri-dimensional volume.");
}
