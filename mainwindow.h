#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "path_configuration.h"
#include "picture_frame.h"

#include <QMainWindow>
#include <QPen>


#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QComboBox>
#include <QSpinBox>
#include <QByteArray>

#include "type_config.h"
#include "Object_management.h"
#include <sstream>
#include <iostream>
#include <string>
#include <cctype>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_FilepathButton_clicked();

    void on_OpenButton_clicked();

    void mousePressEvent(QMouseEvent *event);

    void mouseMoveEvent(QMouseEvent *event);

    void on_type_list_btn_clicked();

    void setComboboxsetup();

    QString checkTypelistShape(QString type_list);


    void PushButtonAction(QPushButton* FindButton, QComboBox* combobox, QString shape, QString data_point_x, QString data_point_y, QString data_width, QString data_height, QSpinBox* spinbox_find);

    void writeDataXML();
    void readData(QString data);
    std::vector<std::string> split(const std::string &s, char delim);




    void on_pushButton_find11_clicked();
    void on_pushButton_find12_clicked();
    void on_pushButton_find21_clicked();
    void on_pushButton_find22_clicked();
    void on_pushButton_find31_clicked();
    void on_pushButton_find32_clicked();
    void on_pushButton_find41_clicked();
    void on_pushButton_find42_clicked();
    void on_pushButton_find51_clicked();
    void on_pushButton_find52_clicked();
    void on_pushButton_find61_clicked();
    void on_pushButton_find62_clicked();
    void spinboxID_reset();


//    void savePushButton(QPushButton* FindButton, QComboBox* combobox);



    void on_SaveButton_clicked();

    void on_radioButton_Id_disable_clicked(bool checked);

    void on_radioButton_Id_enable_clicked(bool checked);

    void spinboxID_readonly();
    void spinboxID_write();

    void setDrawView();

private:
    Ui::MainWindow *ui;
//    Ui::type_config *type_ui;

    QPointF Po1;
    QPointF Po2;

double weight=1;

    QGraphicsScene *scene;
    QGraphicsItem *drawitem;
    QGraphicsItem* item;
    QGraphicsTextItem* textitem;


    QRectF rectangle;

    type_config* type_ui = new type_config;
    path_configuration *path_config;
    picture_frame* picture;

    double radius;
    int find_flag =0;
    QPoint find12_point;
    int find12_int;

    QString data;
    QString data_point_x;
    QString data_point_y;
    QString data_width;
    QString data_height;

    QString TypelistShape;
    QString find_flag_s="0";


    QPointF movment;
    QPointF movment2;

    Object_management *object_data;

    std::map<std::pair<QString, int>, QGraphicsItem*> type_id_item_map;
    std::map<std::pair<QString, int>, QGraphicsTextItem*> type_id_textItem_map;
    std::map<std::pair<QString, int>, QString> type_id_data_map;
    typedef std::pair<QString, int> type_id_pr;
//    typedef std::map<type_id_pr, std::array<int, 4>> type_id_points;
//    type_id_points type_id_points_map;
    QGraphicsItem *f11;
    std::vector<int> collect_bit_data;
    double traffic_signal_type;
    int Traffic_signal_point;
    int Traffic_signal_width;

};
struct scene_item
{
    int a;
    int b;
    int c;
    int d;
};




#endif // MAINWINDOW_H
