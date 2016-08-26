#ifndef OBJECT_MANAGEMENT_H
#define OBJECT_MANAGEMENT_H

#include <QFile>
#include <QDir>
#include <QString>
#include <string>
#include <unistd.h>
#include <Shape_configuration.h>
#include <vector>
#include <sstream>
#include <QDebug>

#include <QtXml/qdom.h>
#include <QtXml/QtXml>
#include <QtXml/QXmlReader>
#include <QtXml/QDomDocument>
#include <QtXml/QDomNodeList>
#include <QtXml/QDomNode>
#include <QTreeWidgetItem>

#endif // OBJECT_MANAGEMENT_H


class Object_management
{

public:

    ~Object_management();
    void init();
    void setObject_path(QString foldername, QString filename);
    void setObject_Config(int count);
    bool setShape_Config(std::string str_id, std::string type_name, std::string shape_type, int center_point_x, int center_point_y, int length_x, int length_y);
    bool writeDataset();
    bool readXMLDataset();
    void retrievElements(QDomElement root, QString tag, QString att);
    std::vector<std::string> split(const std::string &s, char delim);
    void getBit_data(std::vector<int> collect_bit_data, int Traffic_signal_point, int Traffic_signal_width, double traffic_signal_type);

//private Function
private:
    void setFoldername(QString path);
    void setFilename(QString filename);

//private variable
private:
    int count;
    int count_id, *id;
    QString fullFolderPath, foldername, filename;
    std::string *str_id;
    std::string *type_name;
    int bit_value;
    QString str_bit_value;
    Shape_configuation *shape_config;



};
