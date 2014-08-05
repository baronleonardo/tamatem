#ifndef TRAYICON_H
#define TRAYICON_H

#include <QObject>
#include <QSystemTrayIcon>
#include <QPixmap>
#include <QPainter>
#include <QFont>
#include <QRect>
#include <QMenu>

class TrayIcon : public QObject
{
    Q_OBJECT

private:
    QSystemTrayIcon *tray = NULL;
    QMenu *menu = NULL;

private:
    const short preferenceMenu = 0;
    const short separatorInMenu = 1;
    const short quitMenu = 2;

private:
    void construct();
    void trayIconStyle( QSystemTrayIcon *tray );
    void reconstructTrayIconOnTimeChange( int timer );
    void righClickedMenuConstruction();
    void signalsAndSlots();

public:

public:
    explicit TrayIcon(QObject *parent = 0);
    QMenu* getMenu() const;

private slots:
    void onQuitPressed();
    void onPreferencePressed();

signals:
    void preferencePressed();
    void quitPressed();

public slots:

};

#endif // TRAYICON_H
