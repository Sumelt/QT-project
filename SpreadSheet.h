#ifndef SPREADSHEET_H
#define SPREADSHEET_H
#include <QTableWidget>

class SpreadSheet : public QTableWidget
{
public:
    SpreadSheet(QWidget *parent = 0);

private:
    enum{RowCount = 99, ColumCount = 26};


};

#endif // SPREADSHEET_H
