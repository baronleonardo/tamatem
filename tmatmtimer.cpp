#include "tmatmtimer.h"

TmatmTimer::TmatmTimer( int minutes, QObject *parent ) :
    Timer( parent )
{
    this->minutes = minutes;
    timerConstruction();
    startTicking();
}

void TmatmTimer::timerConstruction()
{
    minutes = minutesCounting;

    Timer::timerConstruction();
}

void TmatmTimer::startTicking()
{
    --secondCounting;
    timerChanged();
}

void TmatmTimer::timerChanged()
{
    emit onSecondsChanged( secondCounting );

    if( secondCounting == 0 && minutesCounting != minutes )
    {
        secondCounting = numOfSecondsInMinute;
        emit onMinutesChanged( --minutesCounting );
    }

    if( minutesCounting == 0 && secondCounting == 0 )
    {
        emit timerFinished();
    }
}
