#ifndef CONFIGCONTENT_H
#define CONFIGCONTENT_H

#include <QObject>
#include <QStringList>
#include <QWidget>

enum ConfigType
{
    Unknown,
    OpenSim,
    Region,
    Modrex,
    Robust,
    User,
    Messaging
};

class ConfigContent : public QObject
{

Q_OBJECT

public:
    ConfigContent(QObject *parent, QString config_name, QStringList tags_to_process);

public slots:
    QWidget *GetContentWidget()     { return content_widget_; }
    ConfigType GetType()            { return type_; }

private slots:
    void DetermineType(QString name);

private:
    QWidget *content_widget_;
    QString config_name_;
    QStringList tags_to_process_;
    ConfigType type_;

};

#endif // CONFIGCONTENT_H
