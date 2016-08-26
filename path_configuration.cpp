#include "path_configuration.h"


QString path_configuration::getNumberType(int File_number)
{   QString temp;

    if(0<=File_number && File_number<10) temp = "000"+QString::number(File_number);
    else if(10<=File_number && File_number<100) temp = "00"+QString::number(File_number);
    else if(100<=File_number && File_number<1000) temp = "0"+QString::number(File_number);
    else temp=QString::number(File_number);
    return temp;
}

