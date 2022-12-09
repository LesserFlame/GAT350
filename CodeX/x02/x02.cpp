#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void swap(T* a, T* b)
{
    T* temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    float fa = 12.5f;
    float fb = 14.25f;

    int* pa = &a;
    int* pb = &b;

    float* pfa = &fa;
    float* pfb = &fb;

    //(you don't need to create the references in the main,
    //I just did to differentiate it)
    int& ra = a;
    int& rb = b;

    float& rfa = fa;
    float& rfb = fb;

    //references are able to edit the original variable

    // reference
    swap(ra, rb);
    std::cout << a << " " << b << std::endl;
    
    swap(rfa, rfb);
    std::cout << fa << " " << fb << std::endl;

    // pointers are able to retrieve the original's value,
    //but are unable to edit the original's value directly
    //despite copying it.

    // pointer
    swap(pa, pb);
    std::cout << a << " " << b << std::endl;

    swap(pfa, pfb);
    std::cout << fa << " " << fb << std::endl;

    //for functions that are used to change the value
    //of variables outside of the function, references are
    //useful to avoid having to return the values and setting
    //the variables to the new values from the function.
}
