#include "HexSpinBox.h"

#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

HexSpinBox::HexSpinBox(QWidget *parent): QSpinBox(parent)
{
    setRange(0, 255);
    validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);
}

QValidator::State HexSpinBox::validate(QString &text, int &pos) const
{
    return validator->validate(text, pos);
}

/**number become text**/
QString HexSpinBox::textFromValue(int value) const
{
    return QString::number(value, 16).toUpper();

}

/**text become number**/
/*input string in hex, then string become number by toint*/
int HexSpinBox::valueFromText(const QString &text) const
{
    bool ok;
    return text.toInt(&ok, 16);
}



