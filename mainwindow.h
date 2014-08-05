#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "tasks.h"
#include "staticVariables.h"
#include "trayicon.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Tasks *tasks;
    TrayIcon *trayIcon;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//    void quit();
};

#endif // MAINWINDOW_H
