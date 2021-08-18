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


    void DisplayPreOrder(BinaryTree *root);
    void DisplayInOrder(BinaryTree *root);
    void DisplayPostOrder(BinaryTree *root);

};



void BinaryTree::DisplayPreOrder(BinaryTree *temp)
{
    if(temp==NULL)
    {
        return;
    }

    cout<<temp->num<<"  ";
    DisplayPreOrder(temp->left);
    DisplayPreOrder(temp->right);

}


void BinaryTree::DisplayInOrder(BinaryTree *temp)
{
    if(temp==NULL)
    {
        return;
    }

    DisplayInOrder(temp->left);
    cout<<temp->num<<"  ";
    DisplayInOrder(temp->right);

}


void BinaryTree::DisplayPostOrder(BinaryTree *temp)
{
    if(temp==NULL)
    {
        return;
    }

    DisplayPostOrder(temp->left);
    DisplayPostOrder(temp->right);
    cout<<temp->num<<"  ";

}



int main()
{
    BinaryTree root,*temp;
    root.Insert(5);
    root.Insert(9);
    root.Insert(3);
    root.Insert(7);
    root.Insert(10);
    root.Insert(2);
    root.Insert(1);
    root.Insert(6);
    root.Insert(4);
    root.Insert(8);
    temp=root.retRoot();
    cout<<"Pre-order traversal\n";
    root.DisplayPreOrder(temp);
    cout<<"\nInorder traversal\n";
    root.DisplayInOrder(temp);
    cout<<"\nPostorder traversal\n";
    root.DisplayPostOrder(temp);
    return 0;
}
