#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
void display(struct node*head)
{
    //traversing....
printf("Displaying  LL\n ");
struct node*temp=head;
while(temp!=NULL)
{
    printf("%d\t",temp->data);
    temp=temp->next;
}
}

void revLL(struct node*head)
{
    struct node*prevnode=NULL,*temp,*nextnode;
    temp=head;
    nextnode=head;
    while(nextnode!=NULL)
    {
    nextnode=nextnode->next;
    temp->next=prevnode;
    prevnode=temp;
    temp=nextnode;
    }
    head=prevnode;
    printf("DISPLAYING REVERSE LL\n");
    display(head);
}

int mid(struct node* head)
{
    struct node* temp;
    int count=0,i=1;
  temp=head;
while(temp!=NULL)
{
    temp=temp->next;
     count++;
}
//traverse till mid
temp=head;
while (i<(count/2)+1)
{
 temp=temp->next;
 i++;   
}
return temp->data;
}

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
{ head=p;
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
display(head);
printf("\n");
 printf("middle Node DATA=%d\n",mid(head));
revLL(head);
return 0;
}
