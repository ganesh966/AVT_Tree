#include "structhead.h"
using namespace std;

int height(node *tmp)
{
    if(tmp==NULL)
    return -1;
    else 
    return tmp->height;
}

int balance_factor(node *tmp)
{
    if(tmp==NULL)
    return 0;
    else
    {
        return height(tmp->left)-height(tmp->right);
    }  
}

node* Right_rotate(node *tmp)
{

    node* u = tmp->left;
    tmp->left = u->right;
    u->right = tmp;
    tmp->height = max(height(tmp->left), height(tmp->right))+1;
    u->height = max(height(u->left), tmp->height)+1;
    return u;
}
    

 node* Left_rotate(node *tmp)
 {
    node* u = tmp->right;
    tmp->right = u->left;
    u->left = tmp;
    tmp->height = max(height(tmp->left), height(tmp->right))+1;
    u->height = max(height(tmp->right), tmp->height)+1 ;
    return u;
 }
    
 
node* Right_left_rotate(node *tmp)
{
    tmp->right = Right_rotate(tmp->right);
    return Left_rotate(tmp);
}


node* Left_right_rotate(node *tmp)
{
    tmp->left = Left_rotate(tmp->left);
    return Right_rotate(tmp);
}

node* insert(node *root,int x)
{
    if(root==NULL)
    {
        root=new node();
        root->data = x;
        root->height = 0;
        root->left =root->right = NULL;
    }
    else if(x<root->data)
    {
        root->left = insert(root->left,x);
        if(balance_factor(root)==2)
        {
            if(x <root->left->data)
                root=Right_rotate(root);
            else
                root=Left_right_rotate(root);
        }
    }
    else if(x>root->data)
    {
        root->right=insert(root->right,x);
        if(balance_factor(root)==-2)
        {
            if(x>root->right->data)
                root=Left_rotate(root);
            else
                root=Right_left_rotate(root);
        }
    }

    root->height=max(height(root->left),height(root->right))+1;
    return root;
}