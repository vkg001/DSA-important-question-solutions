#include<bits/stdc++.h>

using namespace std;

struct tree
{
    int data;
    tree *left, *right;
    tree (int x)
    {
        data = x;
        left = right = NULL ;
    }
}*root1 = NULL;


map<int, vector<int> >  res;

int Min = INT_MAX;

void Inorder(tree *root,  int key=0)
{
    if(root==NULL)
    {
        return;
    }
    //if(Min > key)   Min = key;
    //cout<<"Key | "<<key<<endl;
    res[key].push_back(root->data);
    Inorder(root->left, key-1);
    Inorder(root->right, key+1);
}




int main()
{
    root1= new tree(1) ;
    root1->left = new tree(5) ;
    root1->left->left = new tree(7) ;
    root1->left->right = new tree(8) ;
    root1->right = new tree(4) ;
    root1->right->right = new tree(9) ;

    Inorder(root1);

    for(auto &var:res)
    {
        for(auto vect: var.second )
        {
            cout<<vect<<"  ";
        }
    }

}
