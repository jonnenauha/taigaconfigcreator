#ifndef TEMPLATEREADER_H
#define TEMPLATEREADER_H

#include <QObject>
#include <QStringList>
#include <QMap>
#include <QWidget>

class TemplateReader : public QObject
{

Q_OBJECT

public:
    TemplateReader(QObject *parent);

public slots:
    void ReadAllTemplates();

private slots:
    void StoreWidgetToMap(QString template_name, QWidget *tab_widget);

private:
    QString template_location_;
    QStringList template_files_;

    QMap<QString, QWidget*> tab_to_widget_map_;
};

#endif // TEMPLATEREADER_H
