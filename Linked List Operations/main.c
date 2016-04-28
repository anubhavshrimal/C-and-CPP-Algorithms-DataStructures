#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct node
{
    int info;
    struct node *link;
}*header;


void create();
void display();
void insert_end(int data);
void insert_beg(int data);
void insert_pos(int data,int pos);
void delete_beg();
void delete_end();
void delete_pos(int pos);
void delete_val(int data);
void ascend();


int main()
{
    int choice,data,pos;
    header=NULL;

    while(1)
    {
        system("cls");
        printf("\nSelect your choice: ");
        printf("\n1. Create List ");
        printf("\n2. Insert Node ");
        printf("\n3. Display List ");
        printf("\n4. Delete Node ");
        printf("\n5. Arrange in Ascending order");
        printf("\n6. Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create();
                    break;

            case 2: system("cls");
                    printf("\nSelect your choice: ");
                    printf("\n1. Insert at the End ");
                    printf("\n2. Insert at the Beginning ");
                    printf("\n3. Insert at a Specified Position ");
                    printf("\n4. Back to main menu\n");
                    scanf("%d",&choice);

                    switch(choice)
                    {
                    case 1: system("cls");
                            printf("\nEnter the data of the node: ");
                            scanf("%d",&data);
                            insert_end(data);
                            printf("\nNode inserted at the end of the list");
                            break;

                    case 2: system("cls");
                            printf("\nEnter the data of the node: ");
                            scanf("%d",&data);
                            insert_beg(data);
                            printf("\nNode inserted at the beginning of the list");
                            break;

                    case 3: system("cls");
                            printf("\nEnter the position at which you want to insert the node: ");
                            scanf("%d",&pos);
                            printf("\nEnter the data of the node: ");
                            scanf("%d",&data);
                            insert_pos(data,pos);
                            break;

                    case 4: break;

                    default: printf("Invalid choice!!");

                    }
                    break;

            case 3: display();
                    break;

            case 4: system("cls");
                    printf("\nSelect your choice: ");
                    printf("\n1. Delete from the End ");
                    printf("\n2. Delete from the Beginning ");
                    printf("\n3. Delete from a Specified Position ");
                    printf("\n4. Delete by the data of the node");
                    printf("\n5. Back to main menu\n");
                    scanf("%d",&choice);

                    switch(choice)
                    {
                    case 1: system("cls");
                            delete_end();
                            printf("\nNode deleted from the end of the list");
                            break;

                    case 2: system("cls");
                            delete_beg();
                            printf("\nNode deleted from the beginning of the list");
                            break;

                    case 3: system("cls");
                            printf("\nEnter the position at which you want to delete the node: ");
                            scanf("%d",&pos);
                            delete_pos(pos);
                            break;

                    case 4: system("cls");
                            printf("\nEnter the data which you want to delete: ");
                            scanf("%d",&data);
                            delete_val(data);
                            break;

                    case 5: break;

                    default: printf("Invalid choice!!");

                    }
                    break;

            case 5: ascend();
                    system("cls");
                    printf("\nList rearranged in ascending order");
                    getch();
                    break;

            case 6: exit(0);
                    break;

            default: printf("Invalid choice!!");
                     getch();

        }
    }
    return 0;
}

void create()
{
    system("cls");
    int n,data,i;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));

    printf("\nEnter the number of nodes you want to create: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter the data of node %d: ",i+1);
        scanf("%d",&data);

        if(header==NULL)
        {
            temp->link=NULL;
            temp->info=data;
            header=temp;
        }
        else
        {
            insert_end(data);
        }
    }
    if(n>0)
        printf("\nList Created!!");
    else
        printf("\nList not created");

    getch();
    system("cls");
}

void display()
{
    system("cls");
    struct node *ptr;
    ptr=header;
    if(header==NULL)
    {
        printf("\nEmpty List!!");
        getch();
        return;
    }
    printf("\nList:-\n");
    while(ptr!=NULL)
    {
        printf("%d->",ptr->info);
        ptr=ptr->link;
    }
    printf("End of list");
    getch();
}

