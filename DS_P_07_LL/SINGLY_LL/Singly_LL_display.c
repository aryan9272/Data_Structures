//  a) Write a program to create a singly linked list and display its elements.
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};

int main()
{ 
   // THis is for node creation
struct node*head=NULL,*p,*temp;
int choice;
 do{  
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL)
{
    printf("Memory Allocation Failed\n");
}
printf("Enter Data:\n");
scanf("%d",&p->data);
p->next=NULL;

if (head==NULL)
{
    head=p;
    temp=head;
}
else{
temp->next=p;
temp=p;
}
printf("Do u WAnnt to continue--1\n");
printf("Do u Wannt to STOP--0\n");
scanf("%d",&choice);
}while(choice==1);
//traversing....
printf("Displaying Entered LL\n ");
temp=head;
while(temp!=NULL)
{ printf("%d\t",temp->data);
    temp=temp->next;
}
return 0;
}
