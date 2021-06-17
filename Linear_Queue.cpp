#include<iostream>
#include<stack>
#include<stdio.h>
#include<string.h>
#define MAX 10
using namespace std;

struct que
{
    int head = 0;
    int tail = 0;
    char arr[MAX];
};

void enque(que *q,char ch)
{
    if(q->tail==9)
    {
        cout<<"queue is full"<<endl;
        return;
    }

    q->arr[q->tail] = ch;
    q->tail++;
}

void dequeue(que *q)
{
    if(q->head==q->tail)
    {
        cout<<"empty"<<endl;
        return;
    }

    cout<<"--  "<<q->arr[q->head]<<endl;
    q->head++;

}
void show(que a)
{
    if(a.head==a.tail)
    {
        cout<<"Full"<<endl;
        return;
    }

    for(int i=a.head;i<a.tail;i++)
        cout<<a.arr[i]<<endl;
}

int main()
{
    struct que a;
    cout<<"1. Enqueue\n2. Dequeue\n3. View"<<endl;
    int x;
    while(1)
    {
        cin>>x;
        if(x==0)
            break;
        else if(x==1)
        {
            char ch;
            cin>>ch;
            enque(&a,ch);
        }
        else if(x==2)
        {
            dequeue(&a);
        }
        else if(x==3)
        {
            show(a);
        }
    }

}
