#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Ui::Dialog *ui;
    unsigned char *data;
    unsigned char *dataNew;
    int select;
    int width;
    int height;
    int bands;
    int actual;
    QLabel *label;

public slots:
    void setText(char *text, int num);
    void graphFunc(QLabel *label);
    void setParams(unsigned char *data,int w,int h, int b, int selector);

private slots:
    void on_AcceptButton_clicked();

    void on_OBitrateButton_clicked();

    void on_OsizeButton_clicked();

    void on_ABitrateButton_clicked();

    void on_AsizeButton_clicked();

    void on_CompressRatioButton_clicked();

    void on_MSEButton_clicked();

    void on_PSNRButton_clicked();

    void on_nextBand_clicked();

    void on_prevBand_clicked();

    void on_originalButton_clicked();

    void on_newButton_clicked();

};

#endif // DIALOG_H
