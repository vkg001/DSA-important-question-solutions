#include<iostream>
#include<limits.h>
using namespace std;

//  LCA means Lower Common Ancestor

class BinaryTree
{

public:
    int num;
    BinaryTree *left,*right,*root;
    BinaryTree()
    {
        root=NULL;
    }

    BinaryTree(int n)
    {
        num=n;
        left=NULL;
        right=NULL;
    }

    BinaryTree *retRoot()
    {
        return root;
    }
    void Insert(int x)
    {
        BinaryTree *nn = new BinaryTree(x);
        if(root==NULL)
        {
            root=nn;
        }
        else
        {
            BinaryTree *temp=root,*prev;
            while(temp!=NULL)
            {
                prev=temp;
                if(temp->num<x)
                    temp=temp->right;
                else
                    temp=temp->left;
            }
            if(prev->num<x)
                prev->right=nn;
            else
                prev->left=nn;
        }
    }

    BinaryTree* LCA(BinaryTree *temp, int, int);
    int Distance(BinaryTree*, int, int);
    int Height(BinaryTree*, int, int, int);
};


BinaryTree* BinaryTree::LCA(BinaryTree *temp, int x, int y)
{
    if(temp==NULL)
        return NULL;
    if(temp->num==x  ||  temp->num==y)
    {
        cout<<"Pair found"<<endl;
        return temp;
    }

    BinaryTree *r,*l;
    l=LCA(temp->left,x,y);
    r=LCA(temp->right,x,y);
    if(l!=NULL  &&  r!=NULL)
    {
        cout<<temp->num<<endl;
        return temp;
    }

    if(l==NULL  &&  r==NULL)
    {
        cout<<"NULL"<<endl;
        return NULL;
    }

    if(l==NULL  &&  r!=NULL)
    {
        cout<<r->num<<endl;
        return r;
    }

    if(l!=NULL  &&  r==NULL)
    {
        cout<<l->num<<endl;
        return l;
    }

}

int BinaryTree::Distance(BinaryTree* temp, int x, int y)
{
    temp=LCA(temp,x,y);
    int L,R;
    BinaryTree Call;
    L=Call.Height(temp->left,x,y,1);
    R=Call.Height(temp->right,x,y,1);
    return L+R;
}


int BinaryTree::Height(BinaryTree* temp, int x, int y, int h)
{
    if(temp==NULL)
        return 0;
    if(temp->num==x  ||  temp->num==y)
        return h;
    h++;
    return(max(Height(temp->left,x,y,h),Height(temp->right,x,y,h)));
}

int main()
{
    int n,i,x,y,z;
    BinaryTree *r,Call;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements in preorder format\n";
    for(i=0; i<n; i++)
    {
        cin>>x;
        Call.Insert(x);
    }
    r=Call.retRoot();
    cout<<"Enter num1 & num2 : ";
    cin>>y>>z;
    r=Call.LCA(r,y,z);
    cout<<"LCA | "<<r->num;
    cout<<"\nDistance | "<<Call.Distance(r,y,z);
    return 0;
}
