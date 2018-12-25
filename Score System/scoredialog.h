#ifndef SCOREDIALOG_H
#define SCOREDIALOG_H

#include <QMainWindow>
#include <QObject>
#include <QSplitter>
#include <QAction>
#include <QMessageBox>
#include <QDebug>
#include "ui_scoredialog.h"

class ScoreDialog : public QMainWindow, Ui_ScoreDialog
{
    Q_OBJECT
    
public:
    ScoreDialog(QWidget *parent = 0);
    ~ScoreDialog();
    void CreateDialog(ScoreDialog*);
    void CreateMenu(ScoreDialog*);
    void CreateAction(ScoreDialog *);
    void AddMessage(QString);
    void InitMessage();
    void Connect();
    void InfoMBox(QString);


private:
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;

    QPushButton *insertButton;
    QPushButton *deleterButton;
    QPushButton *findButton;
    QLineEdit *lineEdit;
    QTableWidget *tableWidget;

    QAction *newActionFile;
    QAction *exitActionFile;
    QAction *deleterActionEdit;
    QAction *findActionEdit;
    QAction *insertActionEdit;
    QAction *helpActionHelp;

public slots:
    void insert();
    void Find();
    void Deleter();
    void New();
    void aboutInfoMBox();
    void alterButtonText(bool);

};

#endif // SCOREDIALOG_H
