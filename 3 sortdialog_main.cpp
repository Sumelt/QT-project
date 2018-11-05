#include <QApplication>
#include "sortdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //sortDialog w;
    //w.show();
    mysortDialog *w = new mysortDialog;
    w->setColumnRange('C', 'F');
    w->show();
    
    return a.exec();
}
