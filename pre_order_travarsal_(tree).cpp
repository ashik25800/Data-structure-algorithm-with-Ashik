#include<iostream>
#include<stdio.h>
#include<algorithm>
#include <string>
#include<stack>
#include<string.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *left;
    Node *right;
};


Node *create_node(int data)
{
    Node *new_node = (Node*) (malloc(sizeof(Node)));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void append_left(int data,Node **node)
{
    Node *new_node = create_node(data);
    (*node)->left = new_node;
}
void append_right(int data,Node **node)
{
    Node *new_node = create_node(data);
    (*node)->right = new_node;
}

void view(Node *node) //pre-order travarsal
{
    cout<<node->data<<endl;
    if(node->left!=NULL)
        view(node->left);
    if(node->right!=NULL)
        view(node->right);
}

int main()
{
    Node *a;
    a = create_node(6);
    append_left(7,&a);
    append_right(8,&a);
    append_left(9,&(a->left));
    append_left(10,&(a->left)->left);




    view(a);


    return 0;
}
