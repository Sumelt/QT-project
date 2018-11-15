#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QTableWidget>

class SpreadSheet : public QTableWidget
{
public:
    SpreadSheet();
    QString GetCurrentStatusBar();

private:
    enum{RowCount = 99, ColumCount = 26};


};

#endif // SPREADSHEET_H
