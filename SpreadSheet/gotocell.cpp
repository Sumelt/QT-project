#include "gotocell.h"
//#include "ui_gotocell.h"

GoToCell::GoToCell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GoToCell)
{
    ui->setupUi(this);
}

GoToCell::~GoToCell()
{
    delete ui;
}

GoToCellDialog:: GoToCellDialog(QWidget *parent): QDialog(parent)
{
    setupUi(this);

    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

    connect(CancelPushButton, SIGNAL(clicked()), this, SLOT(reject()));
    connect(OkPushButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(lineEdit, SIGNAL(textChanged(const QString&)), this,
            SLOT(lineEditChange(const QString&)));

}

void GoToCellDialog::lineEditChange(const QString &text)
{
   OkPushButton->setEnabled(lineEdit->hasAcceptableInput());

}
