#ifndef PICTURE_FRAME_H
#define PICTURE_FRAME_H

#include <QPixmap>
#include <QSize>
#include <math.h>

class picture_frame
{

public:

    ~picture_frame();

bool pictureExists(QString file_path);
QPixmap pictureLoad(QString file_path);
QPixmap setPictureSize(QPixmap pixmap, QSize frame_size);
double getPictureWeight(QPixmap picture_pixmap, QSize frame_size);
QRectF getCircle(QPointF center_point, QPointF outer_point, int offset_x, int offset_y);
std::vector<QString> getCircleData(QPointF center_point, QPointF outer_point, int offset_x, int offset_y, double weight);
QRectF getRectangle(QPointF initial_point, QPointF last_point, int offset_x, int offset_y);
std::vector<QString> getRectangleData(QPointF initial_point, QPointF last_point, int offset_x, int offset_y, double weight);


//private Function
private:


//private variable
private:




};

#endif // PICTURE_FRAME_H
