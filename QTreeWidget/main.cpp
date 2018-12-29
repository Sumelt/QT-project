#include <QApplication>
#include <QTextCodec>
#include "studentscore.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    StudentScore w;
    w.show();
    
    return a.exec();
}
