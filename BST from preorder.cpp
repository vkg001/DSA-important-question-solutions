#include<iostream>
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
}*root=NULL;


void BuildBST(int *arr, int n)
{
    int i;
    BST *prev,*temp,*newnode=new BST(arr[0]);
    root=newnode;
    for(i=1;i<n;i++)
        {
            newnode=new BST(arr[i]);
            temp=root;
            while(temp!=NULL)
            {
                prev=temp;
                if(arr[i]<temp->num)
                    temp=temp->left;
                else
                    temp=temp->right;
            }
            if(prev->num<arr[i])
                prev->right=newnode;
            else
                prev->left=newnode;
        }
}


void Display(BST *temp)
{
    if(temp==NULL)
        return;
    cout<<temp->num<<"  ";
    Display(temp->left);
    Display(temp->right);
}


int main()
{
    int n,i;
    cout<<"Enter of elements:" ;
    cin>>n;
    int x[n];
    cout<<"Enter elements\n";
    for(i=0; i<n; i++)
    {
        cin>>x[i];
    }
    BuildBST(x,n);
    Display(root);
    return 0;
}
