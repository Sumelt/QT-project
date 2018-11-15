#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QObject>
#include <QIcon>
#include <QToolBar>
#include <QLabel>
#include <QStatusBar>
#include <QMessageBox>
#include <QKeySequence>
#include "SpreadSheet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    //explicit MainWindow(QWidget *parent = 0);
    //~MainWindow();
    MainWindow();
    void CreateMenu();
    void CreateAction();
    void CreateToolBar();
    void CreateStatusBar();
    void CreateFileAction();
    void CreateEditAction();
    void CreateToolsAction();
    void CreateOptionAction();
    void CreateAboutAction();


private slots:
    void aboutInfoMBox();
    void updataBarPosition();

private:
    /**SpreadSheet**/
    SpreadSheet *mytable;

    /**Menu**/
    QMenu *FileMenu;
    QMenu *EditMenu;
    QMenu *SelectEditMenu;
    QMenu *ToolsMenu;
    QMenu *OptionMenu;
    QMenu *HelpMenu;
    QMenu *SelectSubEditMenu;

    /**Action**/
    QAction *newFile;
    QAction *openFile;
    QAction *saveFile;
    QAction *saveasFile;
    QAction *exitFile;

    QAction *cutEdit;
    QAction *copyEdit;
    QAction *pasteEdit;
    QAction *deleteEdit;
    QAction *selectEdit;
    QAction *findEdit;
    QAction *gotocellEdit;
    QAction *rowSelectEdit;
    QAction *columnSelectEdit;
    QAction *allSelectEdit;

    QAction *recalTools;
    QAction *sortTools;

    QAction *showGridOption;
    QAction *autoRecalcOption;
    //QAction *NoneOption;

    QAction *aboutHelp;

    /**Bar**/
    QToolBar *FileToolBar;
    QToolBar *EditeToolBar;

    /**Label**/
    QLabel *LocationLable;
};

#endif // MAINWINDOW_H
