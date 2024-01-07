#pragma once
#include "ReferenceCounter.h"

template<typename T>
class SmartPointer
{
public:
    SmartPointer(T* ptr = nullptr);
    SmartPointer(const SmartPointer<T>& other);
    ~SmartPointer();

    SmartPointer<T>& operator=(const SmartPointer<T>& obj);
    T& operator*();
    T* operator->();

private:
    T* pointer;
    ReferenceCounter* counter;

};

template<typename T>
SmartPointer<T>::SmartPointer(T* ptr)
{
    pointer = ptr;
    counter = new ReferenceCounter();
    counter->increment();
}

template<typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T>& other)
{
    pointer = other.pointer;
    counter = other.counter;
    counter->increment();
}

template<typename T>
SmartPointer<T>::~SmartPointer()
{
    counter->decrement();
    if (counter->getCounter() == 0)
    {
        delete pointer;
        delete counter;
    }
}

template<typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& obj)
{
    if (this != &obj)
    {
        counter->decrement();
        if (counter->getCounter() == 0)
        {
            delete pointer;
            delete counter;
        }
        pointer = obj.pointer;
        counter = obj.counter;
        counter->increment();
    }
    return *this;
}

template<typename T>
T& SmartPointer<T>::operator*()
{
    return *pointer;
}

template<typename T>
T* SmartPointer<T>::operator->()
{
    return pointer;
}