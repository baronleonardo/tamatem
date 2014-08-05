#include "tasksbuttonswidget.h"
#include <QMessageBox>

TasksButtonsWidget::TasksButtonsWidget(QObject *parent) :
    QObject(parent)
{
    construct();
    widgetDesign( buttonsWidget );
}

void TasksButtonsWidget::construct()
{
    buttonsWidget = new QWidget();
    layout = new QHBoxLayout( buttonsWidget );
        space = new QSpacerItem( 40, 20, QSizePolicy::Expanding, QSizePolicy::Fixed );
        addNewTask = new PushButton( buttonsWidget );
            addNewTask->setText( "New" );
        removeThisTask = new PushButton( buttonsWidget );
            removeThisTask->setText( "Remove" );
    layout->addItem( space );
    layout->addWidget( addNewTask );
    layout->addWidget( removeThisTask );

    buttonsWidget->setLayout( layout );

    signalsAndSlots();
}

void TasksButtonsWidget::widgetDesign( QWidget *widget )
{
    widget->setStyleSheet( "background-color: qlineargradient(spread:pad, "
                           "x1:1, y1:1, x2:1, y2:0, stop:0.1 #070709,"
                           "stop:0.5 #111113, stop:0.85 #0C0D0F, stop:1 #070709);"
                           "border-top-left-radius: 1px;"
                           "border-top-right-radius: 1px;");
}

QWidget* TasksButtonsWidget::getButtonsWidget()
{
    if( buttonsWidget != NULL )
        return buttonsWidget;

    return NULL;
}

void TasksButtonsWidget::signalsAndSlots()
{
    if( addNewTask != NULL && removeThisTask != NULL )
    {
        QObject::connect( addNewTask, SIGNAL( clicked() ), this, SLOT( addTaskButtonClicked() ) );
        QObject::connect( removeThisTask, SIGNAL( clicked() ), this, SLOT( removeTaskButtonClicked() ) );
    }
}

void TasksButtonsWidget::addTaskButtonClicked()
{
    emit onAddTaskButtonClicked();
}

void TasksButtonsWidget::removeTaskButtonClicked()
{
//    QMessageBox::information( 0, "ss", "sssss" );
    emit onRemoveTaskButtonClicked();
}
