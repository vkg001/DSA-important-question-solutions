#include<iostream>
#include<vector>
#include<algorithm>
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


struct Q
{
    int num;
    BST *current;
    Q *f,*r,*next;
    Q(BST *curr,int x)
    {
        num=x;
        current=curr;
        next=NULL;
    }
}*f=NULL,*r=NULL;


void BuildQ(BST *curr, int x)
{
    Q *newnode=new Q(curr,x);
    if(curr==NULL)
    {
        return;
    }
    if(f==NULL)
    {
        f=r=newnode;
        return;
    }
    r->next=newnode;
    r=newnode;
}

void BuildBST(int n)
{
    int i;
    BST *prev,*temp,*newnode=new BST(n);
    if(root==NULL)
    {
        root=newnode;
        return;
    }
    temp=root;
    while(temp!=NULL)
    {
        prev=temp;
        if(n<temp->num)
            temp=temp->left;
        else
            temp=temp->right;
    }
    if(prev->num<n)
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

bool sortDec(pair<BST*,int> &a, pair<BST*,int> &b)
{
    return a.second>b.second;
}

int fl=1;
void DisplayZigZag(Q *temp)
{
    if(temp==NULL)
    {
        return;
    }


    if(fl==1)
    {
        Q *t=f;
        fl=0;


        f=r=NULL;
        while(t!=NULL)
        {
            cout<<t->num<<"  ";
            if(t->current->left!=NULL)
            BuildQ(t->current->left,t->current->left->num);
            if(temp->current->right!=NULL)
            BuildQ(t->current->right,t->current->right->num);
            t=t->next;
        }


    }
    else
    {
        Q *t=f;
        vector<pair<BST*,int>> Ele;
        int vrr[50],ki=0;
        f=r=NULL;
        while(t!=NULL)
        {

                pair<BST*,int> yu;
                yu.first=t->current;
                yu.second=t->current->num;
                Ele.push_back(yu);
                cout<<t->current->num<<"-";

                if(t->current->left!=NULL)
                {

                BuildQ(t->current->left,t->current->left->num);
                }


                if(t->current->right!=NULL)
                {
                    BuildQ(t->current->right,t->current->right->num);
                }
            t=t->next;
        }
        /*
        t=f;
        f=r=NULL;
        while(t!=NULL)
        {
            if(t->current->left)
            BuildQ(t->current->left,t->current->left->num);
            if(t->current->right)
            BuildQ(t->current->right,t->current->right->num);
            t=t->next;
        }
        */
        for(int ti=0;ti<ki;ti++)
            cout<<vrr[ti]<<"  ";
        cout<<"  |  ";
        sort(Ele.begin(),Ele.end(),sortDec);
        for(auto var:Ele)
        {
            pair<BST*,int> yu;
            yu=var;
            cout<<yu.second<<"  ";
        }
        fl=1;

    }
    cout<<endl;
    DisplayZigZag(f);
}


int main()
{
    int n,i;
    cout<<"Enter of elements:" ;
    cin>>n;
    int x;
    cout<<"Enter elements\n";
    for(i=0; i<n; i++)
    {
        cin>>x;
    BuildBST(x);

    }
    Display(root);
    cout<<endl;
    BuildQ(root,root->num);
    DisplayZigZag(f);
    return 0;
}
