#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main()
{  // THis is for node creation.
struct node*head=NULL,*p,*temp,*delete;
int choice;
 do{  
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL)
{ printf("Memory Allocation Failed\n");
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
//DELETION in BEg
    printf("Deleting FIRST NODE WITH DATA=%d:\n",head->data);
    delete=head;
    head=head->next;
    free(delete);//free 1st element
//traversing....
printf("Displaying  LL:\n ");
temp=head;
while(temp!=NULL)
{  printf("%d\t",temp->data);
    temp=temp->next;
}
return 0;
}
