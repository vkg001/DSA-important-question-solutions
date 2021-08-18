#include<iostream>
using namespace std;

struct Tree
{
    int num;
    Tree *left, *right;
    Tree(int x)
    {
        num=x;
        left=right=NULL;
    }
}*root=NULL;

Tree *node(Tree *temp, int x)
{
    Tree *u;
    if(temp==NULL)
        return NULL;
    if(temp->num==x)
        return temp;
    u=node(temp->left, x);
    if(u)
        return u;
    return node(temp->right, x);
}


void CheckSub(Tree *temp, int k)
{
    if(temp==NULL  ||  k<0)
        return;
    if(k==0)
    {
        cout<<temp->num<<"  ";
        return;
    }
    CheckSub(temp->left,k-1);
    CheckSub(temp->right,k-1);
}

void Ancestors(Tree *temp, int k, int target)
{
    if(temp==NULL  || k<0)
        return;
    if(temp->right->num==target)
    {
        CheckSub(temp->left,k-2);
        Ancestors(root,k-1,temp->num);
        return;
    }
    else if(temp->left->num==target)
    {
        CheckSub(temp->right,k-2);
        Ancestors(root,k-1,temp->num);
        return;
    }
    Ancestors(temp->left,k-1,target);
    Ancestors(temp->right,k-1,target);
    return;
}

void Display(Tree *temp)
{
    if(temp==NULL)
        return;
    cout<<temp->num<<"  ";
    Display(temp->left);
    Display(temp->right);
}

int main()
{
    root=new Tree(1);
    root->left=new Tree(2);
    root->left->left=new Tree(3);
    root->left->left->left=new Tree(8);
    root->left->left->right=new Tree(9);

    root->left->right=new Tree(4);
    root->right=new Tree(5);
    root->right->left=new Tree(6);
    root->right->right=new Tree(7);
    Tree *x;
    int target,k;
    target=5;
    k=1;
    Display(root);
    cout<<endl;
    x=node(root,target);
    CheckSub(x,k);
    Ancestors(root,k,target);
    return 0;
}
