#include<stdio.h>
#include<stdlib.h>
struct number
{
 int size,top,*data;
};
void push(struct number *ptr,int item);
int pop(struct number *ptr);
int peek(struct number *newstack);
void display(struct number *ptr);
int isEmpty(struct number *ptr);
int isFull(struct number *ptr);

int main()
{
 int item,choice=1;
 struct number *newstack=(struct number*)malloc(sizeof(struct number));
 newstack->size=50;
 newstack->top=-1;
 newstack->data=(int *)malloc(newstack->size*sizeof(int));
 while(choice!=0)
 {
 printf("enter 1 for push,2 for pop,3 for peek,4 for displayand 0 for exit:");
 scanf("%d",&choice);
 switch(choice)
 {
  case 1:
  printf("enter the item u want to  push:");
  scanf("%d",&item);
  push(newstack,item);
  break;
  
  case 2:
  item=pop(newstack);
  printf("popped item is : %d\n",item);
  break;
  
  case 3:
  item=peek(newstack);
  printf("peek item is : %d\n",item);
  break;
  
  case 4:
  display(newstack);
  break;
  
  case 0:
  break;
  
  default:
  printf("INVALID CHOICE."); 
 }
 }
 return 0;
}

void push(struct number *ptr,int item)
{
 if(isFull(ptr))
 {
  printf("stack is full.");
 }
 else 
 {
  ptr->top++;
  ptr->data[ptr->top]=item;
 }
}
int pop(struct number *ptr)
{
 if(isEmpty(ptr))
 {
  printf("stack is empty.");
  return -1;
 }
 else 
 {
  int val=ptr->data[ptr->top];
  ptr->top--;
  return val;
 }
}
int peek(struct number *newstack)
{ 
 int a=newstack->top;
 if(a<0)
 {
  printf("not a valid position.");
  return -1;
 }
 else
 {
  return newstack->data[a];
 }
}
void display(struct number *ptr)
{
 if(isEmpty(ptr))
 {
  printf("stack is empty.");
 }
 else
 { 
  for(int i=0;i<=ptr->top;i++)
  {
   printf("%d\n",ptr->data[i]);
  }
 }
}
int isEmpty(struct number *ptr)
{
 if(ptr->top==-1)
 return 1;
 else
 return 0;
}
int isFull(struct number *ptr)
{
 if(ptr->top==ptr->size-1)
 return 1;
 else
 return 0;
}
 
 
 

