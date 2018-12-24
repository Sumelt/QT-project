#include <QApplication>
#include "ruler.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Ruler *myRuler = new Ruler;
    myRuler->show();
    myRuler->resize(1000, 800);
    return app.exec();

}
