/********************************************************************************
** Form generated from reading UI file 'gotocell.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOCELL_H
#define UI_GOTOCELL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_GoToCell
{
public:
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *OkPushButton;
    QPushButton *CancelPushButton;

    void setupUi(QDialog *GoToCell)
    {
        if (GoToCell->objectName().isEmpty())
            GoToCell->setObjectName(QString::fromUtf8("GoToCell"));
        GoToCell->resize(243, 80);
        formLayout = new QFormLayout(GoToCell);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        label = new QLabel(GoToCell);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::NoFrame);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setWordWrap(false);
        label->setOpenExternalLinks(false);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        lineEdit = new QLineEdit(GoToCell);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        OkPushButton = new QPushButton(GoToCell);
        OkPushButton->setObjectName(QString::fromUtf8("OkPushButton"));

        gridLayout->addWidget(OkPushButton, 1, 1, 1, 2);

        CancelPushButton = new QPushButton(GoToCell);
        CancelPushButton->setObjectName(QString::fromUtf8("CancelPushButton"));

        gridLayout->addWidget(CancelPushButton, 1, 3, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(GoToCell);

        QMetaObject::connectSlotsByName(GoToCell);
    } // setupUi

    void retranslateUi(QDialog *GoToCell)
    {
        GoToCell->setWindowTitle(QApplication::translate("GoToCell", "GoToCell", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GoToCell", "&Cell Location", 0, QApplication::UnicodeUTF8));
        OkPushButton->setText(QApplication::translate("GoToCell", "OK", 0, QApplication::UnicodeUTF8));
        CancelPushButton->setText(QApplication::translate("GoToCell", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GoToCell: public Ui_GoToCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOCELL_H
