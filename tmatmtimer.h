#ifndef TMATMTIMER_H
#define TMATMTIMER_H

#include "timer.h"
//#include <QObject>

class TmatmTimer : public Timer
{
    Q_OBJECT

public:
    TmatmTimer( int minutes, QObject *parent );

private:
    int minutes = 0;

protected:
    void timerChanged();
    void startTicking();
    void timerConstruction();
};

#endif // TMATMTIMER_H
