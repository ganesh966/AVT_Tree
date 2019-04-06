#include "structhead.h"
using namespace std;

node* predecessor(node *tmp)
{
    node *tmp1=tmp;
    while(tmp)
    {
        tmp1=tmp;
        tmp=tmp->right;
    }
return tmp1;
}


node* remove(node *root,int val)
{
    if(root==NULL)
    return NULL;
    else if(root->data>val)
    {
        root->left=remove(root->left,val);
    }
    else if(root->data<val)
    {
        root->right=remove(root->right,val);
    }
    else if(root->left && root->right)
    {
        node *tmp=predecessor(root->left);
        root->data=tmp->data;
        root->left=remove(root->left,tmp->data);
    }
    else
    {
        if(root->left==NULL)
        root=root->right;
        else
        root=root->left; 
    }

    if(root==NULL)
    return NULL;

    root->height=max(height(root->left),height(root->right))+1;

//left unbalanced
    if(balance_factor(root)==2) 
    {
        if(balance_factor(root->left)==1) //Left-Left
        return Right_rotate(root);
        else
        return Left_right_rotate(root); // Left-Right 
    }

//right unbalanced
    if(balance_factor(root)==-2)
    {
        if(balance_factor(root->right)==-1) //Right-right 
        {
            return Left_rotate(root); 
        }
        else
        {
            return Right_left_rotate(root); //right-left
        }
        
    }
    return root;

}