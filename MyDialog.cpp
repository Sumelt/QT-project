#include"MyDialog.h"
#include<QtGui>

void FindDialog :: findClicked()
 {
     QString text = lineedit->text();
     Qt::CaseSensitivity cs = checkbox1->isChecked() ? Qt::CaseSensitive: Qt::CaseInsensitive;

     if (checkbox2->isChecked())
         emit findPrevious(text, cs);
       else
         emit findNext(text, cs);
 }

void FindDialog :: enableFindButton(const QString &text)
 {
     button1->setEnabled(!text.isEmpty());
 }


FindDialog::FindDialog(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("MY Layout");  //my title

    label = new QLabel(QObject::tr("Find what:"));

    lineedit = new QLineEdit;

    button1 = new QPushButton(QObject::tr("&Find"));
    button1->setDefault(true); //enter
    button1->setEnabled(false);  //start invalid

    button2 = new QPushButton(QObject::tr("&Close"));

    checkbox1 = new QCheckBox(QObject::tr("Match &case"));
    checkbox2 = new QCheckBox(QObject::tr("Search &backward"));

    /***********************layout************************************/
    QHBoxLayout *toplayout = new QHBoxLayout;  //top layout
    toplayout->addWidget(label);
    toplayout->addWidget(lineedit);

    QVBoxLayout *leftLayout = new QVBoxLayout; //left layout
    leftLayout->addLayout(toplayout);
    leftLayout->addWidget(checkbox1);
    leftLayout->addWidget(checkbox2);

    QVBoxLayout *rightLayout = new QVBoxLayout; //right layout
    rightLayout->addWidget(button1);
    rightLayout->addWidget(button2);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;  //main layout
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

/*****************connect signals and slots**********************/
    connect(button1, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(button2, SIGNAL(clicked()), this, SLOT(close()));
    connect(lineedit, SIGNAL(textChanged(const QString&)), this,SLOT(enableFindButton(const QString&)));

    setLayout(mainLayout);
    setFixedHeight(sizeHint().height());

}



