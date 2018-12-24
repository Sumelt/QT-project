#ifndef RULER_H
#define RULER_H

#include <QWidget>
#include <QPainter>

class Ruler : public QWidget
{
    Q_OBJECT
public:
    explicit Ruler(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    
//signals:
    
//public slots:
    
};

#endif // RULER_H
