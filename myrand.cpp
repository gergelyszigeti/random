#include "myrand.h"

unsigned int MyRand::myrand()
{
    rand_state *= 65327;      // the day when I was exactly -14 years old (my birthday is not prime :( )
    rand_state ^= rand_state >> 5;
    return rand_state;
}

