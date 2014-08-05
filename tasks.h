#ifndef TASKS_H
#define TASKS_H

#include <QObject>
#include <QLayout>

#include "taskstable.h"
#include "tasksbuttonswidget.h"

class Tasks : public QObject
{
    Q_OBJECT

private:
    TasksTable *tasksTable = NULL;
    TasksButtonsWidget *tasksButtonsWidget = NULL;
    int currentTaskRow = -1;

    QWidget *tasksWidget;
    QLayout *mainLayout;

public:
    explicit Tasks(QObject *parent = 0);
    void construct();
    QWidget* getTasksWidget() const;
    void addTask( QString task, int maxTmatm );
    void removeTask( int rowNumber );

protected:
    void switchCurrentTask( int rowNumber );
    void signalsAndSlots();

signals:


private slots:
    void onNewTask();
    void onRemoveTask();

public slots:
    void currentTask( QTableWidgetItem* );

};

#endif // TASKS_H
