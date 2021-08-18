#include<iostream>
#include<climits>
using namespace std;

struct tree
{
    int num;
    tree *left,*right;
    tree(int x)
    {
        num=x;
        left=right=NULL;
    }
};


struct Info
{
    int ans;
    int Max;
    int Min;
    int Size;
    bool isBST;
};


Info BSTinBinaryTree(tree* temp)
{
    if(temp==NULL)
    {
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(temp->left==NULL  &&  temp->right==NULL)
    {
        return {1,temp->num,temp->num,1,true};
    }
    Info L=BSTinBinaryTree(temp->left);
    Info R=BSTinBinaryTree(temp->right);
    Info curr;
    curr.Size=L.Size+R.Size+1;
    if(L.isBST==true  &&  R.isBST==true  &&  L.Max<temp->num  &&  R.Min>temp->num)
    {
        curr.Max=max(R.Max,max(L.Max,temp->num));
        curr.Min=min(R.Min,min(L.Min,temp->num));
        curr.isBST=true;
        curr.ans=(L.ans+R.ans)+1;
        return curr;
    }
    curr.ans=max(L.Size,R.Size);
    curr.isBST=false;
    return curr;
}


int main()
{
    tree *root1;
    root1=new tree(5);
    root1->left=new tree(3);
    root1->left->left=new tree(2);
    root1->left->right=new tree(4);
    root1->right=new tree(7);
    root1->right->left=new tree(6);
    root1->right->right=new tree(8);

    Info x;
    x=BSTinBinaryTree(root1);
    cout<<"Size | "<<x.ans<<endl;
    return 0;
}
