#include "sortdialog.h"
#include "ui_sortdialog.h"
#include <QLayout>
#include <QObject>
#include <QString>
#include <QDebug>

sortDialog::sortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortDialog)
{
    ui->setupUi(this);
}

sortDialog::~sortDialog()
{
    delete ui;
}

/*my class achieve*/

void mysortDialog :: alterText(bool flag)
{
    //qDebug()<<"hello";//返回输出

    if(flag)
        moreButton->setText(QObject :: tr("Advanced<<<"));
    else moreButton->setText(QObject :: tr("Advanced>>>"));

}

mysortDialog :: mysortDialog(QWidget *parent):QDialog(parent)
{
    setupUi(this);
    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    connect(moreButton, SIGNAL(toggled(bool)), this, SLOT(alterText(bool)));

    setColumnRange('A', 'Z');
}

void mysortDialog :: setColumnRange(QChar first, QChar last)
{
    primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumnCombo->clear();

    secondaryColumnCombo->addItem(QObject::tr("None"));
    tertiaryColumnCombo->addItem(QObject::tr("None"));

    primaryColumnCombo->setMinimumSize(
                secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while(ch<=last){
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode()+1;
        qDebug()<<ch;
    }

}
