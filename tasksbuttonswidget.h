#ifndef TASKSBUTTONSWIDGET_H
#define TASKSBUTTONSWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLayout>
#include <QSpacerItem>

#include "pushbutton.h"

class TasksButtonsWidget : public QObject
{
    Q_OBJECT

private:
    QWidget *buttonsWidget = NULL;
    QHBoxLayout *layout = NULL;

    QSpacerItem *space = NULL;
    PushButton *addNewTask = NULL;
    PushButton *removeThisTask = NULL;

private:
    void widgetDesign( QWidget *widget );
    void signalsAndSlots();

public:
    explicit TasksButtonsWidget(QObject *parent = 0);
    void construct();
    QWidget *getButtonsWidget();

signals:
    void onRemoveTaskButtonClicked();
    void onAddTaskButtonClicked();

public slots:
    void addTaskButtonClicked();
    void removeTaskButtonClicked();

};

#endif // TASKSBUTTONSWIDGET_H
