#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data,height;
    struct node *left,*right;
}node;

node* createAVL(node*,int);
node* del(node *,int);
node* inOrderSuccessor(node *);
void inOrder(node *);
int largerHeight(node *,node *);
int getBalFact(node *);
node* leftRotation(node *);
node* rightRotation(node *);

int main()
{
    node *root=NULL;
    int n;
    int num,i,value;
    while(1)
    {
        system("cls");
        printf("1. Create AVL Tree\n"
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
                    root = createAVL(root,value);
                }
                printf("%d Nodes Added\n",num);
                getch();
                break;

            case 2:
                system("cls");
                printf("Enter the data of the node you want to Delete: ");
                scanf("%d",&value);
                root = del(root,value);
                printf("Node Deleted!!");
                printf("%d",root->data);
                getch();
                break;

            case 3:
                system("cls");
                if(root==NULL)
                    printf("Empty Tree\n");
                else
                    inOrder(root);
                    printf("\b\b");
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
node* createAVL(node *r,int value)
{
    //allocating memory and assigning value
    if(r==NULL)
    {
        r=(node*)malloc(sizeof(node));
        r->data=value;
        r->left=NULL;
        r->right=NULL;
        r->height=0;
        return r;
    }
    else    //comparing the value with the value in the node
    {
        if(r->data > value)
            r->left = createAVL(r->left,value);
        else
            r->right = createAVL(r->right,value);

        r->height=largerHeight(r->left,r->right)+1;

        if(getBalFact(r) > 1)
        {
            if(r->left->data > value)
                return rightRotation(r);
            else
            {
                r->left = leftRotation(r->left);
                return rightRotation(r);
            }
        }
        if(getBalFact(r) < -1)
        {
            if(r->right->data <= value)
                return leftRotation(r);
            else
            {
                r->right = rightRotation(r->right);
                return leftRotation(r);
            }
        }
        return r;
    }
}

int largerHeight(node *l,node *r)
{
    if(r==NULL && l==NULL)
        return 0;
    if(r==NULL)
        return (l->height);
    return (r->height);
}

int getBalFact(node *r)
{
    if(r->left==NULL || r->right==NULL)
    {
        if(r->left!=NULL)
            return ((r->left->height) + 1);
        if(r->right!=NULL)
            return (-1 - (r->right->height));
        return 0;
    }
    return ((r->left->height) - (r->right->height));
}

node* leftRotation(node *r)
{
    node *t=r->right;
    node *t1=t->left;
    t->left=r;
    r->right=t1;

    t->height=largerHeight(t->left,t->right)+1;
    r->height=largerHeight(r->left,r->right)+1;

    return t;
}

node* rightRotation(node *r)
{
    node *t=r->left;
    node *t1=t->right;

    t->right=r;
    r->left=t1;

    t->height=largerHeight(t->left,t->right)+1;
    r->height=largerHeight(r->left,r->right)+1;

    return t;
}

node* del(node *r,int value)
{
    if(r==NULL)
        return r;

    if(r->data > value)
        r->left = del(r->left,value);
    else if(r->data < value)
        r->right = del(r->right,value);
    else
    {
        if(r->left==NULL || r->right==NULL)
        {
            node *temp = r->left? r->left : r->right;
            if(temp==NULL)
            {
                temp=r;
                r=NULL;
            }
            else
            {
                *r=*temp;
            }
            free(temp);
        }
        else
        {
            node *temp= inOrderSuccessor(r->right);
            r->data=temp->data;
            r->right=del(r->right,temp->data);
        }
    }

    if(r==NULL)
        return r;

    r->height=largerHeight(r->left,r->right)+1;
    if(getBalFact(r) > 1)
    {
        if( getBalFact(r->left) >= 0 )
            return rightRotation(r);
        else
        {
            r->left=leftRotation(r->left);
            return rightRotation(r);
        }
    }
    if(getBalFact(r) < -1)
    {
        if( getBalFact(r->right) <= 0 )
            return leftRotation(r);
        else
        {
            r->right=rightRotation(r->right);
            return leftRotation(r);
        }
    }
    return r;
}

node* inOrderSuccessor(node* r)
{
    while(r->left!=NULL)
    {
        r=r->left;
    }
    return r;
}
void inOrder(node *r)
{
    if(r!=NULL)
    {
        inOrder(r->left);
        printf("%d -> ",r->data);
        inOrder(r->right);
    }
}


































