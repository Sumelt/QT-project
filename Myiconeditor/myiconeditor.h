#ifndef MYICONEDITOR_H
#define MYICONEDITOR_H

#include <QColor>
#include <QImage>
#include <QWidget>
#include <QDebug>

class IconEditor : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor penColor READ penColor WRITE setPenColor)
    Q_PROPERTY(QImage iconImage READ iconImage WRITE setIconImage)
    Q_PROPERTY(int zoomFactor READ zoomFactor WRITE setZoomFactor)

public:
    IconEditor(QWidget *parent = 0);
    //pen
    void setPenColor(const QColor &newColor);
    QColor penColor() const{ return curColor; }
    //zoom
    void setZoomFactor(int newZoom);
    int zoomFactor(){ return zoom; }
    //image
    void setIconImage(const QImage &newImage);
    QImage iconImage() const { return image; }
    //size
    QSize sizeHint() const;

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent* event);


private:
    QColor curColor;
    int zoom;
    QImage image;

    void setImagePixel(const QPoint &pos, bool opaque);
    QRect pixelRect(int i, int j) const;

};


#endif // MYICONEDITOR_H
