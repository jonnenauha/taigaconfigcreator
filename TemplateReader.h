#ifndef TEMPLATEREADER_H
#define TEMPLATEREADER_H

#include "ConfigContent.h"

#include <QObject>
#include <QStringList>
#include <QMap>
#include <QWidget>
#include <QFile>

class TemplateReader : public QObject
{

Q_OBJECT

public:
    TemplateReader(QObject *parent);

public slots:
    void ReadAllTemplates();

private slots:
    QFile *OpenFile(QString filename);

private:
    QString template_location_;
    QStringList template_files_;
    QList<ConfigContent *> configs_;
};

#endif // TEMPLATEREADER_H
