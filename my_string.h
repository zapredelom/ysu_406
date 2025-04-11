#include "my_string.h"
#include <iostream>

my_string::my_string(const char* str)
{
    _size = 0;
    while (str[_size] != '\0')
        _size++;

    _str = new char[_size];

    for (int i = 0; i < _size; i++)
        _str[i] = str[i];
}

my_string::my_string(const char c)
    : _size(1)
    , _str(new char(c))
{
}
my_string::my_string()
    : _size(0)
    , _str(nullptr)
{
}

void my_string::print()
{
    for (int i = 0; i < _size; i++) {
        std::cout << _str[i];
    }
}

my_string my_string::sub_str(int b, int e)
{
    my_string ret;
    b = b > _size ? _size : b;
    ret._size = e - b;
    ret._str = new char[_size];
    for (int i = 0; i < ret._size; i++) {
        ret._str[i] = _str[b + i];
    }
    return ret;
}

my_string::~my_string()
{
    if (_size == 1) {
        delete _str;
    } else {
        delete[] _str;
    }
    _size = 0;
    _str = nullptr;
}
