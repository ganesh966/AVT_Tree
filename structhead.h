#ifndef STRUCTHEAD
#define STRUCTHEAD

#include<bits/stdc++.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
node* insert(node *root,int val);
node* Right_rotate(node *t);
node* Left_rotate(node *t);
node* Right_left_rotate(node *t);
node* Left_right_rotate(node *t);
int balance_factor(node *tmp);
int height(node *tmp);

//traverse
void preorder(node *root);
void inorder(node *root);
void postorder(node *root);
int balance_factort(node *tmp);

#endif
