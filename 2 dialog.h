#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;  //这是由设计师生成的类，包含在空间命名Ui中
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    Ui::Dialog *ui;  //使用命名空间：：成员 生成ui 
};

#endif // DIALOG_H
