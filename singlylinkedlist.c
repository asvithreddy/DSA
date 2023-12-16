//singly linked list
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE;
//creation of singly linked list

NODE* head; //global variable 
void begininsert();
void lastinsert();
void posinsert();
void begindelete();
void lastdelete();
void posdelete();
void search();
void display();

int main()
{
    int choice=0;
    while(choice!=9)
    {
        printf("Main Menu\n");
        printf("Enter you choice\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("Insertion at the beginning\n");
            begininsert();
            break;
            case 2: printf("Insertion at the end\n");
            lastinsert();
            break;
            case 3: printf("Insertion at a specific position");
            posinsert();
            break;
            case 4: printf("Deletion at the beginning\n");
            begindelete();
            break;
            case 5: printf("Deletion at the end\n");
            lastdelete();
            break;
            case 6: printf("Deletion at a specific position\n");
            break;
            case 7: printf("Search the item linearly");
            break;
            case 8: printf("Display\n");
            display();
            break;
        }
        
    }
    
}

void display()
{
    NODE* temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->link;
    }
}
void begininsert()
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    printf("ERROR");
    else{
    printf("Enter the value\n");
    scanf("%d", &ptr->data);
    ptr->link=head;
    head=ptr;
    printf("Node inserted");
    }
    //display();
}

void lastinsert()
{
    NODE *ptr, *temp;
    ptr=(NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    printf("ERROR");
    else{
    printf("Enter the value\n");
    scanf("%d", &ptr->data);

    if (head==NULL)
    {
        head = ptr;
        ptr->link=NULL;
        printf("Node inserted\n");
    }
    else
    {
        temp=head;
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=ptr;
        ptr->link=NULL;
        printf("Node inserted\n");
    }
    }
}
void posinsert()
{
    NODE *ptr, *temp; int pos;
    ptr=(NODE*)malloc(sizeof(NODE));
    if (ptr==NULL)
    printf("ERROR");

    printf("Enter the value\n");
    scanf("%d", &ptr->data);
    printf("Enter the position\n");
    scanf("%d", &pos);
    temp=head;
    for(int i=0;i<pos;i++)
    {
        temp=temp->link;
    }
    ptr->link=temp->link;
    temp->link=ptr;
    printf("Node inserted\n");
}

void begindelete()
{
    NODE* ptr;
    if (head==NULL)
    printf("Underflow");
    else
    {
        ptr=head;
        head=ptr->link;
        free(ptr);
        printf("Node deleted");
    }
}

void lastdelete()
{
    NODE* ptr, *temp;
    if (head==NULL)
    printf("Error");

    ptr=head;
    while(ptr->link!=NULL)
    {
        temp=ptr;
        ptr=ptr->link;
    }
    temp->link=NULL;
    free(ptr);
    printf("Node deleted");
}

void posdelete()
{
    NODE *ptr, *temp; int pos;
    printf("Enter the position\n");
    scanf("%d", &pos);
    if (head==NULL)
    printf("Error");
    
    ptr=head;
    for (int i=0;i<pos;i++)
    {
        temp=ptr;
        ptr=ptr->link;
    } 
    temp->link=ptr->link;
    free(ptr);
    printf("Node deleted");
}

void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr=head;
    if (ptr==NULL)
    printf("Empty list\n");
    else
    {
        printf("Enter the item you want to search\n");
        scanf("%d", &item);
        while(ptr!=NULL)
        {
            if(ptr->data==item)
            {
                printf("item found at location %d", i+1);
                flag=0;
                break;
            }
            else
            {
                flag=1;
            }
            ptr=ptr->link;
            i++;
        }
    }
}
