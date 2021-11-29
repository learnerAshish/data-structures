#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *insert_first(struct node **head)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&new->data);
    new->next=*head;
    new->prev=NULL;
    if(*head!=NULL)
        (*head)->prev=new;
    *head=new;
    return (*head);
}

struct node *insert_last(struct node *head)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&new->data);
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    new->next=NULL;
    new->prev=temp;
    return head;
}

void insert_random(struct node *head)
{
    int position;
    printf("enter key after which you want to enter data: ");
    scanf("%d",&position);
    struct node *new=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    while(head->data!=position)
    {
        head=head->next;
    }
    new->next=head->next;
    new->next->prev=head;
    head->next=new;
    new->prev=head;

}

struct node *delete_first(struct node *head)
{
    struct node *temp=head;
    if(temp==NULL)
        printf("list is empty.\n");
    else
        printf("deleted element: %d\n",temp->data);
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}

struct node *delete_last(struct node *head)
{
    struct node *temp=head;
    if(head==NULL)
        printf("empty.\n");
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct node *one=temp;
        printf("deleted element: %d\n",one->data);
        temp=temp->prev;
        temp->next=NULL;
        free(one);
    }
    return head;
}

void delete_random(struct node *head)
{
    struct node *temp=head;
    int position;
    printf("enter key you want to delete: ");
    scanf("%d",&position);
    while(temp->next->data!=position)
    {
        temp=temp->next;
    }
    struct node *one=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    free(one);  
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
         head=insert_first(&head);
         break;

         case 2:
         insert_random(head);
         break;

         case 3:
         head=insert_last(head);
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
