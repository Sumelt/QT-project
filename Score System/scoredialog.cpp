#include "scoredialog.h"

ScoreDialog::ScoreDialog(QWidget *parent) : QMainWindow(parent)
{
    //setupUi(this);

    CreateDialog(this);
    CreateMenu(this);
    InitMessage();
    Connect();

}

void ScoreDialog::CreateDialog(ScoreDialog *parent)
{
    QWidget *centralWidget = new QWidget(parent);
    QVBoxLayout *vRightLayout = new QVBoxLayout;
    QGridLayout *GleftLayout = new QGridLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QStringList lables;

    /*----------------vRightLayout-----------------------------*/
    insertButton = new QPushButton(tr("Insert"));
    deleterButton = new QPushButton(tr("Deleter"));
    findButton = new QPushButton(tr("Find"));

    findButton->setCheckable(true);
    vRightLayout->addWidget(insertButton);
    vRightLayout->addWidget(deleterButton);
    vRightLayout->addWidget(findButton);
    vRightLayout->addStretch();

    /*----------------GleftLayout-----------------------------*/
    lineEdit = new QLineEdit;
    lineEdit->setEnabled(true);
    tableWidget = new QTableWidget;

    lables <<tr("Name") <<tr("Age") <<tr("Class") <<tr("Number") <<tr("Score");
    tableWidget->setColumnCount(5);
    tableWidget->setRowCount(1);
    tableWidget->setHorizontalHeaderLabels(lables);
    tableWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    GleftLayout->addWidget(lineEdit, 0, 0, 1, 3);
    GleftLayout->addWidget(tableWidget, 1, 0, 1, 3);
    GleftLayout->setColumnStretch(1, 2);

    /*----------------mainLayout-----------------------------*/
    mainLayout->addLayout(GleftLayout);
    mainLayout->addLayout(vRightLayout);

    /*----------------centralWidget-----------------------------*/
    centralWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    centralWidget->setLayout(mainLayout);
    parent->setCentralWidget(centralWidget);
    parent->setMaximumWidth(615);
}

void ScoreDialog::CreateMenu(ScoreDialog *parent)
{
    menuFile = parent->menuBar()->addMenu(tr("&File"));
    menuEdit = parent->menuBar()->addMenu(tr("&Edit"));
    menuHelp = parent->menuBar()->addMenu(tr("&Help"));

    CreateAction(this);

    menuFile->addAction(newActionFile);
    menuFile->addAction(exitActionFile);
    menuEdit->addAction(insertActionEdit);
    menuEdit->addAction(findActionEdit);
    menuEdit->addAction(deleterActionEdit);
    menuHelp->addAction(helpActionHelp);

    insertButton->addAction(insertActionEdit);
    deleterButton->addAction(deleterActionEdit);
    findButton->addAction(findActionEdit);

}

void ScoreDialog::CreateAction(ScoreDialog *parent)
{
    newActionFile = new QAction(tr("&New"), parent);
    exitActionFile = new QAction(tr("&Exit"), parent);
    connect(exitActionFile, SIGNAL(triggered()), this, SLOT(close()));

    deleterActionEdit = new QAction(tr("&Deleter"), parent);
    findActionEdit = new QAction(tr("&Find"), parent);
    insertActionEdit = new QAction(tr("&Insert"), parent);

    helpActionHelp = new QAction(tr("&About"),  parent);



}

void ScoreDialog::InitMessage()
{
    QString str;
    str = "吴彦祖 18 4 417 100";
    AddMessage(str);
    str = "朱一龙 20 1 314 95";
    AddMessage(str);
    str = "渣渣辉 30 2 403 60";
    AddMessage(str);
}

void ScoreDialog::AddMessage(QString str)
{
    QStringList list = str.split(" ");
    QString tmp;

    for(int i = 0; i<list.size(); i++)
    {
       tmp = list[i];
       tableWidget->setItem(tableWidget->rowCount()-1, i, new QTableWidgetItem(tmp));
       tmp.clear();
    }
    tableWidget->insertRow(tableWidget->rowCount());
}

void ScoreDialog::InfoMBox(QString str)
{
        QMessageBox::about(this, str,
                        tr("<h2>Failure</h2><p>Warn: Su </p>"));
}

void ScoreDialog::aboutInfoMBox()
{
    QMessageBox::about(this, tr("About"),
                    tr("<h2>Score System</h2><p>Author: Su </p>"));
}

void ScoreDialog::insert()
{
    QString str = lineEdit->text();
    AddMessage(str);

}

void ScoreDialog::Find()
{
    QString text = lineEdit->text();

    int rC = tableWidget->rowCount();//获得行号

    if(text.isEmpty())
    {
       for (int i = 0; i < rC; i++)
        {
            tableWidget->setRowHidden(i, false);//显示所有行
        }
    }
    else
    {
        QList <QTableWidgetItem *> item = tableWidget->findItems(text, Qt::MatchExactly);
        if(item.length()>0)
        {
            for (int i = 0; i < rC; i++)
                tableWidget->setRowHidden(i, true);//隐藏所有行

            for (int i = 0; i < item.count(); i++)
                tableWidget->setRowHidden(item.at(i)->row(),false);
        }
        else{
            InfoMBox("Find failure");
            findButton->setText(tr("Find"));
        }
    }
}


void ScoreDialog::Deleter()
{
   QString text = lineEdit->text();
   QList <QTableWidgetItem *> item = tableWidget->findItems(text, Qt::MatchExactly);

   if(item.length()>0)
   {
       int rC = tableWidget->rowCount();//获得行号
       for (int i = 0; i < rC; i++)
           tableWidget->setRowHidden(i, true);//隐藏所有行

       for (int i = 0; i < item.count(); i++)
           tableWidget->removeRow(item.at(i)->row()); //deleter

       for (int i = 0; i < rC; i++)
            tableWidget->setRowHidden(i, false);//显示所有行
   }
   else
    InfoMBox("Deleter failure");

}

void ScoreDialog::New()
{

}

void ScoreDialog::alterButtonText(bool flag)
{
    if(!flag){
        lineEdit->clear();
        Find();
        findButton->setText(tr("Find"));
    }
    else
        findButton->setText(tr("Show All"));

}

void ScoreDialog::Connect()
{
    connect(newActionFile,SIGNAL(triggered()), this, SLOT(New()));
    connect(exitActionFile, SIGNAL(triggered()), this, SLOT(close()));

    connect(deleterActionEdit,SIGNAL(triggered()), this, SLOT(Deleter()));
    connect(findActionEdit,SIGNAL(triggered()), this, SLOT(Find()));
    connect(insertActionEdit,SIGNAL(triggered()), this, SLOT(insert()));

    connect(helpActionHelp,SIGNAL(triggered()), this, SLOT(aboutInfoMBox()));

    connect(deleterButton,SIGNAL(clicked()), this, SLOT(Deleter()));

    connect(findButton,SIGNAL(clicked()), this, SLOT(Find()));
    connect(findButton, SIGNAL(toggled(bool)), this, SLOT(alterButtonText(bool)));

    connect(insertButton,SIGNAL(clicked()), this, SLOT(insert()));


}

ScoreDialog::~ScoreDialog()
{
    
}
