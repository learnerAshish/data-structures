#include<stdio.h>
#include<stdlib.h>
 struct node{
     int data;
     struct node *left;
     struct node *right;
 };

void pre_order(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d ",root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void inorder(struct node *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void post_order(struct node *root)
{
    if(root==NULL)
        return;
    post_order(root->left);
    post_order(root->right);
    printf("%d ",root->data);
}

struct node *new_node(int value)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insert_node(struct node *root,int value)
{
    if(root==NULL)
        return new_node(value);
    if(value < root->data)
        root->left=insert_node(root->left,value);
    else if(value > root->data)
        root->right=insert_node(root->right,value);
    return root;
}

struct node *find_min(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node *delete(struct node *root, int key)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->data>key)
    {
        root->left=delete(root->left,key);
    }
    else if(root->data<key)
    {
        root->right=delete(root->right,key);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)
        {
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)
        {
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        else
        {
            struct node *temp=find_min(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
    struct node *root=NULL;
    int choice=1,data;
    int key;
    while(choice!=0)
    {
        printf("\n1.insert data\n2.pre order traversal\n3.inorder traversal\n4.post order traversal\n5.delete()\n0.exit\n ");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter data: ");
            scanf("%d",&data);
            root=insert_node(root,data);
            break;

            case 2:
            pre_order(root);
            break;

            case 3:
            inorder(root);
            break;

            case 4:
            post_order(root);
            break;

            case 5:
            printf("enter data you want to delete: ");
            scanf("%d",&key);
            delete(root,key);
            break;

            case 0:
            break;

            default:
            printf("wrong choice.\n");
            break;

        }
    }
    return 0;
}
