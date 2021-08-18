#include<iostream>
using namespace std;
struct Tree
{
    int num;
    Tree *left,*right;
};
Tree* Insert(int x)
{
    Tree *newnode=new Tree ;
    newnode->num=x;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void Flatten(Tree *temp)
{
    if(temp==NULL || (temp->right==NULL  &&  temp->left==NULL))
        return;
    Tree *a,*b;
    a=temp->left;
    Flatten(temp->left);
    b=temp->right;
    Flatten(temp->right);
    temp->right=a;
    while(a->right!=NULL)
    {
        a=a->right;
    }
    a->right=b;
}

int main()
{
    Tree *root;
    root=Insert(1);
    root->left=Insert(2);
    root->left->left=Insert(3);
    root->left->right=Insert(4);
    root->right=Insert(5);
    root->right->left=Insert(6);
    root->right->right=Insert(7);
    Flatten(root);
    while(root)
    {
        cout<<root->num<<"   ";
        root=root->right;
    }
    return 0;
}
