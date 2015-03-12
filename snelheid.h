#include <iostream>
#include "Observer.h"

#ifndef SNELHEID_H
#define SNELHEID_H

using namespace std;

class Snelheid : public Subject
{
public:
    Snelheid();
    virtual void meet(){cin>>waarde; notify();}
    virtual float geef(){return waarde;}
private:
    float waarde;
};

#endif // SNELHEID_H
