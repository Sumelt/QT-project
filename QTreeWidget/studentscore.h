#ifndef STUDENTSCORE_H
#define STUDENTSCORE_H

#include <QMainWindow>
#include "ui_studentscore.h"

//namespace Ui {
//class StudentScore;
//}

class StudentScore : public QMainWindow, Ui_StudentScore
{
    Q_OBJECT
public:
    StudentScore(QWidget *parent = 0);
    ~StudentScore();
    void AddMessage(QTreeWidgetItem*);
    void InitMessage();

public slots:
      void myfind();
      void myinsert();
      void mydelete();
    
};

#endif // STUDENTSCORE_H
