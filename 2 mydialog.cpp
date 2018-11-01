#include"mydialog.h"

mydialog:: mydialog(QWidget *parent): QDialog(parent)
{
    setupUi(this);
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
    connect(lineEdit, SIGNAL(textChanged(const QString&)), this,
            SLOT(enableFindButton(const QString&)));
}

void mydialog::lineEditChange(const QString &text)
{
   pushButton->setEnabled(!text.isEmpty());
}
