#include "TemplateReader.h"

#include <QFile>
#include <QDebug>

TemplateReader::TemplateReader(QObject *parent) :
    QObject(parent),
    template_location_("./templates/")
{
    template_files_ << template_location_ + "OpenSim.ini"
                    << template_location_ + "Opensim.Server.ini"
                    << template_location_ + "Regions/Regions.ini"
                    << template_location_ + "MessagingServer_Config.xml"
                    << template_location_ + "UserServer_Config.xml"
                    << template_location_ + "addon-modules/ModreX/config/modrex.ini";
}

void TemplateReader::ReadAllTemplates()
{
    QString TAG_START  = "${",
            TAG_FINISH = "}$";

    foreach (QString filename, template_files_)
    {
        QFile *file = OpenFile(filename);
        if (!file)
            continue;
        QByteArray content = file->readAll();
        file->close();

        QStringList found_tags;
        int index_start = 0;
        int index_finish = 0;

        while (true)
        {
            index_start = content.indexOf(TAG_START, index_start);
            index_finish = content.indexOf(TAG_FINISH, index_start + TAG_START.length());

            if (index_start != -1 && index_finish != -1)
            {
                index_start += TAG_START.length();
                index_finish -= index_start;
                found_tags.append(content.mid(index_start, index_finish));
            }
            else
                break;
        }

        configs_.append(new ConfigContent(this, filename, found_tags));
    }
}

QFile *TemplateReader::OpenFile(QString filename)
{
    QFile *file = new QFile(filename);
    if (!file->exists())
        return 0;
    if (!file->open(QIODevice::ReadOnly|QIODevice::Text))
        return 0;
    return file;
}
