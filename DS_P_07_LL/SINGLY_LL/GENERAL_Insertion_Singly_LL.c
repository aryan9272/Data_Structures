#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};

int main()
{ 
   // THis is for node creation.
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
int count=0,pos;
//For length of LL
temp=head;
while(temp!=NULL)
{
    
    temp=temp->next;
     count++;
}
int i=1;
printf("AT what position u wannt to insert :\n");
scanf("%d",&pos);
if(pos < 1 || pos > count+1)
 {
    printf("Invalid position\n");
}
p=(struct node*)malloc(sizeof(struct node));
//insertIOn in BEg
if(pos==1)
{
    printf("Enter Data:\n");
scanf("%d",&p->data);
    p->next=head;
    head=p;
    
}
else{
temp=head;

while (i<pos-1)
{
 temp=temp->next;
 i++;   
}
printf("Enter Data:\n");
scanf("%d",&p->data);
p->next=temp->next;
temp->next=p;
}
//traversing....
printf("Displaying Entered LL:\n ");
temp=head;
while(temp!=NULL)
{
    printf("%d\t",temp->data);
    temp=temp->next;
}
return 0;
}
