#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPixmap>


#include <QUrl>
#include <QFileDialog>

#include <QMessageBox>

#include <QPainter>

#include <math.h>


#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>
#include <QMouseEvent>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();               // 사진 띄우기 위한  틀
    ui->graphicsView->setScene((scene));
    int FixedSize_width=640;
    int FixedSize_height=480;
    ui->graphicsView->setFixedSize(FixedSize_width,FixedSize_height);
    ui->graphicsView->setSceneRect(FixedSize_width/2,FixedSize_height/2,1,1);

    ui->FilepathEdit->setText(QDir::homePath());

    connect(type_ui,SIGNAL(accepted()),this,SLOT(setComboboxsetup()));
    
}



MainWindow::~MainWindow()
{
    delete ui;
}

/*******************************************************************************************************************************/
void MainWindow::on_FilepathButton_clicked()
{
    QUrl url = QFileDialog::getExistingDirectory();     //FileDialog 열어서 디렉토리설정
    ui->FilepathEdit->setText(url.toString());          //File path표시
}

/*******************************************************************************************************************************/

void MainWindow::on_OpenButton_clicked()
{    
    type_id_data_map.clear();
    type_id_item_map.clear();
    type_id_textItem_map.clear();
    scene->clear();
    spinboxID_reset();
    QString file_dir(ui->FilepathEdit->text());        //경로 불러들이기 위해서
    QString file_name(ui->FilenameEdit->text());        //파일이름
    int file_number_value(ui->Filenumber->value());                     //몇번째 파일

    QString file_number(path_config->getNumberType(file_number_value));
    QString file_type(ui->FiletypeEdit->text());
    QString file=file_dir+"/"+file_name+file_number+"."+file_type;


    if(picture->pictureExists(file))       //경로에 사진이 있을 경우
    {
        QPixmap pixmap(picture->pictureLoad(file));


        weight=picture->getPictureWeight(pixmap, ui->graphicsView->size());
        pixmap=picture->setPictureSize(pixmap,ui->graphicsView->size());

        item = scene->addPixmap(pixmap);
        item->setPos(0,0);
        setDrawView();
    }
    else                                                        //사진이 없을 경우
    {
        QMessageBox::information(this,"Error","The "+file_dir+"/"+file_name+file_number+"."+file_type+" does not exist.");
    }
}

/*******************************************************************************************************************************/


void MainWindow::on_type_list_btn_clicked()
{
    type_ui->setWindowTitle(QString::fromUtf8("type configuration"));
    type_ui->show();
}

/*******************************************************************************************************************************/

void MainWindow::on_pushButton_find11_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No1->currentText());
    PushButtonAction(ui->pushButton_find11, ui->comboBox_No1, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find11);
}
void MainWindow::on_pushButton_find12_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No1->currentText());
    PushButtonAction(ui->pushButton_find12, ui->comboBox_No1, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find12);
}
void MainWindow::on_pushButton_find21_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No2->currentText());
    PushButtonAction(ui->pushButton_find21, ui->comboBox_No2, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find21);
}
void MainWindow::on_pushButton_find22_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No2->currentText());
    PushButtonAction(ui->pushButton_find22, ui->comboBox_No2, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find22);
}
void MainWindow::on_pushButton_find31_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No3->currentText());
    PushButtonAction(ui->pushButton_find31, ui->comboBox_No3, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find31);
}
void MainWindow::on_pushButton_find32_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No3->currentText());
    PushButtonAction(ui->pushButton_find32, ui->comboBox_No3, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find32);
}
void MainWindow::on_pushButton_find41_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No4->currentText());
    PushButtonAction(ui->pushButton_find41, ui->comboBox_No4, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find41);
}
void MainWindow::on_pushButton_find42_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No4->currentText());
    PushButtonAction(ui->pushButton_find42, ui->comboBox_No4, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find42);
}
void MainWindow::on_pushButton_find51_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No5->currentText());
    PushButtonAction(ui->pushButton_find51, ui->comboBox_No5, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find51);
}
void MainWindow::on_pushButton_find52_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No5->currentText());
    PushButtonAction(ui->pushButton_find52, ui->comboBox_No5, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find52);
}
void MainWindow::on_pushButton_find61_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No6->currentText());
    PushButtonAction(ui->pushButton_find61, ui->comboBox_No6, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find61);
}
void MainWindow::on_pushButton_find62_clicked()
{
    TypelistShape=checkTypelistShape(ui->comboBox_No6->currentText());
    PushButtonAction(ui->pushButton_find62, ui->comboBox_No6, TypelistShape, data_point_x, data_point_y, data_width, data_height,ui->spinBox_find62);
}

