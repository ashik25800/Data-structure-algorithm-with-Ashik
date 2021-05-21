#include<stdio.h>
#include<stdlib.h>


typedef struct node Node;

struct node
{
    int data;
    Node *pre;
    Node *next;
};

Node  *crate_node(int data,Node *pre,Node *next)
{
    Node *new_node = (Node*) (malloc(sizeof(Node)));

    new_node->data=data;
    new_node->next=next;
    new_node->pre=pre;

    return new_node;

}

void prepend(int data,Node **head)
{
    Node *new_node = crate_node(data,NULL,*head);
    if(new_node->next!=NULL)
    (new_node->next)->pre=new_node;
    *head = new_node;

}
void append(int data,Node **head)
{
    Node *new_node= (Node*)(malloc(sizeof(Node)));
    new_node=crate_node(data,NULL,NULL);
    Node *ref=*head;

    if(*head==NULL)
    {
        *head=new_node;
        return;
    }


    else
    {
        while(ref->next!=NULL)
            ref=ref->next;
        new_node->pre=ref;
        ref->next=new_node;
    }


}


void print(Node *head)
{
    Node *n=head;
    while(n->next!=NULL)
    {
        printf("Data : %d  Pre loc: %p Next loc: %p\n",n->data,n->pre,n->next);
        n=n->next;
    }
    printf("Data : %d  Pre loc: %p Next loc: %p\n",n->data,n->pre,n->next);
}


int main()
{
    Node *head=(Node*)(malloc(sizeof(Node)));
    head = NULL;


    prepend(5,&head);
    prepend(2,&head);
    prepend(1,&head);
    prepend(-2,&head);
    append(44,&head);
    append(66,&head);
    prepend(-33,&head);

    print(head);
    return 0;
}
