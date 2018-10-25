#ifndef MYDIALOG_H
#define MYDIALOG_H
#include<QDialog>
//#include<QWidget>
//#include<QPushButton>
//#include<QLineEdit>
//#include<QCheckBox>
//#include<QLabel>
//#include<QHBoxLayout>
//#include<QVBoxLayout>
//#include<QString>

class QPushButton;
class QCheckBox;
class QLineEdit;
class QLabel;

class FindDialog : public QDialog{
    Q_OBJECT

    public:
        FindDialog(QWidget *parent = 0);

    private:
        QLabel *label;
        QLineEdit *lineedit;
        QPushButton *button1; //find
        QPushButton *button2; //close
        QCheckBox *checkbox1; //match box
        QCheckBox *checkbox2; //search back box

    signals:
        void findNext(const QString &str, Qt::CaseSensitivity cs);
        void findPrevious(const QString &str, Qt::CaseSensitivity cs);

    private slots:
       void findClicked();
       void enableFindButton(const QString &text);

};

#endif // MYDIALOG_H
