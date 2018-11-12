#include "SpreadSheet.h"
#include <QString>
SpreadSheet::SpreadSheet(QWidget *parent)
{
    setRowCount(0);
    setColumnCount(0);

    setRowCount(RowCount);
    setColumnCount(ColumCount);

    for(int i = 0; i<ColumCount; i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString(QChar('A'+i)));
        setHorizontalHeaderItem(i, item);
    }

}
