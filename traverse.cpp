#include "structhead.h"
using namespace std;


int balance_factort(node *tmp)
{
    if(tmp==NULL)
    return 0;
    else
    {
        return height(tmp->left)-height(tmp->right);
    }  
}

void preorder(node *root)
{
    if(root)
    {
        cout<<" "<<root->data<<"\t\t"<<balance_factort(root)<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        cout<<" "<<root->data<<"\t\t"<<balance_factort(root)<<endl;
        inorder(root->right);
    }
}

void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data<<"\t\t"<<balance_factort(root)<<endl;
    }
}