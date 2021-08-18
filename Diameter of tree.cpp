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
    int Diameter(BinaryTree *temp);
    int height(BinaryTree *temp);

};

int BinaryTree::Diameter(BinaryTree *temp)
{
    if(temp==NULL)
        return 0;
    int x,y,z;
    x=height(temp->left);
    y=height(temp->right);
    z=max(x+y,Diameter(temp->left));
    return(max(z,Diameter(temp->right))+1);
}

int BinaryTree::height(BinaryTree *temp)
{
    if(temp==NULL)
        return 0;
    return (1+max(height(temp->left),height(temp->right)));
}

int main()
{
    int n,i,x;
    BinaryTree root,*temp;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements of tree in preorder format ->\n";
    for(i=0; i<n; i++)
    {
        cin>>x;
        root.Insert(x);
    }
    temp=root.retRoot();
    n=root.Diameter(temp);
    cout<<"Diameter of tree is : "<<n<<endl;
    return 0;
}