/*******************************************************************************************************************************/

QString MainWindow::checkTypelistShape(QString type_list)
{
    int i=0;
        for(i=0;i<type_ui->sl.count()-1;i++)
        {
            if(type_ui->sl.at(i+1)==type_list) return type_ui->sl_shape.at(i);
        }
    if(type_list=="Type List") return "null";
}

/*******************************************************************************************************************************/

void MainWindow::PushButtonAction(QPushButton* FindButton, QComboBox* combobox, QString shape, QString data_point_x, QString data_point_y, QString data_width, QString data_height, QSpinBox* spinbox_find)
{
    if(shape!="null")
    {
        if(find_flag_s !="0" && find_flag_s !=FindButton->objectName()) QMessageBox::information(this,"Error","Error");
        else
        {   int id;
            QString type = combobox->currentText();
            if(ui->radioButton_Id_disable->isChecked()) id = 0;
            else if(ui->radioButton_Id_enable->isChecked()) id = spinbox_find->value();

            if(FindButton->text()=="find")
            {
                FindButton->setText("Set");

                    drawitem=type_id_item_map[type_id_pr(type,id)];
                    textitem=type_id_textItem_map[type_id_pr(type,id)];

                FindButton->setStyleSheet("background-color: red; border-radius: 10px;");
                combobox->setDisabled(true);

                spinboxID_readonly();

                find_flag_s=FindButton->objectName();

                ui->OpenButton->setDisabled(true);
                ui->SaveButton->setDisabled(true);
                ui->PreviousButton->setDisabled(true);
                ui->NextButton->setDisabled(true);

            }
            else if(FindButton->text()=="Set")
            {
                FindButton->setText("find");
                FindButton->setAutoFillBackground(false);
                FindButton->setStyleSheet("");
                FindButton->update();
                spinboxID_write();


                find_flag_s="0";
                combobox->setEnabled(true);
                std::pair <QString,int> product1;
                product1 = std::make_pair(QString(type),id);


                type_id_item_map[product1] = drawitem;
                textitem=scene->addText((QString::number(id)+", "+combobox->currentText()));
                textitem->setPos(data_point_x.toDouble()/weight,(data_point_y.toDouble()+data_height.toDouble()/2)/weight);
//                textitem->setPos(Po1.x()-32,Po1.y()-135);
                type_id_textItem_map[product1] = textitem;


                ui->OpenButton->setEnabled(true);
                ui->SaveButton->setEnabled(true);
                ui->PreviousButton->setEnabled(true);
                ui->NextButton->setEnabled(true);

                type_id_data_map[product1] = (QString::number(id)+","+combobox->currentText()+","+shape+","+data_point_x+", "+data_point_y+", "+data_width+", "+data_height);


            }
        }
    }
}

/*******************************************************************************************************************************/

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(find_flag_s !="0" )
    {
        Po1 = Po2 = ui->graphicsView->mapToScene(event->pos());

        ui->label_x_value->setText(QString::number((Po1.x()-32)*weight));
        ui->label_y_value->setText(QString::number((Po1.y()-135)*weight));
        ui->label_width_value->setText("0");
        ui->label_height_value->setText("0");

        scene->removeItem(textitem);
    }
}

/*******************************************************************************************************************************/

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(find_flag_s !="0" & TypelistShape!="null")
    {
        scene->removeItem(drawitem);
        Po2 = ui->graphicsView->mapToScene(event->pos());

        if(TypelistShape=="Circle")
        {

            drawitem=scene->addEllipse(picture->getCircle(Po1,Po2,32,135));


            std::vector<QString> circle_data_vector =picture->getCircleData(Po1,Po2,32,135,weight);
            data_point_x=circle_data_vector.at(0);
            data_point_y=circle_data_vector.at(1);
            data_width=circle_data_vector.at(2);
            data_height=circle_data_vector.at(3);

            ui->label_width_value->setText(data_width);
            ui->label_height_value->setText(data_height);

        }
        else if(TypelistShape=="Rectangle")
        {
            drawitem=scene->addRect(picture->getRectangle(Po1,Po2,32,135));

            std::vector<QString> Rectangle_data_vertor = picture->getRectangleData(Po1,Po2,32,135,weight);
            data_point_x=Rectangle_data_vertor.at(0);
            data_point_y=Rectangle_data_vertor.at(1);
            data_width=Rectangle_data_vertor.at(2);
            data_height=Rectangle_data_vertor.at(3);

            ui->label_x_value->setText(data_point_x);
            ui->label_y_value->setText(data_point_y);
            ui->label_width_value->setText(data_width);
            ui->label_height_value->setText(data_height);
        }
    }
}


