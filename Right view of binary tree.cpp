#include<iostream>
using namespace std;

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
    void RightView(BinaryTree *temp);
};




class Queue:public BinaryTree
{
    int num;
    BinaryTree *curr;
    Queue *front, *rear, *next;
public:
    Queue()
    {
        front=rear=NULL;
    }
    Queue(int x, BinaryTree *temp)
    {
        curr=temp;
        num=x;
        next=NULL;
    }
    void Enqueue(int x, BinaryTree *temp)
    {
        Queue *nn=new Queue(x,temp);
        if(front==NULL)
        {
            front=rear=nn;
            return;
        }
        rear->next=nn;
        rear=nn;
    }

    Queue* retFront()
    {
        return front;
    }

    void RightElement(Queue *temp);
};


void BinaryTree::RightView(BinaryTree *temp)
{
    Queue Call, *r;
    Call.Enqueue(temp->num, temp);
    r=Call.retFront();
    Call.RightElement(r);
}


void Queue::RightElement(Queue *temp)
{
    if(temp==NULL)
    {
        return;
    }
    BinaryTree *prev=temp->curr;
    front=rear=NULL;
    Queue Call;
    while(temp!=NULL)
    {
        prev=temp->curr;
        if(temp->curr->left!=NULL)
        {
            Call.Enqueue(temp->curr->left->num, temp->curr->left);
        }
        if(temp->curr->right!=NULL)
        {
            Call.Enqueue(temp->curr->right->num, temp->curr->right);
        }
        temp=temp->next;
    }
    cout<<prev->num<<endl;
    Call.RightElement(Call.retFront());
}

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
    Call.RightView(r);
    return 0;
}
