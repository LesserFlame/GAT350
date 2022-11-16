// x01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

template <typename T>
T Add(T i, T j) { return (i + j); }
template <typename T>
T Sqr(T i) { return (i * i); }
template <typename T>
T Max(T i, T j) { return (i > j) ? i : j; }
//return i if greater than j, if not return j
template <typename T>
T Min(T i, T j) { return (i < j) ? i : j; }
//return i if lesser than j, if not return j
int main()
{
    std::cout << "Add 9 + 10 = " + std::to_string(Add<int>(9, 10)) << std::endl;
    std::cout << "Add 9.1f + 10.3f = " + std::to_string(Add<float>(9.1f, 10.3f)) << std::endl;
    std::cout << "Square 5 = " + std::to_string(Sqr<int>(5)) << std::endl;
    std::cout << "Max 12 & 10 = " + std::to_string(Max<int>(12, 10)) << std::endl;    
    std::cout << "Min 142 & 243432 = " + std::to_string(Min<int>(142, 243432)) << std::endl;    
}
