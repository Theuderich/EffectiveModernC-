/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>


void printInt(int& t_lValueReference)
{
    std::cout << "lValue Reference: " << t_lValueReference << std::endl;
}

void printInt(int&& t_rValueReference)
{
    std::cout << "rValue Reference: " << t_rValueReference << std::endl;
}

void testTry01()
{
    std::cout << "Test Try01: lvalue, rvalue, lvalue reference, rvalue reference" << std::endl;
    
    int a = 5;      // a is a simple variable
    int& b = a;     // b is a lvalue reference;
    //int&& c = a;    // ERROR: a as lvalue can not bind to rvalue reference
    int&& c = a+1;    // c is a rvalue reference;
    
    printInt(a);    // call with lvalue
    printInt(b);    // call with lvalue reference
    printInt(c);    // call with rvalue reference

    printInt(a+1);  // (a+1) creates a rvalue
    printInt(2);    // 2 is a rvalue
    
    
}