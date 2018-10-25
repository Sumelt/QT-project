#include<QApplication>
#include"MyDialog.h"


int main(int argc, char*argv[])
{
    QApplication app(argc, argv);

    FindDialog * find = new FindDialog;
    find->show();
    return app.exec();
}


