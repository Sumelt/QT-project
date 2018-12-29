#include "studentscore.h"

StudentScore::StudentScore(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    InitMessage();

    connect(findButton, SIGNAL(clicked()), this, SLOT(myfind()));
    connect(deleteButton, SIGNAL(clicked()), this, SLOT(mydelete()));
    connect(InsertButton, SIGNAL(clicked()), this, SLOT(myinsert()));
}

void StudentScore::InitMessage()
{
    QStringList m_header;
    m_header<<QString("Name")<<QString("Age")<<QString("Class")<<QString("Number")<<QString("Score");
    treeWidget->setHeaderLabels(m_header);

    QTreeWidgetItem* A = new QTreeWidgetItem(QStringList()<<"小明"<<"20"<<"4"<<"2"<<"98");
    QTreeWidgetItem* B = new QTreeWidgetItem(QStringList()<<"小丽"<<"20"<<"5"<<"3"<<"98");
    QTreeWidgetItem* C = new QTreeWidgetItem(QStringList()<<"小红"<<"20"<<"8"<<"4"<<"98");
    AddMessage(A);
    AddMessage(B);
    AddMessage(C);
}

void StudentScore::AddMessage(QTreeWidgetItem *item)
{
    treeWidget->addTopLevelItem(item);//添加顶级项

}

void StudentScore::myfind()
{
    QString text = findlineEdit->text();

    QList<QTreeWidgetItem *> item = treeWidget->findItems(text, Qt::MatchExactly, 3);

    for(int i = 0; i<treeWidget->topLevelItemCount(); i++)
    {
        QTreeWidgetItem *tp= treeWidget->topLevelItem(i);
        tp->setBackground(0, Qt::white);
        tp->setBackground(1, Qt::white);
        tp->setBackground(2, Qt::white);
        tp->setBackground(3, Qt::white);
        tp->setBackground(4, Qt::white);
    }

    if(!item.isEmpty())
    {
        item.front()->setBackgroundColor(0, Qt::green);
        item.front()->setBackgroundColor(1, Qt::green);
        item.front()->setBackgroundColor(2, Qt::green);
        item.front()->setBackgroundColor(3, Qt::green);
        item.front()->setBackgroundColor(4, Qt::green);
    }

}

void StudentScore::mydelete()
{
    QString text = deletelineEdit->text();

    QList<QTreeWidgetItem *> item = treeWidget->findItems(text, Qt::MatchExactly, 3);

    if(!item.isEmpty())
        delete item.front();
}

void StudentScore::myinsert()
{
    QStringList list = insertlineEdit->text().split(" ");
    QString tmp;
    QTreeWidgetItem* item = new QTreeWidgetItem;

    for(int i = 0; i<list.length(); i++)
    {
       tmp = list[i];
       item->setText(i, tmp);
       tmp.clear();
    }
    treeWidget->addTopLevelItem(item);

}

StudentScore::~StudentScore()
{

}
