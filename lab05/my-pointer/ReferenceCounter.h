#pragma once
#include <iostream>

class ReferenceCounter
{
public:
    ReferenceCounter() : counter(0) {};
    void increment();
    void decrement();
    [[nodiscard]] int getCounter() const;

    private:
    int counter;
};