#ifndef UIHELPER_H
#define UIHELPER_H

#include <QMessageBox>
#include <QFileDialog>

class MainWindow;

class UiHelper : public QObject
{

Q_OBJECT

public:
    UiHelper(MainWindow *main_window);

public slots:
    void ShowAboutDialog();
    void DefineExportLocation();

private:
    MainWindow *main_window_;

};

#endif // UIHELPER_H
