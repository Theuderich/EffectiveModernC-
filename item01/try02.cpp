/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

// Case 1: Pointer
template<typename T>
void fooCase1_Ptr(T* t_param)       // parameter is a pointer
{
    std::cout << "fooCase1_Ptr: " << *t_param << std::endl;
}    

// Case1: Reference
template<typename T>
void fooCase1_Ref(T& t_param)       // parameter is a reference
{
    std::cout << "fooCase1_Ref: " << t_param << std::endl;
}

// Case1: Reference
template<typename T>
void fooCase1_ConstRef(const T& t_param)       // parameter is now a ref-to-const
{
    std::cout << "fooCase1_ConstRef: " << t_param << std::endl;
}

// Case2: Universal Reference
template<typename T>
void fooCase1_UniversalRef(T&& t_param)         // parameter is now a universal reference
{
    std::cout << "fooCase1_UniversalRef: " << t_param << std::endl;
}

// Case3: pass-by-value
template<typename T>
void fooCase1_PassByValue(T t_param)            // parameter is now passed by value
{
    std::cout << "fooCase1_PassByValue: " << t_param << std::endl;
}

// Array Arguments
template<typename T>
void fooArrayArg_PassByValue(T t_param)         // template with by-value parameter
{
    std::cout << "fooArrayArg_PassByValue: " << t_param << " Size: " << sizeof(T) << std::endl;
}

// Array Arguments
template<typename T>
void fooArrayArg_PassByRef(T& t_param)         // template with by-reference parameter
{
    std::cout << "fooArrayArg_PassByRef: " << t_param << " Size: " << sizeof(T) << std::endl;
}

// Array Arguments

// return size of an array as a compile.time constant.
// constexpr make its result available during compilation.
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}


void someFunc( int t_int, double t_double)
{
    std::cout << "int: " << t_int << " double: " << t_double << std::endl;
}

template<typename T>
void f1(T param)        // in f1, param passed by value
{
    param(5, 2.3);
}

template<typename T>
void f2(T& param)        // in f2, param passed by reference
{
    param(10, 12.3);
}


void testTry02()
{
    std::cout << "Test Try02: Type deduction on templates" << std::endl;
    
    int x = 27;             // x is a int
    const int cx = x;       // cx is a const int
    const int& rx = x;      // rx is a reference to x as a const int
    const int* px = &x;     // px is a pointer to x as a const int
    
    // testing pointer type deduction
    fooCase1_Ptr(&x);       // T is int, param's type is int*
    fooCase1_Ptr(px);       // T is const int, param's type is const int*
    
    // testing lvalue reference type deduction
    fooCase1_Ref(x);        // T is int, param's type is int&
    fooCase1_Ref(cx);       // T is const int, param's type is const int&
    fooCase1_Ref(rx);       // T is const int, param's type is const int&
    
    // testing const lvalue reference type deduction
    fooCase1_ConstRef(x);        // T is int, param's type is const int&
    fooCase1_ConstRef(cx);       // T is int, param's type is const int&
    fooCase1_ConstRef(rx);       // T is int, param's type is const int&
    
    // testing universal reference
    fooCase1_UniversalRef(x);   // x is lvalue, so T is int&, param's type is int&
    fooCase1_UniversalRef(cx);  // x is lvalue, so T is const int&, param's type is const int&
    fooCase1_UniversalRef(rx);  // x is lvalue, so T is const int&, param's type is const int&
    fooCase1_UniversalRef(27);  // x is rvalue, so T is int, param's type is int&&
    
    // testing pass-by-value
    fooCase1_PassByValue(x);    // T is int, param's type is also int
    fooCase1_PassByValue(cx);   // T is int, param's type is also int
    fooCase1_PassByValue(rx);   // T is int, param's type is also int
    
    
    
    const char name[] = "J. P. Bridges";    // names type is const char[13]
    const char* ptrToName = name;           // array decays to pointer;
    
    
    // both function declarations are the same:
    // void myFunc(int param[]);
    // void myFunc(int* param);
    //
    // but "const char[13]" and "const char*" are different
    
    fooArrayArg_PassByValue(name);          // name is array, but T deducts as const char*
    fooArrayArg_PassByRef(name);            // T is const char [13], param's type is const char (&)[13]
    
    std::cout << arraySize(name) << std::endl;
    
    int keyVals[] = {1, 3, 7, 9, 11, 22, 35 };      // keyVals with 7 elements
    int mappedVals[arraySize(keyVals)];             // so does mappdVals
    
    
    
    f1(someFunc);       // param deducts as pointer-to-function: type is void(*)(int,double)
    f2(someFunc);       // param deducts as reference-to-function: type is void(&)(int,double)
    
}