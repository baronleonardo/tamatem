#include "trayicon.h"
#include <QMessageBox>

TrayIcon::TrayIcon(QObject *parent) :
    QObject(parent)
{
    construct();
}

void TrayIcon::construct()
{
    tray = new QSystemTrayIcon( this );

    righClickedMenuConstruction();
    tray->setContextMenu( getMenu() );

    tray->show();

    signalsAndSlots();

//    QIcon trayIcon( ":/icons/whiteIcon" );
//    tray->setIcon( trayIcon );
    trayIconStyle( tray );
}

void TrayIcon::trayIconStyle( QSystemTrayIcon *tray )
{
// User could choose white or black Icon
    QIcon trayIcon( ":/icons/whiteIcon" );
    tray->setIcon( trayIcon );

    reconstructTrayIconOnTimeChange( 1 );
    reconstructTrayIconOnTimeChange( 3 );
    reconstructTrayIconOnTimeChange( 59 );
}

void TrayIcon::reconstructTrayIconOnTimeChange( int timer )
{
    // User Choose color of timer
    if( tray != NULL )
    {
        QRect rect( 0, 0, tray->geometry().width(), tray->geometry().height() );

        QPixmap *pixmap = new QPixmap( rect.size() );
        pixmap->fill( Qt::transparent );
//        pixmap->load( iconDestination );

        QPainter *painter = new QPainter();
        painter->begin( pixmap );
            QFont font;
                font.setBold( true );
                font.setPointSize( 12 );
            painter->setFont( font );
            painter->setPen( Qt::white );
            painter->setRenderHint( QPainter::Antialiasing );

            painter->drawText( rect, Qt::AlignCenter,
                               QString::number( timer ) );
        painter->end();

        tray->setIcon( *pixmap );

        delete painter;
        delete pixmap;
    }
}

void TrayIcon::righClickedMenuConstruction()
{
    menu = new QMenu();
    menu->addAction( "Preference" );
    menu->addSeparator();
    menu->addAction( "Quit" );
}

QMenu* TrayIcon::getMenu() const
{
    if( menu != NULL )
        return menu;

    return NULL;
}

void TrayIcon::signalsAndSlots()
{
    if( menu != NULL && tray != NULL )
    {
        // Quit Menu
        connect( tray->contextMenu()->actions().at( quitMenu ), SIGNAL( triggered() ),
                 this, SLOT( onQuitPressed() ) );

        // Preference Menu
        connect( tray->contextMenu()->actions().at( preferenceMenu ), SIGNAL( triggered() ),
                 this, SLOT( onPreferencePressed() ) );
    }
}

void TrayIcon::onPreferencePressed()
{
    emit preferencePressed();
}

void TrayIcon::onQuitPressed()
{
    emit quitPressed();
}
