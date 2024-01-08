#include "ReferenceCounter.h"

void ReferenceCounter::increment()
{
    counter++;
}

void ReferenceCounter::decrement()
{
    counter--;
}

int ReferenceCounter::getCounter() const
{
    return counter;
}