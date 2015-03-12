#ifndef AUTO_H
#define AUTO_H

class Snelheid;

class Auto
{
public:
    Auto(Snelheid*);
    virtual void meetSnelheid();
private:
    Snelheid* S;
};

#endif // AUTO_H
