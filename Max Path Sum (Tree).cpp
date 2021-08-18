#include<iostream>
#include<limits.h>
using namespace std;

struct Tree
{
    int num;
    Tree *left,*right;
    Tree(int x)
    {
        num=x;
        left=right=NULL;
    }
};

Tree *root=NULL;

void Insert(int x)
    {
        Tree *nn = new Tree(x);
        if(root==NULL)
        {
            //cout<<"Root"<<endl;
            root=nn;
        }
        else
        {
            Tree *temp=root,*prev;
            while(temp!=NULL)
            {
                //cout<<temp->num<<"   ";
                prev=temp;
                if(temp->num<x)
                    temp=temp->right;
                else
                    temp=temp->left;
            }
            if(prev->num<x)
            {
                //cout<<prev->num<<endl;
                prev->right=nn;
            }

            else
                prev->left=nn;
        }
    }

int Maxsum=INT_MIN,tempsum=0;

int maxPath(Tree *temp)
{
    if(temp==NULL)
        return 0;
    int l,r;
    l=maxPath(temp->left);
    r=maxPath(temp->right);
    cout<<"L | "<<l<<"\tR | "<<r<<"\tTemp | "<<temp->num<<endl;
    tempsum=max(max(l+r+temp->num,max(l,r)),max(temp->num+r,l+temp->num));
    //cout<<"tempsum | "<<tempsum<<"      maxsum | "<<Maxsum<<endl;
    if(Maxsum<tempsum)  Maxsum=tempsum;
    //cout<<"Maxsum | "<<Maxsum<<endl;
    return max(temp->num,max(l+temp->num,r+temp->num));
}


int main()
{
    Tree *r;
    int y,x,z,n,i;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements in preorder format\n";
    for(i=0; i<n; i++)
    {
        cin>>x;
        Insert(x);
    }
    maxPath(root);
    cout<<"Max. path sum is "<<Maxsum<<endl;

    return 0;
}
