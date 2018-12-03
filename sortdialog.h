#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include <QObject>
#include <FindDialog.h>
#include "ui_sortdialog.h"

namespace Ui {
class sortDialog;
}

class sortDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit sortDialog(QWidget *parent = 0);
    ~sortDialog();
    
private:
    Ui::sortDialog *ui;
};

/* define my class */
class mysortDialog : public QDialog, public Ui::sortDialog
{
     Q_OBJECT

public:
    mysortDialog(QWidget *parent = 0);
    void setColumnRange(QChar first, QChar last);

private slots:
    void alterText(bool);

};


#endif // SORTDIALOG_H
