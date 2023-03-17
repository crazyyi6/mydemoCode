#include <bits/stdc++.h>
using namespace std;

/// 注意要增加一个空实现的printA的函数，这里是使用模板来做递归的时候必须要的东西
void printA()
{

}
// 这里是做递归的方式
template<typename T , typename... Types>
void printA(const T& firstArg ,const Types&... args)
{
    cout<<firstArg<<endl;
    printA(args...);
}
int main()
{
   // vector_test();
    //priority_queue_test();
    printA("ssss","3333","88888","11111");
    system("pause");
    return 0;
}
