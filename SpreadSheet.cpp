#include "SpreadSheet.h"
#include <QString>

SpreadSheet::SpreadSheet(SpreadSheet *parent)
{
    IntSpreadSheet();
}

void SpreadSheet::IntSpreadSheet()
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
    setCurrentCell(0, 0);
}

QString SpreadSheet::GetCurrentStatusBar()
{
    QString data = QChar(currentColumn()+'A')
                    +QString::number(currentRow()+1);
    return data;
}

void SpreadSheet::Copy()
{
    QString context = item(currentRow(), currentColumn())->text();
    QApplication::clipboard()->setText(context);
}

void SpreadSheet::Paste()
{
    QTableWidgetItem *item = new QTableWidgetItem;
    QString str = QApplication::clipboard()->text();

    item->setText(str);
    setItem(currentRow(), currentColumn(), item);

}

void SpreadSheet::Cut()
{
    Copy();
    Delete();
}

void SpreadSheet::Delete()
{
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText("");
    setItem(currentRow(), currentColumn(), item);
}

void SpreadSheet::findNext(const QString &str, Qt::CaseSensitivity cs)
{
    int row = currentRow();
    int column = currentColumn() + 1;

        while (row <= RowCount) {
            while (column <= ColumCount) {

                if (item(row, column)) {
                    if(item(row, column)->text().contains(str, cs)){

                        clearSelection();
                        setCurrentCell(row, column);
                        activateWindow();
                        return;
                    }

                }
                ++column;
            }
            column = 0;
            ++row;
        }

}

void SpreadSheet::findPrevious(const QString &str, Qt::CaseSensitivity cs)
{
    int row = currentRow();
    int column = currentColumn() - 1;

        while (row >= 0) {
            while (column >= 0) {

                if (item(row, column)) {
                    if(item(row, column)->text().contains(str, cs)){

                        clearSelection();
                        setCurrentCell(row, column);
                        activateWindow();
                        return;
                    }

                }
                --column;
            }
            column = ColumCount;
            --row;
        }
}


