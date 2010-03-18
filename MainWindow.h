#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "UiHelper.h"
#include "TemplateReader.h"

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{

Q_OBJECT

public:
    MainWindow();

private slots:
    void InitUi();
    void ConnectSignals();

private:
    UiHelper *ui_helper_;
    TemplateReader *template_reader_;

};

#endif // MAINWINDOW_H
