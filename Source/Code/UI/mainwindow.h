#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include "dialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_BrowseButton_clicked();
    void on_CompressButton_clicked();

    void on_WidthHelp_clicked();

    void on_HeightHelp_clicked();

    void on_BandsHelp_clicked();

    void on_DataHelp_clicked();

    void on_SignedHelp_clicked();

    void on_EndianHelp_clicked();

    void on_OrganizationHelp_clicked();

    void on_ModeHelp_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialogo;
    QProcess *process;
};

#endif // MAINWINDOW_H
