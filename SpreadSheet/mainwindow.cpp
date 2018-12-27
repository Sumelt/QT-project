#include "mainwindow.h"
#include "SpreadSheet.h"
#include "ui_mainwindow.h"

class SpreadSheet;

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

    resize(1300,800);
    move(400,250);
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

    SelectEditMenu = EditMenu->addMenu("&Select");
    SelectEditMenu->addAction(rowSelectEdit);
    SelectEditMenu->addAction(columnSelectEdit);
    SelectEditMenu->addAction(allSelectEdit);
    //EditMenu->addMenu(SelectEditMenu);

    EditMenu->addSeparator();
    EditMenu->addAction(findEdit);   
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
    connect(openFile, SIGNAL(triggered()), this, SLOT(opend()));

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

    //selectEdit = new QAction("&Seclect", this);
    //selectEdit->setShortcut(QKeySequence::Select);
    //selectEdit->setStatusTip("Select Data");

    rowSelectEdit = new QAction("&Row", this);
    columnSelectEdit = new QAction("&Column", this);
    allSelectEdit = new QAction("&All", this);
    allSelectEdit->setShortcut(QKeySequence::SelectAll);

    findEdit = new QAction("&Find", this);
    findEdit->setIcon(QIcon("./img/find.png"));
    findEdit->setShortcut(QKeySequence::Find);
    findEdit->setStatusTip("Find Data");
    connect(findEdit, SIGNAL(triggered()), this, SLOT(find()));

    gotocellEdit = new QAction("&GoTo Cell", this);
    gotocellEdit->setIcon(QIcon("./img/gotocell.png"));
    gotocellEdit->setStatusTip("Gotocell Data");
    connect(gotocellEdit, SIGNAL(triggered()), this, SLOT(gotocell()));
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
    showGridOption->setChecked(true);
    //showGridOption->setChecked(spreadsheet->showGrid());
    showGridOption->setStatusTip(tr("Show or hide the spreadsheet's "
                                        "grid"));
    connect(showGridOption, SIGNAL(toggled(bool)), this, SLOT(showGrid(bool)));

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
    //qDebug()<<mytable->isWindowModified();
    if (mytable->isWindowModified()) {
            int r = QMessageBox::warning(this, tr("Spreadsheet"),
                            tr("The document has been modified.\n"
                               "Do you want to save your changes?"),
                            QMessageBox::Yes | QMessageBox::No
                            | QMessageBox::Cancel);
            if (r == QMessageBox::Yes) {
                return true;//save();
            } else if (r == QMessageBox::Cancel) {
                return false;
            }
        }
        return true;
}

void MainWindow::NewSpreadSheet()
{
    if(oktoContinue())
    {
          //mytable->IntSpreadSheet();
          //mytable->clear();
          //setCurrentFile("");
        MainWindow *newWindow = new MainWindow;
        newWindow->show();
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

void MainWindow::find()
{
    if(!findDialog)
    {
        findDialog = new FindDialog(this);

        //connect button siganl to sheet about next
         connect(findDialog, SIGNAL(findNext(QString,Qt::CaseSensitivity)),
                 mytable, SLOT(findNext(QString,Qt::CaseSensitivity)));

        //connect button siganl to sheet about previous
        connect(findDialog, SIGNAL(findPrevious(QString,Qt::CaseSensitivity)),
                mytable, SLOT(findPrevious(QString,Qt::CaseSensitivity)));
        \
    }

    findDialog->show();
    findDialog->raise();
    findDialog->activateWindow();

}

void MainWindow::gotocell()
{
    GoToCellDialog *gotocellDialog = new GoToCellDialog(this);
    if(gotocellDialog->exec())
    {
        QString str = gotocellDialog->lineEdit->text().toUpper();
        mytable->setCurrentCell(str.mid(1).toInt()-1, str[0].unicode()-'A');
    }
    delete gotocellDialog;
}

void MainWindow::hideSpreadSheet()
{
    QPalette pal = mytable->palette();
    pal.setBrush(QPalette::Base,QBrush(QColor(255,255,255,0)));
    mytable->setPalette(pal);
}

void MainWindow::showGrid(bool flag)
{
    if(flag)
        mytable->setShowGrid(true);
    else mytable->setShowGrid(false);
}

void MainWindow::opend()
{
    if(!oktoContinue())
    {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                "." ,tr("Spreadsheet File (*.sp)"));
        //if(!fileName.isEmpty())
            //loadFile(fileName);
    }
}
