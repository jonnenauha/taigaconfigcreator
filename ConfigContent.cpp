#include "ConfigContent.h"

#include <QDebug>

ConfigContent::ConfigContent(QObject *parent, QString config_name, QStringList tags_to_process) :
    QObject(parent),
    content_widget_(new QWidget()),
    config_name_(config_name),
    tags_to_process_(tags_to_process),
    type_(Unknown)
{
    DetermineType(config_name);
}

void ConfigContent::DetermineType(QString name)
{
    if (name.endsWith("OpenSim.ini"))
       type_ = OpenSim;
    else if (name.endsWith("Opensim.Server.ini"))
        type_ = Robust;
    else if (name.endsWith("Regions.ini"))
        type_ = Region;
    else if (name.endsWith("MessagingServer_Config.xml"))
        type_ = Messaging;
    else if (name.endsWith("UserServer_Config.xml"))
        type_ = User;
    else if (name.endsWith("modrex.ini"))
        type_ = Modrex;
}
