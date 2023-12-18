#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NODE;
NODE *head;
void beginsert()
{
    int item;
    NODE newnode = (NODE)malloc(sizeof(NODE));
    if(newnode == NULL)
    {
        printf("error");
    }
    printf("enter the value");
    scanf("%d",&item);
    if(head==NULL)
    {
        newnode->data=item;
        newnode->prev=newnode;
        newnode->next=newnode;
        head = newnode;
        printf("node inserted\n");
    }
    else
    {
        newnode->next = head;
        newnode->prev = head->prev;
        head->prev->next = newnode;
        head->prev = newnode;
        head = newnode;
         printf("node inserted\n");
    }
}
void display()
{
    NODE *temp;
    temp = head ;
    while(temp->next!=head)
    {
        printf("%d",temp->data);
        temp = temp->next;
        
    }
    if(temp->next==head)
    {
        printf("%d",temp->data);
    }
}

int main()
{
    beginsert();
    beginsert();
    beginsert();
    beginsert();
    display();
}
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;
void insertbegin(){
    struct node *new=malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&(new->data));

    if(head==NULL){
        head=new;
        new->next=new;
        new->prev=new;
    }
    else{
        new->next=head;
        new->prev=head->prev;
        head->prev->next=new;
        head->prev=new;
        head=new;
    }
}

void display(){
    struct node *ptr=head;
    do{
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

int main(){
    insertbegin();
    insertbegin();
    insertbegin();
    display();

    return 0;
}



void delete_front()
{
    if(head == NULL)
    {
        printf("LIST IS EMPTY");

    }
    else if(head->next==head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        head->prev->next = head->next;
        head->next->prev= head->prev;
        head=head->next;
    }
}

int main()
{
    
   beginsert();
   beginsert();
   beginsert();
   beginsert();
   delete_front();
    display();
}
