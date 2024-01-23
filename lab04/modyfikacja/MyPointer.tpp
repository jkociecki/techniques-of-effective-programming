template<typename T> class MyPointer;


template<typename T>
class MyPointer<T[]>
{
public:
    T* val;
    MyPointer(T* ptr) : val(ptr) {}
    T& operator[](int index) { return val[index]; }
};
