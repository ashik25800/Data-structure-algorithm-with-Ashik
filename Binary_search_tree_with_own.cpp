#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *parent;
    node *left;
    node *right;

    ndoe()
    {
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    node *root = NULL;

    void show_preorder(node *root)
    {
        cout<<root->data<<endl;

        if(root->left!=NULL)
            show_preorder(root->left);
        if(root->right!=NULL)
            show_preorder(root->right);

    }
    void show_inorder(node *root)
    {
        if(root->left)
            show_inorder(root->left);

        cout<<root->data<<endl;

        if(root->right)
            show_inorder(root->right);
    }

    void add(int data)
    {
        node         *new_node = new node;
        new_node ->  data      = data;
        new_node ->  left      = NULL;
        new_node ->  right     = NULL;
        new_node ->  parent    = NULL;

        if(root == NULL)
        {      
            root = new_node;
            return;
        }

        node *temp = root;
        node *got_it;
        
        while(1)
        {


            if(data >= temp->data)
            {
                if(temp->right == NULL)
                {
                    new_node->parent = temp;
                    temp->right = new_node;
                    break;
                }
                temp = temp->right;
            }
            
            else 
            {
                if(temp->left ==NULL)
                {
                    new_node->parent = temp;
                    temp->left = new_node;
                    break;
                }
                temp = temp->left;
            }
        }

    }

    void view(string a="none")
    {
        if(root!=NULL && a=="none")
            show_preorder(root);

        else if(root!=NULL && a=="sorted")
            show_inorder(root);

        else cout<<"Empty"<<endl;
    }

    void search(int data)
    {
        node *temp = root;
        while(1)
        {
            if(temp == NULL)
            {
                cout<<"Not found"<<endl;
                break;
            }

            if(temp->data == data)
            {
                cout<<"Found"<<endl;
                break;
            }

            if(data > temp->data)
            {
                temp = temp->right;
            }

            else if(data < temp->data)
            {
                temp = temp->left;
            }

            else cout<<"Not found"<<endl;


        }
    }

    node *small_data(node *root)
    {
        if(root->left == NULL)
            return root;
        small_data(root->left);
    }

    void find_the_node(int data,node *root)
    {
        if(root == NULL)
        {
            cout<<"Not found what you are searching !"<<endl;
            return;
        }

        if(root->data == data && root->left == NULL && root->right == NULL)
        {
            node *temp = root->parent;
            if(temp->right->data == data)
            {
                temp->right = NULL;
            }
            else temp->left = NULL;

            delete root;
            return;
        }

        else if((root->data == data) && ((root->left != NULL && root->right == NULL) || (root->right!=NULL && root->left ==NULL)))
        {
            node *temp;
            node *temp_parent;
            if(root->left !=NULL)
                temp = root->left;
            else temp = root->right;
            temp_parent = temp->parent->parent;
            delete root;
            temp->parent = temp_parent;
            return;
        } 

        else if(root->data == data)  
        {
            node *successor = small_data(root->right);
            root->data = successor->data;
            node *temp = successor->right;
            node *temp_parent = successor->parent;
            delete successor->parent->left;

            temp_parent->left = temp;
            return;
        }

        if(data > root->data)
            find_the_node(data,root->right);
        if(data < root->data)
            find_the_node(data,root->left);
    }

    void remove(int data)
    {
        find_the_node(data,root);
    }


};



int main()
{
    BST a;
    int arr[] = {55,21,88,8,-4,30,56,9,3,93,90,91,94};


    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        a.add(arr[i]);

    a.remove(88);
    
    a.view("sorted");



    return 0;
}
