#include <iostream>
#include <memory>
#include "SmartPointer.h"

template <typename T>
class MyArray {
private:
    std::shared_ptr<T[]> data;
    std::shared_ptr<size_t> count;
    int n;


public:
    MyArray(size_t size) : n(size), count(std::make_shared<size_t>(1)) {
        data = std::shared_ptr<T[]>(new T[n], std::default_delete<T[]>());
    }

    MyArray(const MyArray& other) : data(other.data), n(other.n), count(other.count) {
        (*count)++;
    }

    MyArray(MyArray&& other) noexcept : data(std::move(other.data)), n(other.n), count(other.count) {
        other.n = 0;
        other.count = nullptr;
    }

    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            data = other.data;
            n = other.n;
            count = other.count;
            (*count)++;
        }
        return *this;
    }

    MyArray& operator=(MyArray&& other) noexcept
            {
        if (this != &other) {
            data = std::move(other.data);
            n = other.n;
            count = other.count;
            other.n = 0;
            other.count = nullptr;
        }
        return *this;
    }

    int size() const {
        return n;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    ~MyArray() {
        if (count && --(*count) == 0) {
        }
    }
};


