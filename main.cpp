#include "Observer.h"
#include "auto.h"
#include "snelheid.h"
#include "digitalemeter.h"
#include "analogemeter.h"

int main()
{
    Snelheid S;
    DigitaleMeter DM ( &S );
    AnalogeMeter AM ( &S );
    Auto A ( &S );
    A.meetSnelheid( );
    
    return 0;
}

