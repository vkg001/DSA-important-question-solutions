#include <iostream>
#include<vector>
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
}*root1 = NULL , *root2 = NULL ;


void Inorder(vector<int> &vect, tree *root)
{
    if(root==NULL)
    {
        return;
    }
    Inorder(vect, root->left);
    vect.push_back(root->data);
    Inorder(vect, root->right);
}


bool isMirror(tree *original, tree *mirror)
{
    vector<int> org, mirr;
    Inorder(org, original);
    Inorder(mirr, mirror);
    auto it = org.begin();
    int i = mirr.size()-1;
    while(i>=0   &&   it != org.end())
    {
        if(mirr[i] != *it)
            return false;
        it++;
        i--;
    }
    return true;
}

int main()
{
	root1= new tree(1) ;
	root1->left = new tree(5) ;
	root1->left->left = new tree(7) ;
	root1->left->right = new tree(8) ;
	root1->right = new tree(4) ;
	root1->right->right = new tree(9) ;


	root2 = new tree(1) ;
	root2->right = new tree(5) ;
	root2->right->right = new tree(7) ;
	root2->right->left = new tree(8) ;
	root2->left = new tree(4) ;
	root2->left->left = new tree(9) ;

	if(isMirror(root1, root2))
	{
	    cout<<"Mirror"<<endl;
	}
	else
	{
	    cout<<"Not Mirror"<<endl;
	}


	return 0;
}
