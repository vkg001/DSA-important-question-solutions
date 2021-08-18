#include<iostream>
using namespace std;


struct BST
{
    int num;
    BST *left,*right;
    BST(int x)
    {
        num=x;
        left=right=NULL;
    }
}*root=NULL;


void Insert(int x)
{
    BST *newnode=new BST(x);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    BST *temp=root,*prev;
    while(temp!=NULL)
    {
        prev=temp;
        if(temp->num<x)
            temp=temp->right;
        else
            temp=temp->left;
    }
    if(prev->num<x)
        prev->right=newnode;
    else
        prev->left=newnode;
}


void Display(BST *temp)
{
    if(temp==NULL)
        return;
    cout<<temp->num<<"  ";
    Display(temp->left);
    Display(temp->right);
}


BST *Searchele(BST *temp, int x)
{
    if(temp==NULL)
        return NULL;
    if(temp->num==x)
        return temp;
    BST *l,*r;
    l=Searchele(temp->left,x);
    r=Searchele(temp->right,x);
    if(l!=NULL)
        return l;
    return r;
}


BST *InorderSuc(BST *temp)
{
    if(temp==NULL)
        return NULL;
    BST *t,*u;
    t=InorderSuc(temp->left);
    u=InorderSuc(temp->right);
    if(t==NULL  &&  u==NULL)
    {
        return  temp;
    }
    if(t!=NULL)
    {
        temp->left=NULL;
        return t;
    }
    temp->right=NULL;
    return u;
}

void Pred(BST *pos, BST *temp)
{
    if(temp==NULL)
        return;
    if(temp->left==pos)
    {
        temp->left=NULL;
        return;
    }
    if(temp->right==pos)
    {
        temp->right=NULL;
        return;
    }
    Pred(pos,temp->left);
    Pred(pos,temp->right);
}


void predpos(BST *pos, BST *temp, BST *ins)
{
    if(temp==NULL)
        return;
    if(temp->left==pos)
    {
        temp->left=ins;
        return;
    }
    if(temp->right==pos)
    {
        temp->right=ins;
        return;
    }
    predpos(pos,temp->left,ins);
    predpos(pos,temp->right,ins);
}


void Delete(BST *temp, int x)
{
    BST *pos;
    pos=Searchele(temp,x);
    if(pos->left==NULL  &&  pos->right==NULL)
    {
        Pred(pos,root);
        delete(pos);
        return;
    }
    else if(pos->left==NULL  &&  pos->right!=NULL)
    {
        BST *pre=pos;
        predpos(pos,root,pos->right);
        pos=pos->right;
        delete(pre);
        return;
    }
    else if(pos->left!=NULL  &&  pos->right==NULL)
    {
        BST *pre=pos;
        predpos(pos,root,pos->left);
        pos=pos->left;
        delete(pre);
        return;
    }
    BST *pre=pos,*p;
    pos=InorderSuc(pos->right);
    predpos(pre,root,pos);
    p=pos;
    while(p->left!=NULL)
        p=p->left;
    p->left=pre->left;
    if(pre->right!=p)   p->right=pre->right;
    if(pre==root)   root=pos;
    delete(pre);
}

int main()
{
    int n,i,x;
    cout<<"Enter of elements:" ;
    cin>>n;
    cout<<"Enter elements\n";
    for(i=0; i<n; i++)
    {
        cin>>x;
        Insert(x);
    }
    Display(root);
    cout<<"\nEnter any element to delete: ";
    cin>>x;
    Delete(root,x);
    Display(root);
    return 0;
}
