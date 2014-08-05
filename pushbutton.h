#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QPushButton>
#include <QWidget>
#include "staticVariables.h"

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent = 0);

private:
    void reDesign();

signals:

public slots:

};

#endif // PUSHBUTTON_H
