#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *insert_first(struct node **head,struct node *curr)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&new->data);
    if(*head==NULL)
    {
        new->next=new;
        *head=new;
        curr=new;
    }
    else
    {
        new->next=*head;
        curr->next=new;
        *head=new;
    }
    return curr;
}

struct node *insert_last(struct node **head,struct node *curr)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&new->data);
    if(*head==NULL)
    {
        new->next=new;
        *head=new;
        curr=new;
    }
    else
    {
        new->next=*head;
        curr->next=new;
        curr=new; 
    }
    return curr;
}

void insert_random(struct node *head)
{
    int position,data;
    printf("enter key after which you want to enter data: ");
    scanf("%d",&position);
    printf("enter data: ");
    struct node *new=(struct node *)malloc(sizeof(struct node));
    scanf("%d",&new->data);
    while(head->data!=position)
    {
        head=head->next;
    }
    new->next=head->next;
    head->next=new;
}

struct node *delete_first(struct node *head,struct node *curr)
{
    struct node *temp=head;
    if(temp==NULL)
        printf("list is empty.\n");
    else
        printf("deleted element: %d\n",temp->data);
    head=head->next;
    curr->next=head;
    free(temp);
    return head;
}

struct node *delete_last(struct node *head,struct node *curr)
{
    struct node *temp=curr;
    struct node *one=head;
    if(one==NULL)
        printf("list is empty.\n");
    else
    {
        while(one->next!=curr)
        {
            one=one->next;
        }
        printf("deleted element: %d\n",curr->data);
        one->next=curr->next;
        free(temp);
        return head;
    }
}

void delete_random(struct node *head)
{
    struct node *temp=head;
    int position;
    printf("element you want to delete: ");
    scanf("%d",&position);
    while(temp->next->data!=position)
    {
        temp=temp->next;
    }
    struct node *one=temp->next;
    temp->next=temp->next->next;
    free(one);
}

void traversal(struct node *head)
{
    struct node *temp=head;
    while(temp->next!=head)
    {
        printf("%d   ",temp->data);
        temp=temp->next;
    }
    printf("%d   ",temp->data);
}

int main()
{
    struct node *head=NULL;
    struct node *curr=NULL;
    int choice=1;
    while(choice!=0)
    {
    printf("\n1.insert at first\n2.insert at random\n3.insert at last\n4.delete from first\n5.delete from random\n6.delete from last\n7.display\n0.exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
         case 1:
         curr=insert_first(&head,curr);
         break;

          case 2:
          insert_random(head);
          break;

          case 3:
          curr=insert_last(&head,curr);
          break;

          case 4:
          head=delete_first(head,curr);
          break;

          case 5:
          delete_random(head);
          break;

          case 6:
          head=delete_last(head,curr);
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
