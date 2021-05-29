#include<stdio.h>
#include <iostream>
using namespace std;

int add(int a,int b)
{
    return a+b;
}

int sub(int a,int b)
{
    return a-b;
}

int oparate(int (*op)(int ,int),int a,int b)
{
    return op(a,b);
}

int main()
{
    cout<<oparate(&add,5,6)<<endl;

    return 0;
}
