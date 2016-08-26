#include "picture_frame.h"

bool picture_frame::pictureExists(QString file_path)
{
   QPixmap pixmap;
   if(pixmap.load(file_path)) return true;
   else return false;
}

QPixmap picture_frame::pictureLoad(QString file_path)
{
    QPixmap pixmap;
    pixmap.load(file_path);
    return pixmap;
}


QPixmap picture_frame::setPictureSize(QPixmap pixmap, QSize frame_size)
{
    if((pixmap.size().width()>frame_size.width()) || (pixmap.size().height()>frame_size.height()))
    {
        if(pixmap.size().width()-frame_size.width()>=pixmap.size().height()-frame_size.height())
        {
            pixmap=pixmap.scaled(frame_size.width(),pixmap.size().height()*frame_size.width()/pixmap.size().width());
            return pixmap;
        }
        else if(pixmap.size().width()-frame_size.width()<pixmap.size().height()-frame_size.height())
        {
            pixmap=pixmap.scaled(pixmap.size().width()*frame_size.height()/pixmap.size().height(),frame_size.height());
            return pixmap;
        }
    }
    else return pixmap;
}

double picture_frame::getPictureWeight(QPixmap picture_pixmap, QSize frame_size)
{   double weight;

    if((picture_pixmap.size().width()>frame_size.width()) || (picture_pixmap.size().height()>frame_size.height()))
    {
        if(picture_pixmap.size().width()-frame_size.width()>=picture_pixmap.size().height()-frame_size.height())
        {
            weight=(double) picture_pixmap.size().width()/frame_size.width();
            return weight;
        }
        else if(picture_pixmap.size().width()-frame_size.width()<picture_pixmap.size().height()-frame_size.height())
        {
            weight=(double) picture_pixmap.size().height()/frame_size.height();
            return weight;
        }
    }
    else return 1;
}

QRectF picture_frame::getCircle(QPointF center_point, QPointF outer_point, int offset_x, int offset_y)
{
    double radius=sqrt(pow(center_point.x()-outer_point.x(),2)+pow(center_point.y()-outer_point.y(),2));
    QRectF temp(center_point.x()-offset_x-radius, center_point.y()-offset_y-radius, radius*2, radius*2);
    return temp;
}

std::vector<QString> picture_frame::getCircleData(QPointF center_point, QPointF outer_point, int offset_x, int offset_y, double weight)
{
    std::vector<QString> temp(4);
    temp.at(0)=QString::number((center_point.x()-offset_x)*weight);
    temp.at(1)=QString::number((center_point.y()-offset_y)*weight);
    temp.at(2)=QString::number(sqrt(pow(center_point.x()-outer_point.x(),2)+pow(center_point.y()-outer_point.y(),2))*weight*2);
    temp.at(3)=QString::number(sqrt(pow(center_point.x()-outer_point.x(),2)+pow(center_point.y()-outer_point.y(),2))*weight*2);
    return temp;
}

QRectF picture_frame::getRectangle(QPointF initial_point, QPointF last_point, int offset_x, int offset_y)
{
    QRectF temp(initial_point.x()-offset_x,initial_point.y()-offset_y,last_point.x()-initial_point.x(),last_point.y()-initial_point.y());
    return temp;
}

std::vector<QString> picture_frame::getRectangleData(QPointF initial_point, QPointF last_point, int offset_x, int offset_y, double weight)
{
    std::vector<QString> temp(4);
    temp.at(0)=QString::number(((last_point.x()+initial_point.x())/2-offset_x)*weight);
    temp.at(1)=QString::number(((last_point.y()+initial_point.y())/2-offset_y)*weight);
    temp.at(2)=QString::number((last_point.x()-initial_point.x())*weight);
    temp.at(3)=QString::number((last_point.y()-initial_point.y())*weight);
    return temp;
}

