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
    foreach (QString template_filename, template_files_)
    {
        qDebug() << "Parsing file: " << template_filename;

        // Open the file
        QFile template_file(template_filename);
        if (!template_file.exists())
            continue;
        if (!template_file.open(QIODevice::ReadOnly|QIODevice::Text))
            continue;

        // Loop for tags and store them
        QByteArray file_content = template_file.readAll();
        int tag_start = -2;
        int tag_end = 0;
        while (true)
        {
            tag_start = file_content.indexOf("${", tag_start+2);
            tag_end = file_content.indexOf("}$", tag_start+2);

            if (tag_start == -1 || tag_end == -1)
                break;

            qDebug() << "   " << file_content.mid(tag_start+2, tag_end-tag_start-2);
        }

        // Create qwidget with data and StoreWidgetToMap(template_filename, widget)
        qDebug() << endl;
    }
}

void TemplateReader::StoreWidgetToMap(QString template_name, QWidget *tab_widget)
{
    QString tab_name = "";
    if (template_name.endsWith("OpenSim.ini"))
       tab_name = "opensim";
    else if (template_name.endsWith("Opensim.Server.ini"))
        tab_name = "robust";
    else if (template_name.endsWith("Regions.ini"))
        tab_name = "region";
    else if (template_name.endsWith("MessagingServer_Config.xml"))
        tab_name = "messaging";
    else if (template_name.endsWith("UserServer_Config.xml"))
        tab_name = "user";
    else if (template_name.endsWith("modrex.ini"))
        tab_name = "modrex";
    if (!tab_name.isEmpty())
         tab_to_widget_map_[tab_name] = tab_widget;
}