void insert_end(int data)
{
    struct node *temp,*ptr;
    temp=(struct node *)malloc(sizeof(struct node));
    ptr=header;
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

void insert_beg(int data)
{
    struct node *temp;
    if(header==NULL)
        printf("\nList does not exist");
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->info=data;
        temp->link=header;
        header=temp;
    }
}

void insert_pos(int data,int pos)
{
    int i;
    struct node *temp,*ptr;
    ptr=header;
    if(header==NULL)
        printf("\nList does not exist");
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        for(i=1;i<pos-1;i++)
        {
            if(ptr!=NULL)
            {
                ptr=ptr->link;
            }
            else
            {
                printf("\nInvalid Position!!");
                return;
            }
        }
        if(ptr->link==NULL)
            insert_end(data);
        else
        {
            temp->link=ptr->link;
            temp->info=data;
            ptr->link=temp;
        }
        printf("\nNode inserted at the specified position of the list");
    }
    getch();
}

void delete_beg()
{
    struct node *ptr;
    ptr=header;
    if(header==NULL)
    {
        printf("\nEmpty List");
    }
    else
    {
        header=ptr->link;
        free(ptr);
    }
}

void delete_end()
{
    struct node *ptr,*prev;
    prev=header;
    if(header==NULL)
        printf("\nEmpty List");
    else
    {
        ptr=prev->link;
        while(ptr->link!=NULL)
            {
                ptr=ptr->link;
                prev=prev->link;
            }
        prev->link=NULL;
        free(ptr);
    }
}

void delete_pos(int pos)
{
    int i;
    struct node *ptr,*prev;
    prev=header;
    if(header==NULL)
        {
            printf("\nEmpty List");
            return;
        }
    if(pos==1)
        delete_beg();
    else
    {
        ptr=prev->link;
        for(i=1;i<pos-1;i++)
        {
            if(ptr!=NULL)
            {
                ptr=ptr->link;
                prev=prev->link;
            }
            else
            {
                printf("\nInvalid Position");
                getch();
                return;
            }
        }
        if(ptr->link==NULL)
            delete_end();
        else
        {
            prev->link=ptr->link;
            free(ptr);
        }
        printf("\nNode Deleted");
        getch();
    }
}

void delete_val(int data)
{
    int flag=0,count=0;
    struct node *ptr,*prev,*temp;
    ptr=header;
    if(header==NULL)
        printf("\nList does not exist");
    else
    {
        while(ptr!=NULL)
        {
            while(header!=NULL && ptr!=NULL && ptr->info==data )
            {
                if(ptr==header)
                {
                    header=ptr->link;
                    temp=ptr;
                    ptr=ptr->link;
                    flag=1;
                    count++;
                }
                else
                {
                    prev->link=ptr->link;
                    temp=ptr;
                    ptr=ptr->link;
                    flag=1;
                    count++;
                }
                free(temp);
            }
            if(header!=NULL && ptr!=NULL && ptr->info!=data)
            {
                prev=ptr;
                ptr=ptr->link;
            }
        }
        if(flag==0)
            {
                printf("\nNo node found with the value %d",data);
            }
        else
            printf("\n%d Node deleted",count);
        getch();
    }
}

void ascend()
{
    struct node *first,*premove,*move,*temp1,*temp2;
    first=header;
    premove=first;
    move=first->link;

    while(move!=NULL)
    {
        if(move->info > first->info)
        {
            temp1=move;
            move=move->link;
            temp2=first;

            while(temp1->info > temp2->link->info && temp1->info != temp2->link->info)
                temp2=temp2->link;

            if(temp2->link == temp1)
                premove=temp1;
            else
            {
                premove->link=move;
                temp1->link=temp2->link;
                temp2->link=temp1;
            }
        }
        else if(move->info < first->info)
        {
            header=move;
            move=move->link;
            premove->link=move;
            header->link=first;
            first=header;
        }
        else
        {
            move=move->link;
            premove=premove->link;
        }
    }
}






