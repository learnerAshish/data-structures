#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

void pre_order(node* root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(node* root)
{
    if(root==NULL) return;
    
    post_order(root->left);
    post_order(root->right);
    printf("%d ",root->data);
}

void in_order(node* root)
{
    if(root==NULL) return;
    
    in_order(root->left);
    printf("%d ",root->data);
    in_order(root->right);
}



int main()
{
    node* root=(node*) malloc(sizeof(node));
    root->data=10;
    
    root->left=(node*) malloc(sizeof(node));
    root->right=(node*) malloc(sizeof(node));
    
    root->left->data=4;
    root->right->data=5;


    root->left->left=(node*) malloc(sizeof(node));
    root->left->right=(node*) malloc(sizeof(node));

    root->left->left->data=14;
    root->left->right->data=15;

    root->right->left=(node*) malloc(sizeof(node));
    root->right->right=(node*) malloc(sizeof(node));
    
    root->right->left->data=114;
    root->right->right->data=115;
    
    root->left->right->left=NULL;
    root->left->right->right=NULL;
    
    root->right->left->left=NULL;
    root->right->left->right=NULL;

    root->left->left->left=NULL;
    root->left->left->right=NULL;
    root->right->right->right=NULL;
    root->right->right->left=NULL;
    
    printf("pre order: ");
    pre_order(root);
    printf("\n");
    printf("post order: ");
    post_order(root);
    printf("\n");
    printf("in order: ");
    in_order(root);
    printf("\n");
    return 0;
}
