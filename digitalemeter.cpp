#include "digitalemeter.h"
#include <iostream>

using namespace std;

DigitaleMeter::DigitaleMeter(Snelheid *s): Observer(s)
{}

void DigitaleMeter::update()
{
    cout<<static_cast<Snelheid*>(getSubject())->geef()<<endl;
    return;
}
