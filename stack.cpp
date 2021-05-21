#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

//I made this stack only for integer number and implement this with structure;

#define max 100

typedef struct Stack stak;

struct Stack
{
    int top=-1;
    int data[max];
};

void push(stak *a,int item)
{
    if(a->top>=max)
    {
        cout<<"It's full"<<endl;
        return;
    }

    a->top++;
    a->data[a->top]=item;
}
void pop(stak *a)
{
    if(a->top==-1)
        cout<<"Nothing is to pop"<<endl;
    else    a->top--;
}

void view(stak a)
{
    if(a.top==-1)
        cout<<"Empty"<<endl;
    else
    {
        for(int i=0;i<=a.top;i++)
            cout<<a.data[i]<<" ";
        cout<<endl;
    }
}


int main()
{
    stak a;
    int b,b1,c1;
    cin>>b>>b1>>c1;
    push(&a,b);
    push(&a,b1);
    push(&a,c1);
    pop(&a);

    view(a);


    return 0;
}
