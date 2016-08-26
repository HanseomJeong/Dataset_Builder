#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <qwidget.h>



namespace Ui {

    class Dialog : public QDialog
    {
        Q_OBJECT

    public:

        explicit Dialog(QWidget *parent = 0);
        ~Dialog();


        int a;

    private slots:
        void on_pushButton_clicked();

    private:
        Ui::Dialog *ui;


    };
}


#endif // DIALOG_H
