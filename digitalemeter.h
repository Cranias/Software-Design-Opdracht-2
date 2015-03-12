#include "Observer.h"
#include "snelheid.h"

#ifndef DIGITALEMETER_H
#define DIGITALEMETER_H

class DigitaleMeter : public Observer
{
public:
    DigitaleMeter(Snelheid*);
    void update();
};

#endif // DIGITALEMETER_H
