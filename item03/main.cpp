#include <iostream>

void print(int& t_int)
{
    printf("print as lvalue reference %d\n", t_int);
}

void print(int&& t_int)
{
    printf("print as rvalue reference %d\n", t_int);
}


//https://stackoverflow.com/questions/3582001/advantages-of-using-forward
template <typename A>
void f(A&& param)
{
    print( std::forward<A>(param) ); 
}

template <typename A>
void g(A&& param)
{
    print( param );         
}


// From the book Item03

void authenicateUser()
{
    
}

template<typename Container, typename Index>
auto
authAndAccess(Container&& c, Index i)
  -> decltype(std::forward<Container>(c)[i])
{
    authenicateUser();
    return std::forward<Container>(c)[i];
}

// my test

class Elem
{
public:
    Elem() : m_var(0) {}
    
    int m_var;
};



int main () 
{
    std::cout << "Main Application: Item 03" << std::endl;
    
    int i = 27;
    
    f(i);       // A is int, param is int&  , call print as lvalue
    f(27);      // A is int, param is int&& , caöö print as rvalue
    
    i=28;
    g(i);       // A is int, param is int&  , call print as lvalue
    g(28);      // A is int, param is int&& , call print as lvalue
    
    
    
    int intArray[] = {1, 2, 3, 4, 5};          // array is int[5]
    printf("Array[3] element %d\n", authAndAccess(intArray, 3));

    Elem objArray[5];   // m_var in all elements are 0
    objArray[3].m_var = 4;
    printf("objArray[3].m_var element %d\n", authAndAccess(objArray, 3).m_var);
    
    
    
    return 0;
}