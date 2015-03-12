#include "analogemeter.h"
#include <iostream>

using namespace std;

AnalogeMeter::AnalogeMeter(Snelheid* s): Observer(s)
{}

void AnalogeMeter::update()
{
    cout<<static_cast<Snelheid*>(getSubject())->geef()<<endl;
    return;
}
