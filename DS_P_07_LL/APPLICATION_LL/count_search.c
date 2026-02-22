//  a) Write a program to count the number of nodes and search an element in a linked list.
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
//traversing....(COUNTING)&(SEARCHING)
temp=head;
int count=0;
int s,found=0;
printf("Enter Element To SEarrch:\n");
scanf("%d",&s);
while(temp!=NULL)
{
    if (temp->data==s)
    {
      found=1;
    }
    
    temp=temp->next;
    count++;
}
printf("NUMBER OF NODES=%d\n",count);
if (found)
{
    printf("%d Element IS found in LL\n",s);
}
else{
    printf("%d Element IS NOT found in LL \n",s);
}


return 0;
}
