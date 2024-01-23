#include <iostream>
#include <type_traits>

template <typename T>
class Pointer {
public:
    Pointer(T ptr) : pointer(ptr)
    {
        static_assert(std::is_pointer<T>::value);
    }

    typename std::enable_if<std::is_pointer<T>::value, typename std::remove_pointer<T>::type>::type operator*() const
    {
        return *pointer;
    }

private:
    T pointer;
};