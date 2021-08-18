#include<iostream>
#include<vector>
using namespace std;

struct node
{
    int num;
    node *left,*right;
    node(int x)
    {
        num=x;
        right=left=NULL;
    }
}*root;


vector<node*> Construct(int lb, int ub)
{
    vector<node*> Trees;
    if(lb>ub)
    {
        Trees.push_back(NULL);
        return Trees;
    }

    for(int i=lb; i<=ub; i++)
    {
        vector<node*> lefttrees=Construct(lb,i-1);
        vector<node*> righttrees=Construct(i+1,ub);

        for(int j=0; j<lefttrees.size(); j++)
        {
            node* L=lefttrees[j];
            for(int k=0; k<righttrees.size(); k++)
            {
                node* R=righttrees[k];
                node *newnode= new node(i);
                newnode->left=L;
                newnode->right=R;
                Trees.push_back(newnode);
            }
        }
    }
    return Trees;
}

void Display(node* temp)
{
    if(temp==NULL)
        return;
    cout<<temp->num<<"  ";
    Display(temp->left);
    Display(temp->right);
}


int main()
{
    long int i=0;
    vector<node*> Trees=Construct(1,10);
    for(auto it:Trees)
    {
        i++;
        Display(it);
        cout<<endl;
    }
    cout<<"Total BST constructed are "<<i<<endl;
}
