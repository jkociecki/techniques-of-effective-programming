#include "SmartPointer.h"

template <typename T>
class MyArray
        {
private:
    SmartPointer<T> data;
    int n;

public:
    MyArray(int size) : n(static_cast<int>(size))
    {
        data = SmartPointer<T>(new T[n]);
    }

    MyArray(const MyArray& other) : data(other.data), n(other.n) {}

    MyArray(MyArray&& other) noexcept : data(std::move(other.data)), n(other.n)
    {
        other.n = 0;
    }

    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            data = other.data;
            n = other.n;
            //count = other.count;
        }
        return *this;
    }

    MyArray& operator=(MyArray&& other) noexcept
            {
        if (this != &other) {
            data = std::move(other.data);
            n = other.n;
            //count = std::move(other.count);
            other.n = 0;
        }
        return *this;
    }

    int size() const
    {
        return n;
    }

    T& operator[](int index)
    {
        return data.operator->()[index];
    }

    const T& operator[](int index) const
    {
        return data.operator->()[index];
    }
    ~MyArray() = default;
};


