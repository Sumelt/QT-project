/********************************************************************************
** Form generated from reading UI file 'sortdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sortDialog
{
public:
    QFormLayout *formLayout;
    QGridLayout *gridLayout_4;
    QGroupBox *primaryGroupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *primaryColumnCombo;
    QSpacerItem *horizontalSpacer;
    QLabel *label_6;
    QComboBox *primaryOrderCombo;
    QVBoxLayout *verticalLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *verticalSpacer;
    QPushButton *moreButton;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *secondaryGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *secondaryColumnCombo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QComboBox *secondaryOrderCombo;
    QGroupBox *tertiaryGroupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QComboBox *tertiaryColumnCombo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QComboBox *tertiaryOrderCombo;

    void setupUi(QDialog *sortDialog)
    {
        if (sortDialog->objectName().isEmpty())
            sortDialog->setObjectName(QString::fromUtf8("sortDialog"));
        sortDialog->resize(306, 384);
        formLayout = new QFormLayout(sortDialog);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        primaryGroupBox = new QGroupBox(sortDialog);
        primaryGroupBox->setObjectName(QString::fromUtf8("primaryGroupBox"));
        gridLayout = new QGridLayout(primaryGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(primaryGroupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        primaryColumnCombo = new QComboBox(primaryGroupBox);
        primaryColumnCombo->setObjectName(QString::fromUtf8("primaryColumnCombo"));

        gridLayout->addWidget(primaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_6 = new QLabel(primaryGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        primaryOrderCombo = new QComboBox(primaryGroupBox);
        primaryOrderCombo->setObjectName(QString::fromUtf8("primaryOrderCombo"));

        gridLayout->addWidget(primaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(primaryGroupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        okButton = new QPushButton(sortDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setDefault(true);

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(sortDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setEnabled(true);

        verticalLayout->addWidget(cancelButton);

        verticalSpacer = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        moreButton = new QPushButton(sortDialog);
        moreButton->setObjectName(QString::fromUtf8("moreButton"));
        moreButton->setCheckable(true);

        verticalLayout->addWidget(moreButton);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        secondaryGroupBox = new QGroupBox(sortDialog);
        secondaryGroupBox->setObjectName(QString::fromUtf8("secondaryGroupBox"));
        gridLayout_2 = new QGridLayout(secondaryGroupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(secondaryGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        secondaryColumnCombo = new QComboBox(secondaryGroupBox);
        secondaryColumnCombo->setObjectName(QString::fromUtf8("secondaryColumnCombo"));

        gridLayout_2->addWidget(secondaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_3 = new QLabel(secondaryGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        secondaryOrderCombo = new QComboBox(secondaryGroupBox);
        secondaryOrderCombo->setObjectName(QString::fromUtf8("secondaryOrderCombo"));

        gridLayout_2->addWidget(secondaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(secondaryGroupBox, 2, 0, 1, 1);

        tertiaryGroupBox = new QGroupBox(sortDialog);
        tertiaryGroupBox->setObjectName(QString::fromUtf8("tertiaryGroupBox"));
        gridLayout_3 = new QGridLayout(tertiaryGroupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_4 = new QLabel(tertiaryGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        tertiaryColumnCombo = new QComboBox(tertiaryGroupBox);
        tertiaryColumnCombo->setObjectName(QString::fromUtf8("tertiaryColumnCombo"));

        gridLayout_3->addWidget(tertiaryColumnCombo, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_5 = new QLabel(tertiaryGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        tertiaryOrderCombo = new QComboBox(tertiaryGroupBox);
        tertiaryOrderCombo->setObjectName(QString::fromUtf8("tertiaryOrderCombo"));

        gridLayout_3->addWidget(tertiaryOrderCombo, 1, 1, 1, 2);


        gridLayout_4->addWidget(tertiaryGroupBox, 3, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_4);

        QWidget::setTabOrder(okButton, cancelButton);
        QWidget::setTabOrder(cancelButton, moreButton);
        QWidget::setTabOrder(moreButton, primaryColumnCombo);
        QWidget::setTabOrder(primaryColumnCombo, primaryOrderCombo);
        QWidget::setTabOrder(primaryOrderCombo, secondaryColumnCombo);
        QWidget::setTabOrder(secondaryColumnCombo, secondaryOrderCombo);
        QWidget::setTabOrder(secondaryOrderCombo, tertiaryColumnCombo);
        QWidget::setTabOrder(tertiaryColumnCombo, tertiaryOrderCombo);

        retranslateUi(sortDialog);
        QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
        QObject::connect(okButton, SIGNAL(clicked()), sortDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), sortDialog, SLOT(reject()));
        QObject::connect(moreButton, SIGNAL(toggled(bool)), tertiaryGroupBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(sortDialog);
    } // setupUi

    void retranslateUi(QDialog *sortDialog)
    {
        sortDialog->setWindowTitle(QApplication::translate("sortDialog", "sort", 0, QApplication::UnicodeUTF8));
        primaryGroupBox->setTitle(QApplication::translate("sortDialog", "&Primary Key", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("sortDialog", "Column:", 0, QApplication::UnicodeUTF8));
        primaryColumnCombo->clear();
        primaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("sortDialog", "Order:", 0, QApplication::UnicodeUTF8));
        primaryOrderCombo->clear();
        primaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        okButton->setText(QApplication::translate("sortDialog", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("sortDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        moreButton->setText(QApplication::translate("sortDialog", "&More", 0, QApplication::UnicodeUTF8));
        secondaryGroupBox->setTitle(QApplication::translate("sortDialog", "&Secondary Key", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("sortDialog", "Column:", 0, QApplication::UnicodeUTF8));
        secondaryColumnCombo->clear();
        secondaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("sortDialog", "Order:", 0, QApplication::UnicodeUTF8));
        secondaryOrderCombo->clear();
        secondaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
        tertiaryGroupBox->setTitle(QApplication::translate("sortDialog", "&Tertiary Key", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("sortDialog", "Column:", 0, QApplication::UnicodeUTF8));
        tertiaryColumnCombo->clear();
        tertiaryColumnCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "None", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("sortDialog", "Order:", 0, QApplication::UnicodeUTF8));
        tertiaryOrderCombo->clear();
        tertiaryOrderCombo->insertItems(0, QStringList()
         << QApplication::translate("sortDialog", "Ascending", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("sortDialog", "Descending", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class sortDialog: public Ui_sortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
