#include<bits/stdc++.h>
using namespace std;
#define MAX 5

typedef struct node Node;

struct node
{
    int data;
    Node *left;
    Node *right;
};

Node *create_node(int data)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node ->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left(Node **node,int data)
{
    Node *new_node = create_node(data);

    (*node)->left = new_node;
}


void add_right(Node **node,int data)
{
    Node *new_node = create_node(data);

    (*node)->right = new_node;
}

void pre(Node *node)
{

    cout<<node->data<<" ";

    if(node->left!=NULL)
        pre(node->left);
    if(node->right!=NULL)
        pre(node->right);
}

void post(Node *node)
{

    if(node->left!=NULL)
        post(node->left);
    if(node->right!=NULL)
        post(node->right);

    cout<<node->data<<" ";
}


void in(Node *node)
{

    if(node->left!=NULL)
        in(node->left);
    cout<<node->data<<" ";
    if(node->right!=NULL)
        in(node->right);
}

int main()
{
    Node *root;

    root=create_node(1);

    add_left(&root,2);
    add_right(&root,3);
    add_left(&(root->left),4);
    add_right(&(root->left),5);
    add_left(&(root->left->right),10);

    add_left(&(root->right),6);
    add_right(&(root->right),7);
    add_right(&(root->right->right),12);


    pre(root);
    cout<<endl;
    post(root);
    cout<<endl;
    in(root);

    return 0;
}
