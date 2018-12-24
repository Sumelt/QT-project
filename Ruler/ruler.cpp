#include "ruler.h"

static bool flag = false;

Ruler::Ruler(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle(tr("Ruler and Semicircle"));
}

void Ruler::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    /*----------------------semicircle----------------------------------*/
    QRadialGradient RadialGradient(500, 430, 500, 500, 430);
    RadialGradient.setColorAt(0.0, Qt::green);
    RadialGradient.setColorAt(0.7, Qt::blue);
    RadialGradient.setColorAt(1.0, Qt::white);
    painter.setBrush(QBrush(RadialGradient));
    painter.drawPie(500, 430, 400, 400, 0, 180*16);//semicircle

    /*----------------------Ruluer----------------------------------*/
    QLinearGradient LinearGradient (350, 30, 600, 350);
    LinearGradient.setColorAt(0.0, Qt::yellow);
    LinearGradient.setColorAt(0.5, Qt::red);
    LinearGradient.setColorAt(1.0, Qt::white);
    painter.setPen(QPen(Qt::black, 4, Qt::SolidLine, Qt::FlatCap));

    if(flag) //reverse ruluer
    {
        painter.translate(420, 350);
        painter.rotate(90);
        painter.translate(-420, -350);
    }

    painter.setBrush(QBrush(LinearGradient));
    painter.drawLine(+450, +50, +450, +600);// 550 length
    painter.drawRect(350, 30, 100, 600); //rect

    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::FlatCap)); //20 bei
    for(int i = 0, j = 50, n = 100; i<6; i++, j+=110, n-=20)
    {
        painter.drawLine(420,  j, 450,  j); //100
        if(i == 0)
            painter.drawText(QPoint(393, j+2), QString::number(n, 10));
        else if(i == 5)
            painter.drawText(QPoint(405, j+2), QString::number(n, 10));
        else
            painter.drawText(QPoint(398, j+2), QString::number(n, 10));
    }

    painter.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::FlatCap)); //10 bei
    for(int i = 0, j = 2; i<5; i++, j+=4)
    {
        painter.drawLine(430, 600-(27.5*j), 450, 600-(27.5*j));
    }

    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap)); //5 bei
    for(int i = 0, j = 1; i<10; i++, j+=2)
    {
        painter.drawLine(440, 600-(27.5*j), 450, 600-(27.5*j));
    }
}

void Ruler::mousePressEvent(QMouseEvent *event)
{
    flag = !flag;
    update();
}
