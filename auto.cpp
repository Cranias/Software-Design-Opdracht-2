#include "auto.h"
#include "snelheid.h"

Auto::Auto(Snelheid* pS): S(pS)
{
}

void Auto::meetSnelheid()
{
    S->meet();
    return;
}
