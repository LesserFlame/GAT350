#include <iostream>

int main()
{
    int i1 = 10;
    int i2 = 30;

    int& ir = i1;
    int* ip = &i2;

    // to declare a reference variable, what symbol do you use?
    // -> &

    // to declare a pointer variable, what symbol do you use?
    // -> *

    // to get an address of a variable, what symbol do you use?
    // -> & on an already declared variable

    ir = 20;
    std::cout << i1 << std::endl;
    // once a reference is assigned to a variable, can it later reference a different varaible?
    // -> no
    // can a reference be null?
    // -> no
    // can you declare a reference and not assign it when declared ( int& i; ) ?
    // -> no
    std::cout << &i1 << std::endl;
    std::cout << &ir << std::endl;
    // are the addresses of a reference and the variable it is referencing the same?
    // -> yes

    // display the value the pointer is pointing at (dereference)
    // https://cplusplus.com/doc/tutorial/pointers/
    std::cout << *ip << std::endl;

    // explain what it means to dereference a pointer
    // -> when you dereference a pointer, you are grabbing the value set at the address of the pointer.
    // can a pointer be null?
    // -> yes
    // can you dereference a null pointer (explain)?
    // -> no, if you try to derefence a null pointer it crashes because it doesn't have an address set to it, and is unable to get any values, resulting in undefined behavior
    std::cout << &i2 << std::endl;
    std::cout << &ip << std::endl;
    // are the addresses of a pointer and the object it is pointing to the same?
    // -> no

    // ** pointers are variables with their own address
    // ** a reference is an alias (another name for) the object it is refering to

    ip = &i1;
    // once a pointer is pointing to a variable, can it later point to a different varaible?
    // -> yes, pointers can be reassigned to different variables and stores different addresses.

    // read the following page
    // https://www.geeksforgeeks.org/pointers-vs-references-cpp/
    // when should a pointer be used and when should a reference be used?
    // -> a pointer should be used when you are planning on using data structures and/ or need to have the ability to have null values, and references are used when you want to alter the value of a variable outside of the scope it is in.
}