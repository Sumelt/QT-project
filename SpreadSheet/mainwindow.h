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
#include <QPalette>
#include <QFileDialog>
#include "SpreadSheet.h"
#include "FindDialog.h"
#include "gotocell.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    //explicit MainWindow(QWidget *parent = 0);
    //~MainWindow();
    MainWindow(MainWindow* parent = 0);
    void CreateMenu();
    void CreateAction();
    void CreateToolBar();
    void CreateStatusBar();
    void CreateFileAction();
    void CreateEditAction();
    void CreateToolsAction();
    void CreateOptionAction();
    void CreateAboutAction();
    void CreateContextMenuAction();
    bool oktoContinue();
    void hideSpreadSheet(); //test


private slots:
    void aboutInfoMBox();
    void updataBarPosition();
    void NewSpreadSheet();
    void find();
    void gotocell();
    void showGrid(bool);
    void opend();

private:
    /**SpreadSheet**/
    SpreadSheet *mytable;

    /**FindDialog**/
    FindDialog *findDialog;

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
    QAction *findEdit;
    QAction *gotocellEdit;
    QAction *rowSelectEdit;
    QAction *columnSelectEdit;
    QAction *allSelectEdit;

    QAction *recalTools;
    QAction *sortTools;

    QAction *showGridOption;
    QAction *autoRecalcOption;

    QAction *aboutHelp;

    /**Bar**/
    QToolBar *FileToolBar;
    QToolBar *EditeToolBar;

    /**Label**/
    QLabel *LocationLable;

};

#endif // MAINWINDOW_H
