#include "pushbutton.h"

PushButton::PushButton(QWidget *parent) :
    QPushButton(parent)
{
    reDesign();
}

void PushButton::reDesign()
{
    this->setStyleSheet( "QPushButton{ "
                         + selectionColor
                         + "color: white;"
                         + "border-radius: 4px;"
                         + "border: 1px solid #9C1E3F; }"
                         + "QPushButton:pressed {"
                         + "background-color: #9C1E3F; }");

    this->setFixedSize( 80, 20 );
    this->setFocusPolicy( Qt::NoFocus );
}