/*******************************************************************************************************************************/


void MainWindow::on_SaveButton_clicked()
{

    QString file_dir(ui->FilepathEdit->text());        //경로 불러들이기 위해서
    QString file_name(ui->FilenameEdit->text());        //파일이름
    int file_number_value(ui->Filenumber->value());                     //몇번째 파일

    QString file_number(path_config->getNumberType(file_number_value));
    QString file_type(ui->FiletypeEdit->text());
    QString file=file_dir+"/"+file_name+file_number+"."+file_type;



        printf("Saved\n");
        this->object_data = new Object_management();
        this->object_data->setObject_path(file_dir, file_name+file_number+".xml");

        writeDataXML();
        scene->clear();

        ui->Filenumber->stepUp();
        ui->OpenButton->click();
}

/*******************************************************************************************************************************/

void MainWindow::writeDataXML(){
    std::map<std::pair<QString, int>, QString>::iterator iter;
    this->object_data->setObject_Config(type_id_data_map.size());
    for (iter = type_id_data_map.begin(); iter !=type_id_data_map.end();++iter)
    {
        readData(iter->second);
    }

    if (ui->radioButton_Id_disable->isChecked()) this->object_data->getBit_data(collect_bit_data,Traffic_signal_point,Traffic_signal_width, traffic_signal_type);
    this->object_data->writeDataset();
    this->object_data->init();
    this->collect_bit_data.clear();

}

/*******************************************************************************************************************************/


void MainWindow::readData(QString qdata){    

    std::vector<std::string> data_vector = split(qdata.toUtf8().constData(), ',');
    std::string str_id         = data_vector.at(0);
    std::string type_name      = data_vector.at(1);
    std::string shape_type     = data_vector.at(2); // required string to int
    std::string center_point_x = data_vector.at(3); // required string to int
    std::string center_point_y = data_vector.at(4); // required string to int
    std::string length_x       = data_vector.at(5); // required string to int
    std::string length_y       = data_vector.at(6); // required string to int

    if(shape_type=="Circle") collect_bit_data.push_back(std::atoi(center_point_x.c_str()));
    else
    {
        traffic_signal_type = (double)(std::atoi(length_x.c_str())/std::atoi(length_y.c_str()));
        Traffic_signal_point = std::atoi(center_point_x.c_str())- std::atoi(length_x.c_str())/2;
        Traffic_signal_width = std::atoi(length_x.c_str());
    }



    if(this->object_data->setShape_Config(str_id, type_name, shape_type, std::atoi(center_point_x.c_str()), std::atoi(center_point_y.c_str()), std::atoi(length_x.c_str()), std::atoi(length_y.c_str())))
    {
        try{
            std::cout << "qdata : " << qdata.toUtf8().constData() << std::endl;
            /*std::cout << "data( 0 ) : " << data_vector.at(0) << std::endl;
            std::cout << "data( 1 ) : " << data_vector.at(1) << std::endl;
            std::cout << "data( 2 ) : " << data_vector.at(2) << std::endl;
            std::cout << "data( 3 ) : " << data_vector.at(3) << std::endl;
            std::cout << "data( 4 ) : " << data_vector.at(4) << std::endl;
            std::cout << "data( 5 ) : " << std::atoi(length_x.c_str()) << std::endl;

            std::cout << "data( 6 ) : " << data_vector.at(6) << std::endl;*/
        }catch(...){
        }
    }
}

/*******************************************************************************************************************************/

std::vector<std::string> MainWindow::split(const std::string &s, char delim){
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delim)){
        elems.push_back(number);
    }
    return elems;
}

/*******************************************************************************************************************************/









void MainWindow::setComboboxsetup()
{
    ui->comboBox_No1->clear();
    ui->comboBox_No1->addItems(type_ui->sl);
    ui->comboBox_No2->clear();
    ui->comboBox_No2->addItems(type_ui->sl);
    ui->comboBox_No3->clear();
    ui->comboBox_No3->addItems(type_ui->sl);
    ui->comboBox_No4->clear();
    ui->comboBox_No4->addItems(type_ui->sl);
    ui->comboBox_No5->clear();
    ui->comboBox_No5->addItems(type_ui->sl);
    ui->comboBox_No6->clear();
    ui->comboBox_No6->addItems(type_ui->sl);

}

