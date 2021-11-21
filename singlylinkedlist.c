#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*temp,*head,*t;
void create();
void insert_first();
void insert_mid();
void insert_end();
void delete_first();
void delete_mid();
void delete_end();
void print();

int main()
{
    int n,i,m,choice;
    char name;
    do{
        printf("enter the choice\n1.create\n2.insert_first\n3.insert_mid\n4.insert_end\n5.delete_first\n6.delete_mid\n7.delete_end\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the number of nodes to be insert:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                  create();  
                }
                print();
                break;
            case 2:
                printf("enter the number of nodes to be inserted:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                 insert_first();  
                }
                print();
                break;
            case 3:
                printf("enter the number of nodes to insert:");
                scanf("%d",&m);
                for(i=0;i<m;i++)
                {
                    insert_mid();
                }
                print();
                break;
            case 4:
                printf("enter the number of nodes to insert:");
                scanf("%d",&m);
                for(i=0;i<m;i++)
                {
                    insert_end();
                }
                print();
                break;
            case 5:
                delete_first();
                print();
                break;
            case 6:
                delete_mid();
                print();
                break;
            case 7:
                delete_end();
                print();
                break;
            default:
                printf("choice is invalid");
                break;
        }
        printf("do you want to continue:");
        scanf(" %c",&name);
        
    }while(name=='y');
}
void create()
{
    int n;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&temp->data);
    if(head==NULL)
    {
       head=temp;
    }
    else
    {
       temp->next=head;
       head=temp;
    }
}
void insert_first()
{
    int x;
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data:");
    scanf("%d",&x);
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
         temp->next=head;
         head=temp;
    }
}
void insert_mid()
{
    int x;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&temp->data);
    temp->next=NULL;
    printf("enter the element to insert after:");
    scanf("%d",&x);
    t=head;
    while(t->data!=x)
    {
        t=t->next;
    }
    temp->next=t->next;
    t->next=temp;
}
void insert_end()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter the data");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=temp;
    }
}
void delete_first()
{
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }
    
}
void delete_mid()
{
    int x;
    printf("enter the front node");
    scanf("%d",&x);
    t=head;
    while(t->data!=x)
    {
        t=t->next;
    }
    free(t->next);
    t->next=t->next->next;             
}
void delete_end()
{
    t=head->next;
    temp=head;
    while(t->next!=NULL)
    {
      temp=temp->next;
      t=t->next;
    }
    free(t);
    temp->next=NULL;

    
    
}
void print()
{
    temp=head;
    printf("\n");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}


