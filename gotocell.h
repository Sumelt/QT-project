#ifndef GOTOCELL_H
#define GOTOCELL_H

#include <QDialog>
#include "ui_gotocell.h"

namespace Ui {
class GoToCell;
}

class GoToCell : public QDialog
{
    Q_OBJECT
    
public:
    explicit GoToCell(QWidget *parent = 0);
    ~GoToCell();
    
private:
    Ui::GoToCell *ui;
};

class GoToCellDialog : public QDialog, public Ui::GoToCell
{
    Q_OBJECT

public:
    GoToCellDialog(QWidget *parent = 0);

private slots:
    void lineEditChange(const QString &text);

};

#endif // GOTOCELL_H
