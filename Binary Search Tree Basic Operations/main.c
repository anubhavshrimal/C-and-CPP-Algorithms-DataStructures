#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;
void createBST(node**,int);
void search(node **root,node **par ,node **x,int num, int* found );
void del(node **,int );
void inOrder(node *);
int main()
{
    node *root=NULL;
    int n;
    int num,i,value;
    while(1)
    {
        system("cls");
        printf("1. Create Binary Search Tree\n"
               "2. Delete a node\n"
               "3. inOrder Display\n"
               "4. Exit\n"
               "Enter Your Choice:- ");
        scanf("%d",&n);
        switch (n)
        {
            case 1:
                system("cls");
                printf("Enter the number of nodes you want to add: ");
                scanf("%d",&num);
                for(i=0;i<num;i++)
                {
                    printf("Enter the data for the %d node: ",i+1);
                    scanf("%d",&value);
                    createBST(&root,value);
                }
                printf("%d Nodes Added\n",num);
                getch();
                break;

            case 2:
                system("cls");
                printf("Enter the data of the node you want to Delete: ");
                scanf("%d",&value);
                del(&root,value);
                getch();
                break;

            case 3:
                system("cls");
                if(root==NULL)
                    printf("Empty Tree\n");
                else
                    inOrder(root);
                getch();
                break;

            case 4:
                system("cls");
                exit(0);

            default:
                system("cls");
                printf("\nWrong Selection");
                getch();
        }


    }
    return 0;
}

//To add a new node to the tree
void createBST(node **r,int value)
{
    //allocating memory and assigning value
    if(*r==NULL)
    {
        *r=(node*)malloc(sizeof(node));
        (*r)->data=value;
        (*r)->left=NULL;
        (*r)->right=NULL;
        return;
    }
    else    //comparing the value with the value in the node
    {
        if((*r)->data > value)
            createBST(&(*r)->left,value);
        else
            createBST(&(*r)->right,value);
    }
}

void del(node **r,int value)
{
    int found;
    node *parent=NULL,*x=NULL,*xsucc;

    if(*r==NULL)
    {
        printf("Tree Underflow\n");
        return;
    }

    search(r,&parent,&x,value,&found);

    if(found==0)
    {
        printf("Node not found\n");
        return;
    }
    if(x->left!=NULL && x->right!=NULL)
    {
        parent=x;
        xsucc=x->right;

        while(xsucc->left!=NULL)
        {
            parent=xsucc;
            xsucc=xsucc->left;
        }

        x->data=xsucc->data;
        x=xsucc;
    }

    if(x->left==NULL && x->right==NULL )
    {
        if(parent!=NULL)
        {
            if(parent->right==x)
                parent->right=NULL;
            else
                parent->left=NULL;
        }
        if(x==*r)
            *r=NULL;
        free(x);
        printf("Node deleted\n");
        return;
    }

    if(x->left!=NULL && x->right==NULL)
    {
        if(parent!=NULL)
        {
            if(parent->right==x)
                parent->right=x->left;
            else
                parent->left=x->left;
        }
        if(x==*r)
            *r=x->left;
        free(x);
        printf("Node deleted\n");
        return;
    }

    if(x->left==NULL && x->right!=NULL)
    {
        if(parent!=NULL)
        {
            if(parent->right==x)
                parent->right=x->right;
            else
                parent->left=x->right;
        }

        if(x==*r)
            *r=x->right;
        free(x);
        printf("Node deleted\n");
        return;
    }
}

void search(node** r,node** parent,node** x,int value,int * found)
{
    node *q=*r;
    *found=0;
    *parent=NULL;

    while(q!=NULL)
    {
        if(q->data==value)
        {
            *found=1;
            *x=q;
            return;
        }
        *parent=q;
        if(q->data>value)
            q=q->left;
        else
            q=q->right;
    }
}

void inOrder(node *r)
{
    if(r!=NULL)
    {
        inOrder(r->left);
        printf("%d\t",r->data);
        inOrder(r->right);
    }
}


































