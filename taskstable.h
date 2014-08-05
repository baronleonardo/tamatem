#ifndef TASKSTABLE_H
#define TASKSTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "staticVariables.h"

namespace Ui {
class TasksTable;
}

class TasksTable : public QWidget
{
    Q_OBJECT

private:
    QTableWidgetItem *tableWidgetItem;

public:
    explicit TasksTable(QWidget *parent = 0);
    QTableWidget* getTableWidget();
//    QTableWidget* getTasksTable();
    void construct();
    int getCurrentRow();
    void removeRow( int row );
    ~TasksTable();

private:

public:
    const int numOfColumns = 4;
    const int completedTasksColumn = 0;
    const int tasksColumn = 1;
    const int tmatmNumColumn = 2;
    const int interruptedNumColumn = 3;

private:
    void setTableStyleSheet( QTableWidget* table );

private:
    Ui::TasksTable *ui;
};

#endif // TASKSTABLE_H
