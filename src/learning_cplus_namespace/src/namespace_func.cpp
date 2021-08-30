#include <iostream>
// namespace通常用来给类或者函数做个区间定义，以使编译器能准确定位到适合的类或者函数。
// 譬如说，自行实现了一个函数test(void)，而在该项目的库函数内也定义了一个函数test(void);
// 当你调用test();函数的时候，编译器就困惑了，该调用哪个呢？这个时候namespace的作用就显现出来了。

using namespace std;
    
// first name space
namespace first_space{
    void func(){
        cout << "Inside first_space" << endl;
    }
}

// second name space
namespace second_space{
    void func(){
        cout << "Inside second_space" << endl;
    }
}
    
int main () 
{

// Calls function from first name space.
first_space::func();
       
// Calls function from second name space.
second_space::func(); 
    
return 0;
} 