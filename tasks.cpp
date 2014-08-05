#include "tasks.h"
#include <QMessageBox>

Tasks::Tasks(QObject *parent) :
    QObject(parent)
{
//    construct();
}

void Tasks::construct()
{
    tasksWidget = new QWidget();
        tasksWidget->setContentsMargins( -10, -10, -10, -10 );
    tasksTable = new TasksTable();
    tasksButtonsWidget = new TasksButtonsWidget();

    mainLayout = new QVBoxLayout( tasksWidget );
    mainLayout->setSpacing( 0 );
        mainLayout->addWidget( tasksTable->getTableWidget() );
        mainLayout->addWidget( tasksButtonsWidget->getButtonsWidget() );

    tasksWidget->setLayout( mainLayout );

    signalsAndSlots();
}

void Tasks::addTask( QString task, int maxTmatm )
{
    int RowsCount = tasksTable->getTableWidget()->rowCount();
    QTableWidget *table = tasksTable->getTableWidget();

    table->insertRow( RowsCount );

//    ui->tableWidget->item( ui->tableWidget->rowCount() , ui->tableWidget->columnCount() )->setText( task );
//    tableWidgetItem = ui->tableWidget->item( ui->tableWidget->rowCount(), tmatmNumColumn );

    int currentRowIndex = table->rowCount() - 1;

    // task
    QTableWidgetItem *taskBox = new QTableWidgetItem;
    taskBox->setText( task );
        table->setItem( currentRowIndex, tasksTable->tasksColumn, taskBox );

    // maximum Tmatm
    QTableWidgetItem *maxTmatmBox = new QTableWidgetItem;
    maxTmatmBox->setText( QString::number( maxTmatm ) );
        table->setItem( currentRowIndex, tasksTable->tmatmNumColumn, maxTmatmBox );

    // Num of Interruptions
    QTableWidgetItem *interruptedNumBox = new QTableWidgetItem;
    interruptedNumBox->setText( QString::number( 0 ) );
        table->setItem( currentRowIndex, tasksTable->interruptedNumColumn, interruptedNumBox );

//    delete tableWidgetItem;
//    tableWidgetItem = NULL;
}

QWidget* Tasks::getTasksWidget() const
{
    if( tasksWidget != NULL )
        return tasksWidget;

    return NULL;
}

void Tasks::removeTask( int rowNumber )
{
    tasksTable->getTableWidget()->removeRow( rowNumber );
}

void Tasks::currentTask( QTableWidgetItem* itm )
{
    if( tasksTable != NULL )
    {
        QFont font;

        if( currentTaskRow != itm->row() )
        {
            if( currentTaskRow != -1 )
                switchCurrentTask( currentTaskRow );

            currentTaskRow = itm->row();

            font.setBold( true );
//            font.setCapitalization( QFont::AllUppercase );
            font.setUnderline( true );

            for( int column = tasksTable->tasksColumn;
                 column < tasksTable->numOfColumns;
                 ++column )
            {
                tasksTable->getTableWidget()->item( currentTaskRow, column )
                        ->setFont( font );
                tasksTable->getTableWidget()->item( currentTaskRow, column )
                        ->setTextColor( Qt::white );
            }
        }
    }
}

void Tasks::switchCurrentTask( int rowNumber )
{
    QFont font;
    font.setBold( false );
//    font.setCapitalization( QFont::AllLowercase );
    font.setUnderline( false );

    for( int column = tasksTable->tasksColumn;
         column < tasksTable->numOfColumns;
         ++column )
    {
        tasksTable->getTableWidget()->item( rowNumber, column )
                ->setFont( font );
        tasksTable->getTableWidget()->item( rowNumber, column )
                ->setTextColor( QColor( "#E6E6E6" ) );
    }
}

void Tasks::signalsAndSlots()
{
    connect( tasksTable->getTableWidget(), SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
             this, SLOT(currentTask(QTableWidgetItem*)) );
    connect( tasksButtonsWidget, SIGNAL( onRemoveTaskButtonClicked() ), this, SLOT( onRemoveTask() ) );
    connect( tasksButtonsWidget, SIGNAL( onAddTaskButtonClicked() ), this, SLOT( onNewTask() ) );
}

void Tasks::onRemoveTask()
{
    int currentRow = tasksTable->getCurrentRow();
    tasksTable->removeRow( currentRow );
}

void Tasks::onNewTask()
{

}
