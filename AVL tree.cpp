#include<iostream>
using namespace std;

struct tree
{
    int data;
    tree *left, *right;
    tree(int x)
    {
        data=x;
        left=right=NULL;
    }
};


int height(tree *root)
{
    if(root==NULL)
        return 0;
    return (max(height(root->left),height(root->right))+1);
}


void rotator(tree *big, tree *small, tree *unbalanced)
{
    if(big->left!=NULL  &&  big->right!=NULL)
    {
        if(height(big->left)>height(big->right))
        {
            tree *temp=big;
            root->left
        }
        else
        {
            rotator(big->right,big->left);
        }
    }
}


void rotation(tree *root)
{
    if(root==NULL)
        return;
    if(diff(height(root->left),height(root->right))>1)
    {
        if(height(root->left)>height(root->right))
        {
            rotator(root->left,root->right,root);
        }
        else
        {
            rotator(root->right,root->left,root);
        }
    }
    rotation(root->left);
    rotation(root->right);
}


int main()
