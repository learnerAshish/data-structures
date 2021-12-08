#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *insert_first(struct node *head)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    int data;
    printf("enter data: ");
    scanf("%d",&data);
    new_node->data=data;
    if(head==NULL)
    {
        new_node->next=NULL;
        head=new_node;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=NULL;
    }
    return head;
}

struct node *insert_last(struct node *head)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    int data;
    printf("enter data: ");
    scanf("%d",&data);
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=(struct node*)malloc(sizeof(struct node));
    temp->next->data=data;
    temp->next->next=NULL;
    return head;
}

struct node *insert_random(struct node *head)
{
    struct node *a=(struct node*)malloc(sizeof(struct node));
    a=head;
    int position,data;
    printf("enter node after which you want to enter data: ");
    scanf("%d",&position);
    printf("enter data: ");
    scanf("%d",&data);
    while(a->data!=position)
    {
        a=a->next;
    }
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=a->next;
    a->next=new_node;
    return head;
}

struct node *delete_first(struct node *head)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    if(temp==NULL)
        printf("list is empty.\n");
    else
        printf("deleted element: %d\n",temp->data);
    head=head->next;
    free(temp);
    return head;
}

struct node *delete_last(struct node *head)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    if(temp==NULL)
        printf("list is empty.\n");
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf("deleted element: %d\n",temp->next->data);
    }
    temp->next=NULL;
    free(temp->next);
    return head;
}

struct node *delete_random(struct node *head)
{
    int position;
    printf("enter element which you want to delete: ");
    scanf("%d",&position);
    struct node *temp=head;
    while(temp->next->data!=position)
    {
        temp=temp->next;
    }
    struct node *a=(struct node*)malloc(sizeof(struct node));
    a=temp->next;
    temp->next=temp->next->next;
    free(a);
    return head;
}

void traversal(struct node *head){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    struct node *head=NULL;
    int choice=1;
    while(choice!=0)
    {
    printf("\n1.insert at first\n2.insert at random\n3.insert at last\n4.delete from first\n5.delete from random\n6.delete from last\n7.display\n0.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
         case 1:
         head=insert_first(head);
         break;

         case 2:
         insert_random(head);
         break;

         case 3:
         insert_last(head);
         break;

         case 4:
         head=delete_first(head);
         break;

         case 5:
         delete_random(head);
         break;

         case 6:
         delete_last(head);
         break;

         case 7:
         traversal(head);
         break;

         case 0:
         break;

         default:
         printf("wrong choice\n");
         break;
    }
    }
    return 0;
}
