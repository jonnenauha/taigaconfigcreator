#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{

Q_OBJECT

public:
    explicit MainWindow();

};

#endif // MAINWINDOW_H
