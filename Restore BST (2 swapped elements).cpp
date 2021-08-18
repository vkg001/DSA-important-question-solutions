#include<iostream>
#include<climits>
using namespace std;


struct BST
{
    int num;
    BST *left,*right;
    BST(int x)
    {
        num=x;
        right=left=NULL;
    }
};


struct nodes
{
    BST *first,*mid,*last;
    nodes()
    {
        first=mid=last=NULL;
    }
};


nodes ret;

nodes restoreBST(BST *temp)
{
    if(temp->left==NULL  &&  temp->right==NULL)
    {
        nodes x;
        return x;
    }
    if(temp->left!=NULL)
    if(temp->num<temp->left->num)
    {
        if(ret.first==NULL)
        {
            ret.first=temp->left;
            ret.mid=temp;
        }
        else
        {
            ret.last=temp;
        }
    }
    if(temp->right!=NULL)
    if(temp->num>temp->right->num)
    {
        if(ret.first==NULL)
        {
            ret.first=temp;
            ret.mid=temp->right;
        }
        else
        {
            ret.last=temp->right;
        }
    }
    if(ret.last!=NULL)
        return ret;
    restoreBST(temp->left);
    if(ret.last==NULL)
        restoreBST(temp->right);
    return ret;
}



void Display(BST *temp)
{
    if(temp==NULL)
        return;
    Display(temp->left);
    cout<<temp->num<<"  ";
    Display(temp->right);
}


int main()
{
    int t;
    BST *root;
    root=new BST(7);
    root->left=new BST(3);
    root->left->left=new BST(2);
    root->left->right=new BST(4);
    root->right=new BST(5);
    Display(root);
    cout<<endl;
    nodes ret=restoreBST(root);
    if(ret.last!=NULL)
    {
        t=ret.last->num;
        ret.last->num=ret.first->num;
        ret.first->num=t;
    }
    else
    {
        t=ret.mid->num;
        ret.mid->num=ret.first->num;
        ret.first->num=t;
    }
    Display(root);
    cout<<endl;
    return 0;
}

