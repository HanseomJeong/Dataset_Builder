#include "type_config.h"
#include "ui_type_config.h"
#include <QString>
#include <QTextStream>
#include <iostream>



type_config::type_config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::type_config)
{
    ui->setupUi(this);
}
type_config::~type_config()
{
    delete ui;
}
void type_config::on_buttonBox_accepted()
{


}


void type_config::AddtableWidghet(int row, QString item1, QString item2)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(item1));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(item2));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

QStringList type_config::GettableItemName(QTableWidget* tablewidget)
{
    QStringList ItemName;
    ItemName<<"Type List";
    for(i=0;i<tablewidget->rowCount();i++)
    {
        ItemName.append(tablewidget->item(i,0)->text());
    }
    return ItemName;
}

QStringList type_config::GettableItemShape(QTableWidget* tablewidget)
{
    QStringList ItemShape;
    for(j=0;j<tablewidget->rowCount();j++)
    {
         ItemShape.append(tablewidget->item(j,1)->text());
    }
    return ItemShape;
}



void type_config::on_AddButton_clicked()
{
    int row=ui->tableWidget->rowCount();
/*
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row,0,new QTableWidgetItem(ui->lineEdit->text()));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(ui->comboBox->currentText()));
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
*/
    AddtableWidghet(row,ui->lineEdit->text(),ui->comboBox->currentText());
    ui->lineEdit->clear();



//    sl.clear();
//    sl_shape.clear();
//    sl<<"Type List";

/*
    for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        sl.append(ui->tableWidget->item(i,0)->text());
    }
    for(j=0;j<ui->tableWidget->rowCount();j++)
    {
         sl_shape.append(ui->tableWidget->item(j,1)->text());
    }
*/
    sl=GettableItemName(ui->tableWidget);
    sl_shape=GettableItemShape(ui->tableWidget);
}

void type_config::on_RemoveButton_clicked()
{   int selectedRow=ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(selectedRow);

/*
    //
    sl.clear();
    sl_shape.clear();
    sl<<"Type List";

    for(i=0;i<ui->tableWidget->rowCount();i++)
    {
        sl.append(ui->tableWidget->item(i,0)->text());
    }
    for(j=0;j<ui->tableWidget->rowCount();j++)
    {
         sl_shape.append(ui->tableWidget->item(j,1)->text());
    }
    //
*/
    sl=GettableItemName(ui->tableWidget);
    sl_shape=GettableItemShape(ui->tableWidget);

}


void type_config::on_SaveButton_clicked()
{
    QString filename(QFileDialog::getSaveFileName()+".xml");


    QFile *file = new QFile;
//    std::vector<std::string> xmlfilename_vector = split(this->filename.toUtf8().constData(), '.');
//    QString xmlfilename = QString::fromStdString(xmlfilename_vector.at(0)) + ".xml";

    file->setFileName(filename);
    if(file->exists()){
        file->remove();
    }
    file->open(QIODevice::WriteOnly);



    QString str;
    for(int i=1; i < sl.size();++i)
    {
        str.append("<type name=\"").append(sl.at(i)).append("\">\n");
        str.append("\t<shape name>=\"").append(sl_shape.at(i-1)).append("\">\n");
        str.append("\t</shape>\n");
        str.append("</type>\n");

    }

    QByteArray _str;
    _str.append(str);
    file->write(_str);
    file->close();
}

void type_config::on_OpenButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName();
    QFile inputFile(filename);
    i=1;
    j=0;
    if (inputFile.open(QIODevice::ReadOnly))
    {
      QTextStream in(&inputFile);

      int m=0;
      for(m=0;ui->tableWidget->rowCount()*2;m++)
      {
          ui->tableWidget->removeRow(0);

      }

      while (!in.atEnd())
      {
         QString line = in.readLine();
         line=line.section("=",1,1);
         line=line.remove(0,1);
         line=line.remove(line.size()-2,line.size());
        if(i==(j*4+1))
        {
         ui->tableWidget->insertRow(j);
         ui->tableWidget->setItem(j,0,new QTableWidgetItem(line));
        }
        else if(i==(j*4+2))
        {
         ui->tableWidget->setItem(j,1,new QTableWidgetItem(line));
         j++;
        }
        i++;
      }
      inputFile.close();
   }
    sl=GettableItemName(ui->tableWidget);
    sl_shape=GettableItemShape(ui->tableWidget);
}




