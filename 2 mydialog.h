#ifndef MYDIALOG_H
#define MYDIALOG_H
#include<QDialog>
#include"ui_dialog.h"

class mydialog : public QDialog, public Ui::Dialog
{
    Q_OBJECT

public:
    mydialog(QWidget *parent = 0);

private slots:
    void lineEditChange(const QString &text);

};


#endif // MYDIALOG_H
