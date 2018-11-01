#include <QApplication>
#include <QDialog>
#include "ui_dialog.h"
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mydialog *w = new mydialog;
    w->show();

    return a.exec();
}
