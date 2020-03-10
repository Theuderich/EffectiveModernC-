#include <iostream>
#include <vector>

template<typename T>
class TD;

template<typename T>
void foo( const T& param )
{
    
    std::cout << "T =     " << typeid(T).name() << std::endl;
    std::cout << "param = " << typeid(param).name() << std::endl;       // removes constness & reference-ness because std::type_info::name is a template
    
    TD<decltype(param)> paramType;                                      // implicit instantiation of undefined template 'TD<const Widget *const &>'
    
}

class Widget
{
public:
    Widget() : m_var(0) {}
    
    int m_var;
};

std::vector<Widget> createVec()
{
    std::vector<Widget> vector;
    vector.push_back(Widget());
    
    return vector;
}

// https://www.boost.org/users/history/version_1_72_0.html


int main () 
{
    std::cout << "Main Application: Item 04" << std::endl;
    
    auto x = 27;
    const auto* y = &x;
    const auto& z = x;
    
//    TD<decltype(x)> xType;
//    TD<decltype(y)> yType;
//    TD<decltype(z)> zType;
    
    std::cout << "xType is: " << typeid(x).name() << '\n';
    std::cout << "yType is: " << typeid(y).name() << '\n';
    std::cout << "zType is: " << typeid(z).name() << '\n';

    const auto vw = createVec();
    
    if( !vw.empty() )
    {
        foo(&vw[0]);                // this is const Widget * const &
    }
    
    return 0;
}