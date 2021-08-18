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


BST *BuildBST(int *arr, int n, int lb, int ub)
{
    if(lb<0  ||  ub>=n  ||  lb>ub)
        return NULL;
    int mid=(lb+ub)/2;
    BST *temp=new BST(arr[mid]);
    temp->left=BuildBST(arr,n,lb,mid-1);
    temp->right=BuildBST(arr,n,mid+1,ub);
    return temp;
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
    root=BuildBST(x,n,0,n-1);
    Display(root);
    return 0;
}
