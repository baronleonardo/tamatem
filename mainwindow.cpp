#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowFlags( Qt::FramelessWindowHint );

    tasks = new Tasks();
    tasks->construct();

    trayIcon = new TrayIcon( this );

    QVBoxLayout *layout = new QVBoxLayout( this );
    layout->addWidget( tasks->getTasksWidget() );

    QWidget *wid = new QWidget( this );
//    wid->setContentsMargins( -10, -10, -10, -10 );
    this->setStyleSheet( /*"border: 4px solid red;"*/
                         "border-radius: 6px;");
    setCentralWidget( wid );
    wid->setLayout( layout );
    wid->setStyleSheet( baseColor );

    tasks->addTask( "test", 7 );
    tasks->addTask( "test", 7 );
    tasks->addTask( "test", 7 );
    tasks->removeTask( 2 );
    tasks->addTask( "test", 7 );

    connect( trayIcon, SIGNAL( quitPressed() ), this, SLOT( close() ) );

}

MainWindow::~MainWindow()
{
}
