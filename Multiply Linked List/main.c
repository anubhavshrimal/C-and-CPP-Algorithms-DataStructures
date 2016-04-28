#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct node
{
    int info;
    struct node *link;
}*start1,*start2,*start3;

void create1();
void create2();
void create3(int);
void insert_end2();
void insert_end1();
int traverse1();
int traverse2();
void display();
void reverse();
int main()
{
    start1=start2=start3=NULL;
    create1();
    create2();
    int num1=traverse1();
    int num2=traverse2();
    int result=num1*num2;
    create3(result);
    reverse();
    display();
    getch();
    return 0;
}
void create1()
{
    int n,data,i;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the number of nodes you want to create: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the data of node %d: ",i+1);
        scanf("%d",&data);

        if(start1==NULL)
        {
            temp->link=NULL;
            temp->info=data;
            start1=temp;
        }
        else
        {
            insert_end1(data);
        }
    }
    if(n>0)
        printf("\nList Created!!");
    else
        printf("\nList not created");
}
void create2()
{
    int n,data,i;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the number of nodes you want to create: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the data of node %d: ",i+1);
        scanf("%d",&data);

        if(start2==NULL)
        {
            temp->link=NULL;
            temp->info=data;
            start2=temp;
        }
        else
        {
            insert_end2(data);
        }
    }
    if(n>0)
        printf("\nList Created!!");
    else
        printf("\nList not created");
}

void insert_end1(int data)
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=start1;
    if(ptr==NULL)
        {
            printf("\nList does not exist");
            getch();
        }
    else
    {
        while(1)
        {
            if(ptr->link!=NULL)
                ptr=ptr->link;
            else
                break;
        }
        temp->info=data;
        temp->link=NULL;
        ptr->link=temp;
    }
}

void insert_end2(int data)
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=start2;
    if(ptr==NULL)
        {
            printf("\nList does not exist");
            getch();
        }
    else
    {
        while(1)
        {
            if(ptr->link!=NULL)
                ptr=ptr->link;
            else
                break;
        }
        temp->info=data;
        temp->link=NULL;
        ptr->link=temp;
    }
}

int traverse1()
{
    struct node *q=start1;
    int num=0,r;
    if(start1==NULL)
    {
        printf("\nmultiplication result = 0");
        getch();
        exit(0);
    }
    while(q!=NULL)
    {
        r=q->info;
        num=num*10+r;
        q=q->link;
    }
    return num;
}
int traverse2()
{
    struct node *q=start2;
    int num=0,r;
    if(start2==NULL)
    {
        printf("\nmultiplication result = 0");
        getch();
        exit(0);
    }
    while(q!=NULL)
    {
        r=q->info;
        num=num*10+r;
        q=q->link;
    }
    return num;
}

void create3(int res)
{
    while(res!=0)
    {
        struct node *temp,*q;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=res%10;
        res=res/10;
        temp->link=NULL;
        if(start3==NULL)
        {
            start3=temp;
        }
        else
        {
            q=start3;
            while(q->link!=NULL)
            {
                q=q->link;
            }
            q->link=temp;
        }
    }
}

void reverse()
{
    struct node *s,*r=NULL,*q;
    q=start3;
    while(q!=NULL)
    {
        s=r;
        r=q;
        q=q->link;
        r->link=s;
    }
    start3=r;
}

void display()
{
    struct node *q;
    q=start3;
    while(q!=NULL)
    {
        printf("%d ->",q->info);
        q=q->link;
    }
    printf("end of list");
}














