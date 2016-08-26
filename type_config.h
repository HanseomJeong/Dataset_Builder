#ifndef TYPE_CONFIG_H
#define TYPE_CONFIG_H

#include <QDialog>
#include <QUrl>
#include <QFileDialog>
#include <QTableWidget>
namespace Ui {
class type_config;
}

class type_config : public QDialog
{
    Q_OBJECT

public:
    explicit type_config(QWidget *parent = 0);
    ~type_config();




    QStringList sl, sl_shape;
private slots:
    void on_buttonBox_accepted();

    void on_AddButton_clicked();

    void on_RemoveButton_clicked();


    void on_SaveButton_clicked();

    void on_OpenButton_clicked();

    void AddtableWidghet(int row, QString item1, QString item2);

    QStringList GettableItemName(QTableWidget *tablewidget);

    QStringList GettableItemShape(QTableWidget* tablewidget);

private:
    Ui::type_config *ui;

    QString input_text;

    int i,j;

};
#endif // TYPE_CONFIG_H
