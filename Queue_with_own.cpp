#include<iostream>
#include<stack>
#include<stdio.h>
#include<string.h>
#define MAX 5
using namespace std;

int full = 0;

struct que
{
    int head = 0;
    int tail = 0;
    char arr[MAX];
};

void enque(que *q,char ch)
{
    if(full==MAX)
    {
        cout<<"queue is full"<<endl;
        return;
    }

    q->arr[(q->tail)%MAX] = ch;
    full++;
    q->tail++;
}

void dequeue(que *q)
{

    if(full==0)
    {
        cout<<"empty"<<endl;
        return;
    }
    full--;
    q->head++;

}
void show(que *a)
{
    stack<char> ch,ch1;
    if(full==0)
    {
        cout<<"Nothing to show"<<endl;
        return;
    }

    while(full!=0)
    {
        cout<<a->arr[(a->head)%MAX]<<" ";
        ch.push(a->arr[(a->head)%MAX]);
        dequeue(a);
    }cout<<endl;


    while(!ch.empty())
    {
        ch1.push(ch.top());
        ch.pop();
    }
    while(!ch1.empty())
    {
        enque(a,ch1.top());
        ch1.pop();

    }
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
            show(&a);
        }
    }

}
