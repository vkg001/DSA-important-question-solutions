#include<iostream>
using namespace std;

class Tree
{
    int num;
    Tree *left,*right,*root;
public:
    Tree()
    {
        root=NULL;
    }

    Tree(int x)
    {
        num=x;
        left=right=NULL;
    }


    Tree *retRoot()
    {
        return root;
    }
    void Insert(int x)
    {
        Tree *nn = new Tree(x);
        if(root==NULL)
        {
            root=nn;
        }
        else
        {
            Tree *temp=root,*prev;
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


    int Traverse(Tree*);
    void DisplayPreOrder(Tree *root);
    void SumReplacement(Tree *temp);
};


void Tree::DisplayPreOrder(Tree *temp)
{
    if(temp==NULL)
    {
        return;
    }

    cout<<temp->num<<"  ";
    DisplayPreOrder(temp->left);
    DisplayPreOrder(temp->right);

}



void Tree::SumReplacement(Tree *temp)
{
    if(temp==NULL)
        return;
    SumReplacement(temp->left);
    SumReplacement(temp->right);
    temp->num=Traverse(temp)+temp->num;
}


int Tree::Traverse(Tree* temp)
{
    int x,y;
    if(temp->left==NULL)
        x=0;
    else
        x=temp->left->num;
    if(temp->right==NULL)
        y=0;
    else
        y=temp->right->num;
    return(x+y);
}



int main()
{
    int n,i,x;
    Tree *r,Call;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements in preorder format\n";
    for(i=0;i<n;i++)
    {
        cin>>x;
        Call.Insert(x);
    }
    r=Call.retRoot();
    Call.SumReplacement(r);
    Call.DisplayPreOrder(r);
    return 0;
}
