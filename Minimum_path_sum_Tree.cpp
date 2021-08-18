
//  MAXIMUM PATH SUM 
// MISTAKENLY SAVED AS MINIMUM PATH SUM

#include<iostream>
#include<climits>

using namespace std;

struct node
{
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right =NULL;
    }
};

int MaxPathSum(node *root, int &res)
{
    if(root == NULL)
        return 0;
    int L = MaxPathSum(root->left, res);
    int R = MaxPathSum(root->right, res);
    int temp = max(L, R) + root->data;
    res = max(res, max(temp, L+R+root->data));
    return temp;
}

void Display(node *root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    Display(root->left);
    Display(root->right);
}


int main()
{
    int res = INT_MIN;
    node *root = new node(10);
    root->left = new node(2);
    root->left->left = new node(20);
    root->left->right = new node(18);
    root->right = new node(-25);
    root->right->left = new node(10);
    root->right->right = new node(200);
    //Display(root);
    MaxPathSum(root, res);
    cout << res ;
    return 0;
}