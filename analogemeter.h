#include "Observer.h"
#include "snelheid.h"

#ifndef ANALOGEMETER_H
#define ANALOGEMETER_H

class AnalogeMeter : public Observer
{
public:
    AnalogeMeter(Snelheid*);
    void update();
};

#endif // ANALOGEMETER_H
