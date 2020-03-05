#include <iostream>

void someFunc(int, double)
{
    
}

template<typename T>
void f(std::initializer_list<T> initList)
{
    
}

int main () 
{
    std::cout << "Main Application: Item 02" << std::endl;
    
    
    auto x = 27;            // case 3: (x is neither ptr nor reference)
    const auto cx = x;      // case 3: (cx isn't either)
    const auto& rx = x;     // case 1: (rx is a non-universal reference)
    
    auto&& uref1 = x;       // x is int and lvalue, so uref's type is int&
    auto&& uref2 = cx;      // cx is const int and lvalue, so uref2's type is const int&
//    auto&& uref3 = rx;      // rx is const int& and lvalue, so uref's type is const int&
    auto&& uref3 = 27;       // 27 is int and rvalue, so uref's type is int&&
    


    
    const char name[] = "J. P. Bridges";    // names type is const char[13]

    auto arr1 = name;                       // arr1's type is const char*
    auto& arr2 = name;                      // arr2's type is const char (&)[13]
    
    auto func1 = someFunc;          // func1's type is void(*)(int,double)
    auto& func2 = someFunc;         // func2's type is void(&)(int,double)
    
    
    
    f({11, 23, 9});                 // T deduced as int, and initList's type is std::initializer_list<int>
    
    return 0;
}