void MainWindow::on_radioButton_Id_disable_clicked(bool checked)
{
    //*********ID disable***************//
    ui->spinBox_find11->setDisabled(true);
    ui->spinBox_find12->setDisabled(true);
    ui->spinBox_find21->setDisabled(true);
    ui->spinBox_find22->setDisabled(true);
    ui->spinBox_find31->setDisabled(true);
    ui->spinBox_find32->setDisabled(true);
    ui->spinBox_find41->setDisabled(true);
    ui->spinBox_find42->setDisabled(true);
    ui->spinBox_find51->setDisabled(true);
    ui->spinBox_find52->setDisabled(true);
    ui->spinBox_find61->setDisabled(true);
    ui->spinBox_find62->setDisabled(true);
    //*********ID disable***************//

    //********PushButton disable***********//
    ui->pushButton_find12->setDisabled(true);
    ui->pushButton_find22->setDisabled(true);
    ui->pushButton_find32->setDisabled(true);
    ui->pushButton_find42->setDisabled(true);
    ui->pushButton_find52->setDisabled(true);
    ui->pushButton_find62->setDisabled(true);
    //********PushButton disable***********//
}

void MainWindow::on_radioButton_Id_enable_clicked(bool checked)
{
    //*********ID enable***************//
    ui->spinBox_find11->setEnabled(true);
    ui->spinBox_find12->setEnabled(true);
    ui->spinBox_find21->setEnabled(true);
    ui->spinBox_find22->setEnabled(true);
    ui->spinBox_find31->setEnabled(true);
    ui->spinBox_find32->setEnabled(true);
    ui->spinBox_find41->setEnabled(true);
    ui->spinBox_find42->setEnabled(true);
    ui->spinBox_find51->setEnabled(true);
    ui->spinBox_find52->setEnabled(true);
    ui->spinBox_find61->setEnabled(true);
    ui->spinBox_find62->setEnabled(true);
    //*********ID enable***************//

    //*********PushButton enable**********//
    ui->pushButton_find11->setEnabled(true);
    ui->pushButton_find22->setEnabled(true);
    ui->pushButton_find32->setEnabled(true);
    ui->pushButton_find42->setEnabled(true);
    ui->pushButton_find52->setEnabled(true);
    ui->pushButton_find62->setEnabled(true);
    //*********PushButton enable**********//
}


void MainWindow::spinboxID_readonly()
{
    ui->spinBox_find11->setReadOnly(true);
    ui->spinBox_find12->setReadOnly(true);
    ui->spinBox_find21->setReadOnly(true);
    ui->spinBox_find22->setReadOnly(true);
    ui->spinBox_find31->setReadOnly(true);
    ui->spinBox_find32->setReadOnly(true);
    ui->spinBox_find41->setReadOnly(true);
    ui->spinBox_find42->setReadOnly(true);
    ui->spinBox_find51->setReadOnly(true);
    ui->spinBox_find52->setReadOnly(true);
    ui->spinBox_find61->setReadOnly(true);
    ui->spinBox_find62->setReadOnly(true);
}

void MainWindow::spinboxID_write()
{
    ui->spinBox_find11->setReadOnly(false);
    ui->spinBox_find12->setReadOnly(false);
    ui->spinBox_find21->setReadOnly(false);
    ui->spinBox_find22->setReadOnly(false);
    ui->spinBox_find31->setReadOnly(false);
    ui->spinBox_find32->setReadOnly(false);
    ui->spinBox_find41->setReadOnly(false);
    ui->spinBox_find42->setReadOnly(false);
    ui->spinBox_find51->setReadOnly(false);
    ui->spinBox_find52->setReadOnly(false);
    ui->spinBox_find61->setReadOnly(false);
    ui->spinBox_find62->setReadOnly(false);
}




