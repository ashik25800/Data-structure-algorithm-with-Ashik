#include<bits/stdc++.h>
using namespace std;


class node
{
public:
    int data;
    node *next;

    node()
    {
        next = NULL;
    }
};


class linkedlist
{
public:
    node *head = NULL;

    void append(int value)
    {
        node *new_node = new node;
        new_node->data = value;

        if(head == NULL)
            head = new_node;

        else 
        {
            node *temp = head;
            while(temp->next)
            {
                temp=temp->next;
            }temp->next = new_node;
        }
    }

    void view()
    {
        while(head)
        {
            cout<<head->data<<endl;
            head=head->next;
        }
    }


};



int main()
{
    linkedlist a;
    a.append(5);
    a.append(10);
    a.view();


    return 0;
}
