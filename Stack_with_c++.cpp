#include<bits/stdc++.h>
using namespace std;
#define MAX 5




class stackk
{
public:
    int top=-1;
    int arr[MAX];

    void push(int data)
    {
        if(top == 4)
        {
            cout<<"Full"<<endl;
            return;
        }
        top++;
        arr[top] = data;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Empty"<<endl;
            return;
        }
        top--;
    }

    void show()
    {
        for(int i=0;i<top+1;i++)
            cout<<arr[i]<<endl;
        cout<<"---"<<endl;
    }
};



int main()
{
    stackk a;
    a.push(12);
    a.show();



    return 0;
}
