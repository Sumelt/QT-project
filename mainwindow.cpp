#include "mainwindow.h"
#include "SpreadSheet.h"
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


MainWindow::MainWindow(MainWindow* parent)
{
    mytable = new SpreadSheet;
    setCentralWidget(mytable);

    CreateAction();
    CreateMenu();
    CreateToolBar();
    CreateStatusBar();

    setWindowTitle("MY SpreadSheet");
    setWindowIcon(QIcon("./img/myico.ico"));

    resize(1000,500);
    move(250,250);
}


/**CreateMenu And Add Action**/
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
    OptionMenu->addAction(showGridOption);
    OptionMenu->addAction(autoRecalcOption);

    /**help**/
    HelpMenu = menuBar()->addMenu("&Help");
    HelpMenu->addAction(aboutHelp);


}

/**Create ALL Action**/
void MainWindow::CreateAction()
{
    CreateFileAction();
    CreateEditAction();
    CreateToolsAction();
    CreateOptionAction();
    CreateAboutAction();
    CreateContextMenuAction();
}


/**File Action**/
void MainWindow::CreateFileAction()
{
    newFile = new QAction("&New", this);
    newFile->setIcon(QIcon("./img/new.png"));
    newFile->setShortcut(QKeySequence::New);
    newFile->setStatusTip("Create A New SpreadSheeet");
    connect(newFile, SIGNAL(triggered()), this, SLOT(NewSpreadSheet()));

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
    connect(exitFile, SIGNAL(triggered()), this, SLOT(close()));

}


/**Edit Action**/
void MainWindow::CreateEditAction()
{
    cutEdit = new QAction("&Cut", this);
    cutEdit->setIcon(QIcon("./img/cut.png"));
    cutEdit->setShortcut(QKeySequence::Cut);
    cutEdit->setStatusTip("Cut Data");
    connect(cutEdit, SIGNAL(triggered()), mytable, SLOT(Cut()));

    copyEdit = new QAction("&Copy", this);
    copyEdit->setIcon(QIcon("./img/copy.png"));
    copyEdit->setShortcut(QKeySequence::Copy);
    copyEdit->setStatusTip("Copy Data");
    connect(copyEdit, SIGNAL(triggered()), mytable, SLOT(Copy()));

    pasteEdit = new QAction("&Paste", this);
    pasteEdit->setIcon(QIcon("./img/paste.png"));
    pasteEdit->setShortcut(QKeySequence::Paste);
    pasteEdit->setStatusTip("Paste Data");
    connect(pasteEdit, SIGNAL(triggered()), mytable, SLOT(Paste()));

    deleteEdit = new QAction("&Delete", this);
    deleteEdit->setShortcut(QKeySequence::Delete);
    deleteEdit->setStatusTip("Delete Data");
    connect(deleteEdit, SIGNAL(triggered()), mytable, SLOT(Delete()));

    rowSelectEdit = new QAction("&Row", this);
    columnSelectEdit = new QAction("&Column", this);
    allSelectEdit = new QAction("&All", this);
    allSelectEdit->setShortcut(QKeySequence::SelectAll);

    findEdit = new QAction("&Find", this);
    findEdit->setIcon(QIcon("./img/find.png"));
    findEdit->setShortcut(QKeySequence::Find);
    findEdit->setStatusTip("Find Data");

    gotocellEdit = new QAction("&GoTo Cell", this);
    gotocellEdit->setIcon(QIcon("./img/gotocell.png"));
    gotocellEdit->setStatusTip("Gotocell Data");
}

/**Tool Action**/
void MainWindow::CreateToolsAction()
{
    recalTools = new QAction("&Recalculate", this);
    recalTools->setShortcut(tr("F9"));
    recalTools->setStatusTip("Recalculate");

    sortTools = new QAction("&Sort", this);
    sortTools->setStatusTip("Sort");
}


/**Option Action**/
void MainWindow::CreateOptionAction()
{
    showGridOption = new QAction(tr("&Show Grid"), this);
    showGridOption->setCheckable(true);
    //showGridOption->setChecked(spreadsheet->showGrid());
    showGridOption->setStatusTip(tr("Show or hide the spreadsheet's "
                                        "grid"));
    autoRecalcOption = new QAction("&Auto-Recalculate", this);
    autoRecalcOption = new QAction(tr("&Auto-Recalculate"), this);
    autoRecalcOption->setCheckable(true);
    //autoRecalcOption->setChecked(spreadsheet->autoRecalculate());
    autoRecalcOption->setStatusTip(tr("Switch auto-recalculation on or "
                                          "off"));
}


/**About Action**/
void MainWindow::CreateAboutAction()
{
    aboutHelp = new QAction("&About", this);
    connect(aboutHelp, SIGNAL(triggered()), this, SLOT(aboutInfoMBox()));
}


/**ToolBar Action**/
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

void MainWindow::updataBarPosition()
{
    LocationLable->setText(mytable->GetCurrentStatusBar());
}

void MainWindow::CreateStatusBar()
{
    LocationLable = new QLabel("W99");
    statusBar()->addWidget(LocationLable);
    connect(mytable, SIGNAL(currentCellChanged(int,int,int,int)), this, SLOT(updataBarPosition()));
}


void MainWindow::aboutInfoMBox()
{
    QMessageBox::about(this, tr("About"),
                       tr("<h2>MY table</h2><p>Sumelt</p>"));

}

bool MainWindow::oktoContinue()
{
    if(isWindowModified())
    {
        int res = QMessageBox::warning(this, tr("Warning"), tr("Save?"),
                             QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);

        if(res == QMessageBox::Yes)
            return true;
        else if(res == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MainWindow::NewSpreadSheet()
{
    if(oktoContinue())
    {
          mytable->IntSpreadSheet();
//        MainWindow *w2 = new MainWindow(this);
//        SpreadSheet *sheet = new SpreadSheet();
//        w2->setCentralWidget(sheet);
//        w2->show();

    }
}

void MainWindow::CreateContextMenuAction()
{
    mytable->addAction(copyEdit);
    mytable->addAction(pasteEdit);
    mytable->addAction(cutEdit);
    mytable->addAction(deleteEdit);

    //mytable->setContextMenuPolicy(Qt::noc);
    mytable->setContextMenuPolicy(Qt::ActionsContextMenu);

}
