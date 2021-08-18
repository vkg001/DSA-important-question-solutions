#include<iostream>
using namespace std;

class BinaryTree
{
    int num;
    BinaryTree *left,*right,*root;
public:

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

    bool CheckBalance(BinaryTree* temp)
    {
        int l,r;
        if(temp==NULL)   return true;
        l=Height(temp->left);
        r=Height(temp->right);
        if(l-r<=1  &&  l-r>=-1)
            return (CheckBalance(temp->left) &&  CheckBalance(temp->right));
        return false;
    }


    int Height(BinaryTree *temp)
    {
        if(temp==NULL)
            return 0;
        return(max(Height(temp->left),Height(temp->right)+1));
    }
};



int main()
{
    int n,i,x;
    BinaryTree *r,Call;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements in preorder format\n";
    for(i=0;i<n;i++)
    {
        cin>>x;
        Call.Insert(x);
    }
    r=Call.retRoot();
    if(Call.CheckBalance(r))  cout<<"Balanced";
    else cout<<"Not balanced";
    return 0;
}
