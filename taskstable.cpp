#include "taskstable.h"
#include "ui_taskstable.h"
#include <QMessageBox>

TasksTable::TasksTable(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TasksTable)
{
    ui->setupUi(this);
    construct();
}

QTableWidget* TasksTable::getTableWidget()
{
    return ui->tableWidget;
}

void TasksTable::construct()
{
    setTableStyleSheet( ui->tableWidget );
    QStringList tableHeaderLables;
    tableHeaderLables << "" << "Tasks" << "T" << "I";
    ui->tableWidget->setHorizontalHeaderLabels( tableHeaderLables );

    ui->tableWidget->setColumnWidth( completedTasksColumn, 25 );
    ui->tableWidget->setColumnWidth( tasksColumn, 200 );
    ui->tableWidget->setColumnWidth( tmatmNumColumn, 25 );
    ui->tableWidget->setColumnWidth( interruptedNumColumn, 25 );
}

void TasksTable::setTableStyleSheet( QTableWidget* table )
{
    QString tableStyleString = "QTableView{ "
                               + baseColor
                               + textColor
                               + borderDesign
                               + "border-bottom-left-radius: 1px;"
                               + "border-bottom-right-radius: 1px;"
                               + " }";

    QString selectionStyleString = "QTableWidget::item:selected { "
                                   + selectionColor
                                   + " }";

    QString tableHeaderStyleSheet = "QHeaderView::section{ "
                                    + baseColor
                                    /*"background-color: qlineargradient(x1:0, y1:0,"
                                    "x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343,"
                                    "stop:1 #656565);"*/
                                    + textColor
                                    //"border-radius: 2px;"
                                    + " }";

    table->setStyleSheet( tableStyleString + selectionStyleString + tableHeaderStyleSheet );

//                          "QHeaderView::section:checked{ background-color: black; }"
//                          "QScrollBar::handler{ border-bottom: 1px solid #1A1A1A; }"
}

int TasksTable::getCurrentRow()
{
//    if(  )
    return ui->tableWidget->currentRow();
}

void TasksTable::removeRow( int row )
{
    // check if this row marked default task
    if( !ui->tableWidget->item( row, tasksColumn )->font().underline() )
        ui->tableWidget->removeRow( row );
}

TasksTable::~TasksTable()
{
    delete ui;
}
