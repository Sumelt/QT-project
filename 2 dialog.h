#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;  //���������ʦ���ɵ��࣬�����ڿռ�����Ui��
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    
private:
    Ui::Dialog *ui;  //ʹ�������ռ䣺����Ա ����ui 
};

#endif // DIALOG_H
