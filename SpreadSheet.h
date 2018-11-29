#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QTableWidget>
#include <QApplication>
#include <QString>
#include <QClipboard>
#include <Qt>
#include <QDebug>

class SpreadSheet : public QTableWidget
{
    Q_OBJECT

public:
    SpreadSheet(SpreadSheet *parent = 0);
    void IntSpreadSheet();
    QString GetCurrentStatusBar();

private:
    enum{RowCount = 99, ColumCount = 26};

signals:

public slots:
    void Copy();
    void Paste();
    void Cut();
    void Delete();
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    //void findPrevious(const QString &str, Qt::CaseSensitivity cs);

};

#endif // SPREADSHEET_H
