//=========================================
//
// Made by : Baron Leonardo
// E-mail  : mohamedayman.fcis@zoho.com
//
// This work is done under GPL licence
// to read Licence's terms read licence file
// wich indecates :
// ***the freedom to use the software for any purpose,
// ***the freedom to change the software to suit your needs,
// ***the freedom to share the software with your friends and neighbors, and
// ***the freedom to share the changes you make.
//
//=========================================

// This is a timer for timer less than or equal to 24 hrs

#ifndef TIMER_H
#define TIMER_H

#include <QTimer>
#include <QTime>
#include <QObject>


class Timer : public QObject
{
    Q_OBJECT

public:
    explicit Timer( int hours, int minutes, int seconds, QObject *parent = 0 );
    explicit Timer( QObject *parent = 0 );

private:
    QTimer *timer= NULL;

    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    QTime *time = NULL;

public:
    const int numOfSecondsInMinute = 60;
    const int numOfMinutesInHour = numOfSecondsInMinute;

protected:
    int hoursCounting = 0;
    int minutesCounting = 0;
    int secondCounting = 0;

protected:
    void timerChanged();
    void setHours( int hours );
    void setMinutes( int minutes );
    void setSeconds( int seconds );

signals:
    void onSecondsChanged( short );
    void onMinutesChanged( short );
    void onHoursChanged( short );
    void timerFinished();

public slots:
    void startTicking();
    void restartTimer();
    void timerConstruction();
    void stopTimer();
    void pauseTimer();
    void resumeTimer();
    void onTimerFinish();

signals:

};

#endif // TIMER_H
