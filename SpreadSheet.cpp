#include "SpreadSheet.h"
#include <QString>
SpreadSheet::SpreadSheet()
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

QString SpreadSheet::GetCurrentStatusBar()
{
    QString data = QChar(currentColumn()+'A')
                    +QString::number(currentRow()+1);
    return data;
}
