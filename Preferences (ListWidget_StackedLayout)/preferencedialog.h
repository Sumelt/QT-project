#ifndef PREFERENCEDIALOG_H
#define PREFERENCEDIALOG_H

#include <QDialog>

class QCheckBox;
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QListWidget;
class QRadioButton;
class QStackedLayout;

class PreferenceDialog : public QDialog
{
    Q_OBJECT

public:
    PreferenceDialog(QWidget *parent = 0);

private:
    void createAppearancePage();
    void createWebBrowserPage();
    void createMailAndNewsPage();
    void createAdvancedPage();
    //--------------------------------------------left widget
    QStackedLayout *stackedLayout;
    QListWidget *listWidget;
    QWidget *appearancePage;
    QWidget *webBrowserPage;
    QWidget *mailAndNewsPage;
    QWidget *advancedPage;
    //--------------------------------------------cancel and ok button
    QDialogButtonBox *buttonBox;
    //-------------------------------------------- one
    QGroupBox *openGroupBox;
    QCheckBox *webBrowserCheckBox;
    QCheckBox *mailEditorCheckBox;
    QCheckBox *newsgroupCheckBox;

    QGroupBox *toolbarsGroupBox;
    QRadioButton *picturesAndTextRadioButton;
    QRadioButton *picturesOnlyRadioButton;
    QRadioButton *textOnlyRadioButton;

    QCheckBox *tooltipsCheckBox;
    QCheckBox *webSiteIconsCheckBox;
    QCheckBox *resizeImagesCheckBox;

    //---------------------------------------------two
    QGroupBox *displayGroupBox;
    QRadioButton *blankRadioButton;
    QRadioButton *homeRadioButton;
    QRadioButton *lastRadioButton;

    QGroupBox *homeGroupBox;
    QLabel *locationLabel;
    QLineEdit *locationLineEdit;

    QGroupBox *webButtonsGroupBox;
    QCheckBox *bookmarksCheckBox;
    QCheckBox *goCheckBox;
    QCheckBox *homeCheckBox;
    QCheckBox *searchCheckBox;
    QCheckBox *printCheckBox;
    //----------------------------------------------three
    QGroupBox *generalGroupBox;
    QCheckBox *confirmCheckBox;
    QCheckBox *rememberCheckBox;

    QGroupBox *mailButtonsGroupBox;
    QCheckBox *fileCheckBox;
    QCheckBox *nextCheckBox;
    QCheckBox *stopCheckBox;
    QCheckBox *junkCheckBox;
    //-----------------------------------------------four
    QGroupBox *featuresGroupBox;
    QCheckBox *javaCheckBox;
    QCheckBox *ftpCheckBox;
    QLineEdit *ftpLineEdit;
};

#endif
