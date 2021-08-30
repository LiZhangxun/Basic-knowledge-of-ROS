#include <iostream>
using namespace std;

// using namespace std:
// 为了解决C++标准库中的标识符与程序中的全局标识符之间以及不同库中的标识符之间的同名冲突，应该将不同库的标识符在不同的命名空间中定义(或声明)。
// 标准C++库的所有的标识符都是在一个名为std的命名空间中定义的，或者说标准头文件(如iostream)中函数、类、对象和类模板是在命名空间 std中定义的。
// std是standard(标准)的缩写，表示这是存放标准库的有关内容的命名空间，含义请楚，不必死记。 
// 这样，在程序中用到C++标准库时，需要使用std作为限定。
    
// first name space
namespace first_space{
    void func(){
    cout << "Inside first_space" << endl;
    }
}
    
// second name space
namespace second_space{
//此处func与第一处命名空间内函数名相同
    void func(){
        cout << "Inside second_space" << endl;
    }
}
    
// 使用第一个namespace
using namespace first_space;
int main () 
{
     
// This calls function from first name space.
    func();   
    return 0;
}