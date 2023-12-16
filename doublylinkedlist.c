//doubly linked list

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
}NODE;

//creation of doubly linked list
NODE *head;

void begininsert();
void lastinsert();
void posinsert();
void begindelete();
void lastdelete();
void posdelete();
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
            case 3: printf("Insertion at a specific position\n");
            posinsert();
            break;
            case 4: printf("Deletion at the beginning\n");
            begindelete();
            break;
            case 5: printf("Deletion at the end\n");
            lastdelete();
            break;
            case 6: printf("Deletion at a specific position\n");
            posdelete();
            break;
            // case 7: printf("Search the item linearly");
            // break;
            case 8: printf("Show\n");
            display();
            break;
            case 9: printf("Exit\n");
            exit(0);
            default: printf("Invalid\n");
            break;
        }
        
    }
    
}

void display()
{
    NODE *temp;
    if (head==NULL)
    printf("Nothing to print\n");
    else{
        temp=head;
        while(temp!=NULL)
        {
        printf("%d", temp->data);
        temp=temp->rlink;
        }
    }
}


void begininsert()
{
    NODE *ptr; int item;
    ptr = (NODE*) malloc(sizeof(NODE));
    if (ptr==NULL)
    printf("Error\n");
    else
    {
        printf("enter the value to be inserted\n");
        scanf("%d", &item);
        if (head==NULL)
        {
            ptr->data=item;
            ptr->rlink=NULL;
            ptr->llink=NULL;
            head=ptr;
            printf("Node inserted\n");
        }
        else{
        ptr->data=item;
        ptr->rlink=head;
        ptr->llink=NULL;
        head->rlink=ptr;
        head=ptr;
        printf("Node inserted\n");
        }
    }
}

void lastinsert()
{
    NODE *temp, *ptr;
    int item;
    ptr = (NODE*)malloc(sizeof(NODE*));
    if (ptr==NULL)
    printf("Error\n");
    else
    {
        printf('ENter the value\n');
        scanf("%d",&ptr->data);
        temp=head;

        while(temp->rlink!=NULL)
        {
            temp=temp->rlink;
        }
        temp->rlink=ptr;
        ptr->llink=temp; 
    }
}

void posinsert()
{
    NODE *temp, *ptr; int pos, item;
    ptr = (NODE*)malloc(sizeof(NODE*));
    if (ptr==NULL)
    printf("Error\n");
    else
    {
        temp=head;
        printf("enter the position\n");
        scanf("%d", &pos);
        for (int i=0;i<pos;i++)
        {
            temp=temp->rlink;
            if (temp==NULL)
            {
                printf("there are less elements\n");
                return;
            }
            printf("enter value\n");
            scanf("%d", &item);
            ptr->data=item;
            ptr->llink=temp;
            ptr->rlink=temp->rlink;
            temp->rlink->llink=ptr;
            temp->rlink=ptr;
            printf("Node inserted\n");
        }
    }
}

void begindelete()
{
    NODE *temp;
    temp=head;
    if(head->rlink==NULL)
    {
        free(head);
        printf("node deleted\n");
    }
    else
    {
        head=temp->rlink;
        head->llink=NULL;
        free(temp);
        printf("node deleted\n");
    }
}

void lastdelete()
{
    NODE *temp;
    temp=head;
    if(head->rlink==NULL)
    {
        free(head);
        printf("node deleted\n");
    }
    else
    {
        while(temp->rlink!=NULL)
        temp=temp->rlink;

        temp->llink->rlink=NULL;
        free(temp);
        printf("node deleted\n");
    }
}

void posdelete()
{
    NODE *temp; int pos;
    printf("enter the position\n");
    for (int i=0;i<pos;i++)
    {
        temp=temp->rlink;
    }
    temp->rlink->llink=temp->llink;
    temp->llink->rlink=temp->rlink;
    free(temp);
    printf("node deleted\n");
}
