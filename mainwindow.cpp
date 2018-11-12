#include "mainwindow.h"
#include "ui_mainwindow.h"
/*
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/

MainWindow::MainWindow()
{
    mytable = new SpreadSheet;
    setCentralWidget(mytable);

    CreateAction();
    CreateMenu();
    CreateToolBar();
    CreateStatusBar();

    setWindowTitle("MY SpreadSheet");
    resize(1000,500);
    move(250,250);
}

void MainWindow::CreateMenu()
{
    /**file**/
    FileMenu = menuBar()->addMenu("&File");
    FileMenu->addAction(newFile);
    FileMenu->addAction(openFile);
    FileMenu->addAction(saveFile);
    FileMenu->addAction(saveasFile);
    FileMenu->addSeparator();
    FileMenu->addAction(exitFile);

    //;
    /**edit**/
    EditMenu = menuBar()->addMenu("&Edit");
    EditMenu->addAction(cutEdit);
    EditMenu->addAction(copyEdit);
    EditMenu->addAction(pasteEdit);
    EditMenu->addAction(deleteEdit);
    EditMenu->addAction(selectEdit);

    SelectEditMenu = menuBar()->addMenu("&Select");
    SelectEditMenu->addAction(rowSelectEdit);
    SelectEditMenu->addAction(columnSelectEdit);
    SelectEditMenu->addAction(allSelectEdit);
    EditMenu->addMenu(SelectEditMenu);

    EditMenu->addAction(findEdit);
    EditMenu->addSeparator();
    EditMenu->addAction(gotocellEdit);

    /**tools**/
    ToolsMenu = menuBar()->addMenu("&Tools");
    ToolsMenu->addAction(recalTools);
    ToolsMenu->addAction(sortTools);

    /**option**/
    OptionMenu = menuBar()->addMenu("&Option");
    OptionMenu->addAction(NoneOption);
    //OptionMenu->addAction(autorecalOption);

    /**help**/
    HelpMenu = menuBar()->addMenu("&Help");
    HelpMenu->addAction(aboutHelp);


}

void MainWindow::CreateAction()
{
    CreateFileAction();
    CreateEditAction();
    CreateToolsAction();
    CreateOptionAction();
    CreateAboutAction();
}

void MainWindow::CreateFileAction()
{
    newFile = new QAction("&New", this);
    newFile->setIcon(QIcon("./img/new.png"));
    newFile->setShortcut(QKeySequence::New);
    newFile->setStatusTip("Create A New SpreadSheeet");

    openFile = new QAction("&Open", this);
    openFile->setIcon(QIcon("./img/open.png"));
    openFile->setShortcut(QKeySequence::Open);
    openFile->setStatusTip("Open A New SpreadSheeet");

    saveFile = new QAction("&Save", this);
    saveFile->setIcon(QIcon("./img/save.png"));
    saveFile->setShortcut(QKeySequence::Save);
    saveFile->setStatusTip("Save SpreadSheeet");

    saveasFile = new QAction("&Save As", this);
    //saveasFile->setIcon(QIcon("./img/saveas.png"));
    saveasFile->setShortcut(QKeySequence::SaveAs);
    saveasFile->setStatusTip("Save AS SpreadSheeet");

    exitFile = new QAction("&Exit", this);
    exitFile->setShortcut(QKeySequence::Close);
    exitFile->setStatusTip("Exit SpreadSheeet");


}

void MainWindow::CreateEditAction()
{
    cutEdit = new QAction("&Cut", this);
    cutEdit->setIcon(QIcon("./img/cut.png"));
    cutEdit->setShortcut(QKeySequence::Cut);
    cutEdit->setStatusTip("Cut Data");

    copyEdit = new QAction("&Copy", this);
    copyEdit->setIcon(QIcon("./img/copy.png"));
    copyEdit->setShortcut(QKeySequence::Copy);
    copyEdit->setStatusTip("Copy Data");

    pasteEdit = new QAction("&Paste", this);
    pasteEdit->setIcon(QIcon("./img/paste.png"));
    pasteEdit->setShortcut(QKeySequence::Paste);
    pasteEdit->setStatusTip("paste Data");

    deleteEdit = new QAction("&Delete", this);
    deleteEdit->setShortcut(QKeySequence::Delete);
    deleteEdit->setStatusTip("Delete Data");

    rowSelectEdit = new QAction("&Row", this);
    columnSelectEdit = new QAction("&Column", this);
    allSelectEdit = new QAction("&All", this);
    allSelectEdit->setShortcut(QKeySequence::SelectAll);

    findEdit = new QAction("&Find", this);
    findEdit->setIcon(QIcon("./img/find.png"));
    findEdit->setShortcut(QKeySequence::Find);
    findEdit->setStatusTip("find Data");

    gotocellEdit = new QAction("&GoTo Cell", this);
    gotocellEdit->setIcon(QIcon("./img/gotocell.png"));
    gotocellEdit->setStatusTip("gotocell Data");
}

void MainWindow::CreateToolsAction()
{
    recalTools = new QAction("&Recalculate", this);
    recalTools->setShortcut(tr("F9"));
    recalTools->setStatusTip("Recalculate");

    sortTools = new QAction("&Sort", this);
    sortTools->setStatusTip("Sort");
}

void MainWindow::CreateOptionAction()
{
    NoneOption = new QAction("&NoneOption", this);

}

void MainWindow::CreateAboutAction()
{
    aboutHelp = new QAction("&About", this);

}

void MainWindow::CreateToolBar()
{
    FileToolBar = addToolBar("&File");
    FileToolBar->addAction(newFile);
    FileToolBar->addAction(openFile);
    FileToolBar->addAction(saveFile);

    EditeToolBar = addToolBar("&Edit");
    FileToolBar->addAction(copyEdit);
    FileToolBar->addAction(cutEdit);
    FileToolBar->addAction(pasteEdit);
    FileToolBar->addAction(findEdit);
    FileToolBar->addAction(gotocellEdit);

}

void MainWindow::CreateStatusBar()
{
    statusBar();
}
