#include<cstdio>
#include<queue>
#include<stdlib.h>
#include<stack>
#include<algorithm>
#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

///creating a new node

struct node* newNode(int item)
{
    struct node* temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data= item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
} ;


///helping function for traversing the graph

void inorder(struct node* root)
{
    if (root!= NULL)
    {
        inorder(root->left);
        cout<<root->data;

        inorder(root->right);

    }
}

///input the new node data or insert data

struct node* insert(struct node* node, int data)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
    {
        return newNode(data);
    }
    if(data <node->data)
    {
        node->left=insert(node->left,data);
    }
    else if (data > node->data)
    {
        node->right=insert(node->right,data);
    }
    /* return the (unchanged) node pointer */
    return (node);

};


int main()
{
    struct node* root=NULL;

    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    inorder(root);
}
