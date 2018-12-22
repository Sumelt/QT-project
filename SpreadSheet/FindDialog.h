#ifndef FINDDIALOG_H
#define FINDDIALOG_H
#include<QDialog>
#include<QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QCheckBox>
#include<QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QString>
#include<QObject>
#include<Qt>
#include<QDebug>

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
        QPushButton *Findbutton; //find
        QPushButton *Closebutton; //close
        QCheckBox *matchBox;//checkbox1; //match box
        QCheckBox *searchBackBox;//checkbox2; //search back box

signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);

private slots:
       void findClicked();
       void enableFindButton(const QString& );

};

#endif // MYDIALOG_H
