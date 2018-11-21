#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QTableWidget>
#include <QApplication>
#include <QString>
#include <QClipboard>

class SpreadSheet : public QTableWidget
{
    Q_OBJECT

public:
    SpreadSheet(SpreadSheet *parent = 0);
    void IntSpreadSheet();
    QString GetCurrentStatusBar();

private:
    enum{RowCount = 99, ColumCount = 26};

private slots:
    void Copy();
    void Paste();
    void Cut();
    void Delete();


};

#endif // SPREADSHEET_H
