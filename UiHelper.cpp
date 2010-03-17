#include "UiHelper.h"
#include "MainWindow.h"

UiHelper::UiHelper(MainWindow *main_window) :
    QObject(main_window),
    main_window_(main_window)
{
}

void UiHelper::ShowAboutDialog()
{
    QMessageBox::about(main_window_, "About", "Taiga Config Creator by Jonne Nauha\n\nContact: jonne.nauha@evocativi.com and #realxtend-dev @ freenode"
                       "\nWebsites: http://www.realxtend.org / http://wiki.realxtend.org");
}

void UiHelper::DefineExportLocation()
{
    QString location = QFileDialog::getExistingDirectory(main_window_, "Export location", main_window_->exportLocationLineEdit->text());
    if (!location.isEmpty() && !location.isNull())
        main_window_->exportLocationLineEdit->setText(location);
}
