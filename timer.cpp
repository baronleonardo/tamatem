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

#include "timer.h"


Timer::Timer( int hours, int minutes, int seconds, QObject *parent ) :
    QObject( parent )
{
    setSeconds( seconds );
    setMinutes( minutes );
    setHours( hours );

    time = new QTime( 0, 0, 0 );
    timer = new QTimer( this );
}

Timer::Timer( QObject *parent ) :
    QObject( parent )
{
    time = new QTime( 0, 0, 0 );
    timer = new QTimer( this );
}

void Timer::setHours( int hours )
{
    if( hours > 24 )
    {
        this->hours = 24;
        this->minutes = 0;
        this->seconds = 0;
    }

    else
        this->hours = hours;
}

void Timer::setMinutes( int minutes )
{
    if( minutes >= 60 )
    {
        this->hours += minutes / 60;
        this->minutes = minutes % 60;
    }

    else
        this->minutes = minutes;
}

void Timer::setSeconds( int seconds )
{
    if( seconds >= 60 )
    {
        this->minutes += seconds / 60;
        this->seconds = seconds % 60;
    }

    else
        this->seconds = seconds;
}

void Timer::timerConstruction()
{
    connect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );

    timer->start( 1000 );
}

void Timer::startTicking()
{
    ++secondCounting;
    timerChanged();
}

void Timer::timerChanged()
{
    emit onSecondsChanged( secondCounting );

    if( secondCounting == numOfSecondsInMinute )
    {
        secondCounting = 0;
        emit onMinutesChanged( ++minutesCounting );
    }

    if( minutesCounting == numOfMinutesInHour )
    {
        minutesCounting = 0;
        emit onHoursChanged( ++hoursCounting );
    }

    if( hoursCounting == hours && minutesCounting == minutes &&
            secondCounting == seconds )
    {
        emit timerFinished();
    }
}

void Timer::restartTimer()
{
    hoursCounting = 0;
    minutesCounting = 0;
    secondCounting = 0;
}

void Timer::stopTimer()
{
    timer->stop();
    restartTimer();

    disconnect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );
}

void Timer::pauseTimer()
{
    if( timer != NULL )
    {
        disconnect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );
        timer->stop();
    }
}

void Timer::resumeTimer()
{
    if( secondCounting != 0 )
    {
//        connect( timer, SIGNAL(timeout()), this, SLOT(startTicking()) );
//        timer->start( 1000 );
        timerConstruction();
        startTicking();
    }
}

void Timer::onTimerFinish()
{
    stopTimer();
}
