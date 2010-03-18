#include "MainWindow.h"

MainWindow::MainWindow() :
    QMainWindow(),
    ui_helper_(new UiHelper(this)),
    template_reader_(new TemplateReader(this))
{
    setupUi(this);
    InitUi();
    ConnectSignals();

    template_reader_->ReadAllTemplates();
}

void MainWindow::InitUi()
{
    exportLocationLineEdit->setText(QApplication::applicationDirPath() + "/configs");
}

void MainWindow::ConnectSignals()
{
    connect(actionExit, SIGNAL(triggered()), SLOT(close()));
    connect(actionAbout, SIGNAL(triggered()), ui_helper_, SLOT(ShowAboutDialog()));
    connect(exportLocationPushButton, SIGNAL(clicked()), ui_helper_, SLOT(DefineExportLocation()));
}
