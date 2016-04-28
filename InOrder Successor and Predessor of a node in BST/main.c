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
void inOrder(node *,node *,int a[]);
int j=0,pos=-1;
int main()
{
    int num,i,value;
    node *root=NULL,*t;
    printf("Enter the number of nodes you want to add: ");
    scanf("%d",&num);
    int a[num];
    for(i=0;i<num;i++)
    {
        printf("Enter the data for the %d node: ",i+1);
        scanf("%d",&value);
        createBST(&root,value);
    }
    printf("%d Nodes Added\n",num);

    t=root->left;    //address of the node for which we have to find the successors
    inOrder(root,t,a);
    for(i=0;i<num;i++)
       printf("%d ->",a[i]);
    if(pos==-1)
        printf("Address not found");
    else if(pos==0)
        printf("inorder predessor = Null\n inorder successor = %d",a[pos+1]);
    else
        printf("inorder predessor = %d\n inorder successor = %d",a[pos-1],a[pos+1]);
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

void inOrder(node *r,node *t,int a[])
{
    if(r!=NULL)
    {
        inOrder(r->left,t,a);
        a[j]=r->data;
        printf("%d ",pos);
        if(r==t)
            pos=j;
        j++;
        inOrder(r->right,t,a);
    }
}


