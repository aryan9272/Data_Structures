#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void Enqueue(int x)
{               
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL)
    {   
        printf("Queue Overflow\n");
        return ;
    }
    p->data=x;
    p->next=NULL;
    if (front==NULL && rear==NULL)
    {  
         rear=p;
        front=p;
    }
    else{
        rear->next=p;
        rear=p;
    }

}

void Dequeue()
{
    struct node *temp;
    temp=front;
     if (front==NULL && rear==NULL)
    {  
        printf("Queue underFlow\n");
    }
    else{
    printf("%d is dequeue from queue\n",front->data);
    front=front->next;
    free(temp);
    }
    if(rear==front)
    {
        
        front=NULL;
        rear=NULL;
    }
}

void peek()
{
     if (front==NULL && rear==NULL)
    {  
        printf("Queue underFlow\n");
    }
    else{
        printf("Element At Front=%d\n",front->data);
    }
}
void display()
{
    struct node *temp;
    temp=front;
     if (front==NULL && rear==NULL)
    {  
        printf("Queue EMPTY...!\n");
    }
    else{ 
        while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
}
int main()
{
    Enqueue(1);
    Enqueue(2);
    display();
    Enqueue(3);
    peek();
    Dequeue();
    peek();
    Enqueue(4);
    Enqueue(5);
    display();
    Dequeue();
    display();
    Dequeue();
    Dequeue();
    display();
    
        return 0;
}