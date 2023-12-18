
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}NODE;
NODE *head;
void beginsert() 
{
     NODE ptr = (NODE)malloc(sizeof(NODE));
     if(ptr == NULL)
    {
         printf("error");
     }
     printf("enter the value\n");
     scanf("%d",&ptr->data);
     if(head ==NULL)
     {
        head = ptr;6
        ptr->next = head;
        printf("node inserted");
     }
     else{
     NODE *temp;
     temp = head;
     while(temp->next!=head)
     {
        temp=temp->next;
     }
     ptr->next = head;
     
     temp->next = ptr;
     head = ptr;

     printf("node inserted\n");
     }
} 


void insert_last()
{
     NODE *tail;
    NODE ptr = (NODE)malloc(sizeof(NODE));
     if(ptr == NULL)
    {
         printf("error");
     }
     printf("enter the value\n");
     scanf("%d",&ptr->data);
     if(head ==NULL)
     {
        head = ptr;
        ptr->next = head;
        printf("node inserted");
     }
     else{
   
    tail=head;
    while(tail->next !=head)
    {
        tail = tail->next;
    }
    tail->next = ptr;
    ptr->next = head;
     }
}
void random_insert()
 {
     int pos;NODE *head;
      NODE ptr = (NODE)malloc(sizeof(NODE));
       if(ptr == NULL)
     {
         printf("error");
     }
     if(head==NULL)
     {
        printf("error");
     }
     else
     {
        NODE *temp ;int item;
        temp= head;
        printf("enter the position");
        scanf("%d",&pos); 
       for(int i = 0;i<pos;i++)
       {
        temp = temp->next;
        if(temp == NULL)
        {
            printf("less elements\n");
          
        } 
       }
        printf("enter the value");
        scanf("%d",&item);
        ptr->data=item;
       ptr->next = temp->next;
       temp->next = ptr;
       
        printf("node inserted\n");
 }
 }
 void delete_front()
 {
    NODE *temp,*tail;
    temp = head;
    tail = head;
    head=head->next;
    while(tail->next!=NULL)
    {
    tail=tail->next;
    }
    tail->next = head;

    free(temp);
}

void delete_last()
{
    NODE *temp,*ptr;
    temp = head;
    while(temp->next!=head)
    {
        ptr = temp;
        temp = temp->next;
    }
    ptr->next = head;
    free(temp);
}

int search()
{
   NODE *temp;int key;
   NODE *tail;
    int index=0;
    if(tail==NULL){
        return -2;
    }
    temp=tail->next;
    do{
        if(temp->data==key){
            return index;
        }
        temp=temp->next;
        index++;
    }
    while(temp!=tail->next);
    return -1;
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
        printf("%d\n",temp->data);
    }
}



int main()
{
    NODE *tail;
   beginsert();
   beginsert();
   beginsert();
   beginsert();
  
  int ele;
    printf("Enter the element:");
    scanf("%d",&ele);
     int ind=search(tail,ele);
     if(ind==-1){
        printf("Element not found\n");
     }
     else if(ind==-2){
        printf("linked list is empty\n");
     }
     else{
        printf("Element %d is at index %d",ele,ind);
     }
   display();

}
