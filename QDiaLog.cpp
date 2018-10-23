#include<QApplication>
#include<QPushButton>
#include<QWidget>
#include<QLabel>
#include<QCheckBox>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>

//void QObject::findClicked()
// {
//     QString text = lineEdit->text();
//     Qt::CaseSensitivity cs =
//             caseCheckBox->isChecked() ? Qt::CaseSensitive: Qt::CaseInsensitive;

//     if (backwardCheckBox->isChecked())
//         emit findPrevious(text, cs);
//       else
//         emit findNext(text, cs);
// }

//void QObject::enableFindButton(const QString &text)
// {
//     findButton->setEnabled(!text.isEmpty());
// }

int main(int argc, char*argv[])
{
    QApplication app(argc, argv);

/*******************************widget initialization***************************/
    QWidget *window = new QWidget;
    window->setWindowTitle("MY Layout");  //my title

/*******************************label initialization***************************/
    QLabel *label = new QLabel(QObject::tr("Find &what:"));

/*******************************lineedit initialization***************************/
    QLineEdit *lineedit = new QLineEdit;

/*******************************button*****************************************/
    QPushButton *button1 = new QPushButton(QObject::tr("&Find"));
    button1->setDefault(true); //enter
    button1->setEnabled(false);  //start invalid
    QPushButton *button2 = new QPushButton(QObject::tr("&Next"));

/*******************************checkbox*****************************************/
    QCheckBox *checkbox1 = new QCheckBox(QObject::tr("Match &case"));
    QCheckBox *checkbox2 = new QCheckBox(QObject::tr("Search &backward"));

/*******************************set layout*****************************************/
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
    window->setLayout(mainLayout);

/*******************************signal connect*************************************/
//    QObject::connect(lineedit, SIGNAL(textChanged(const QString&)), &app, SLOT(enableFindButton(const QString&)));
//    QObject::connect(button1, SIGNAL(clicked()), &app, SLOT(findClicked()));
//    QObject::connect(button2, SIGNAL(clicked()), &app, SLOT(close()));

/*******************************widget show*****************************************/
    window->setFixedHeight(window->sizeHint().height());
    window->show();  //show widget

    return app.exec();
}