void MainWindow::setDrawView()
{
    QFile *file = new QFile;
    QString file_number(path_config->getNumberType(ui->Filenumber->value()));
    file->setFileName(ui->FilepathEdit->text()+"_AnswerSheet"+"/"+ui->FilenameEdit->text()+file_number+".xml");
//    file->setFileName("/home/hsjeong/QT_ws/build-Traffic_signal-Desktop-Debug/160810_traffic_signal_AnswerSheet/0001.xml");


    if(!file->exists()){
//        qDebug() << "Error : Not found targetFilename";
    }

    if(!file->open(QIODevice::ReadOnly | QIODevice::Text)){
//        qDebug() << "Error : Failed to open the file for reading";
    }

//    qDebug() << "start read xmlfile";


    QString type;
    int id;
    QString shape;
    int point_x;
    int point_y;
    double width;
    double height;




    QXmlStreamReader reader;
    reader.addData(file->readAll());

    if (reader.readNextStartElement()) {
            if (reader.name() == "Traffic_signal"){
                while(reader.readNextStartElement()){
                    if(reader.name() == "image"){                                  // [image subelement]
                        while(reader.readNextStartElement()){
                            if(reader.name() == "filename"){
                                QString s = reader.readElementText();

                            }
                            else if(reader.name() == "count"){
                                QString s = reader.readElementText();
                                std::string s1 = s.toUtf8().constData();

                                {

                                }

                                while(reader.readNextStartElement()){
                                    if(reader.name() == "object"){                 // [object subelement]
                                        while(reader.readNextStartElement()){
                                            if(reader.name() == "type_name"){
                                                QString s = reader.readElementText();
//                                                qDebug(qPrintable(s));
                                                type=s;
                                            }else if(reader.name() == "indexID"){
                                                QString s = reader.readElementText();
                                                id =s.toInt();
//                                                qDebug(qPrintable(s));

                                            }else if(reader.name() == "data"){      // [data subelement]
                                                while(reader.readNextStartElement()){
                                                    if(reader.name() == "type_shape"){
                                                        QString s = reader.readElementText();
                                                        std::string s1 = s.toUtf8().constData();
                                                        if (s=="1") shape="Circle";
                                                        else if(s=="2") shape="Rectangle";
//                                                        qDebug(qPrintable(s));

                                                    }else if(reader.name() == "center_point_x"){
                                                        QString s = reader.readElementText();
                                                        point_x=s.toInt();
                                                        std::string s1 = s.toUtf8().constData();
//                                                        qDebug(qPrintable(s));

                                                    }else if(reader.name() == "center_point_y"){
                                                        QString s = reader.readElementText();
                                                        point_y=s.toInt();
                                                        std::string s1 = s.toUtf8().constData();
//                                                        qDebug(qPrintable(s));

                                                    }else if(reader.name() == "length_x"){
                                                        QString s = reader.readElementText();
                                                        width=s.toDouble();
                                                        std::string s1 = s.toUtf8().constData();
//                                                        qDebug(qPrintable(s));

                                                    }else if(reader.name() == "length_y"){
                                                        QString s = reader.readElementText();
                                                        height = s.toDouble();
                                                        std::string s1 = s.toUtf8().constData();
//                                                        qDebug(qPrintable(s));

                                                        std::pair <QString,int> product1;
                                                        product1 = std::make_pair(QString(type),id);

                                                        if (shape=="Circle") type_id_item_map[product1] =scene->addEllipse((point_x-width/2)/weight,(point_y-height/2)/weight,width/weight,height/weight);
                                                        else if(shape =="Rectangle") type_id_item_map[product1] =scene->addRect((point_x-width/2)/weight,(point_y-height/2)/weight,width/weight,height/weight);

                                                    }else
                                                        reader.skipCurrentElement();
                                                }
                                            }else
                                                reader.skipCurrentElement();
                                        }
                                    }
                                }

                            }else
                                reader.skipCurrentElement();
                        }

                    }
                    else
                        reader.skipCurrentElement();
                }


            }
            else
                reader.raiseError(QObject::tr("Incorrect file"));
    }

//    qDebug() << "end read xmlfile";

}

void MainWindow::spinboxID_reset()
{
   ui->spinBox_find11->setValue(1);
   ui->spinBox_find12->setValue(2);
   ui->spinBox_find21->setValue(1);
   ui->spinBox_find22->setValue(2);
   ui->spinBox_find31->setValue(1);
   ui->spinBox_find32->setValue(2);
   ui->spinBox_find41->setValue(1);
   ui->spinBox_find42->setValue(2);
   ui->spinBox_find51->setValue(1);
   ui->spinBox_find52->setValue(2);
   ui->spinBox_find61->setValue(1);
   ui->spinBox_find62->setValue(2);
}

