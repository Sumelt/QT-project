#include"FindDialog.h"
#include<QDialog>

FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("Find");  //my title

    label = new QLabel(QObject::tr("Find what:"));

    lineedit = new QLineEdit;

    Findbutton = new QPushButton(QObject::tr("&Find"));
    Findbutton->setDefault(true); //enter
    Findbutton->setEnabled(false);  //start invalid

    Closebutton = new QPushButton(QObject::tr("&Close"));

    matchBox = new QCheckBox(QObject::tr("Match &case"));
    searchBackBox = new QCheckBox(QObject::tr("Search &backward"));

    /***********************layout************************************/
    QHBoxLayout *toplayout = new QHBoxLayout;  //top layout
    toplayout->addWidget(label);
    toplayout->addWidget(lineedit);

    QVBoxLayout *leftLayout = new QVBoxLayout; //left layout
    leftLayout->addLayout(toplayout);
    leftLayout->addWidget(matchBox);
    leftLayout->addWidget(searchBackBox);

    QVBoxLayout *rightLayout = new QVBoxLayout; //right layout
    rightLayout->addWidget(Findbutton);
    rightLayout->addWidget(Closebutton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;  //main layout
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

/*****************connect signals and slots**********************/
    connect(Findbutton, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(Closebutton, SIGNAL(clicked()), this, SLOT(close()));
    connect(lineedit, SIGNAL(textChanged(const QString&)), this,SLOT(enableFindButton(const QString&)));

    setLayout(mainLayout);
    setFixedHeight(sizeHint().height());

}

void FindDialog :: findClicked()
{
     QString text = lineedit->text();
     Qt::CaseSensitivity cs = matchBox->isChecked() ? Qt::CaseSensitive: Qt::CaseInsensitive;

     if (searchBackBox->isChecked()){
         emit findPrevious(text, cs);
         //qDebug()<<"Back";
     }

       else{
         emit findNext(text, cs);
         //qDebug()<<"Next";
     }

}

void FindDialog :: enableFindButton(const QString &text)
{
     Findbutton->setEnabled(!text.isEmpty());
}

