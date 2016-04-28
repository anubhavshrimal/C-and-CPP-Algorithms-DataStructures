#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
}s;

s* create(char);
void inOrder(s *);
void allPath(s *,int);
int height(s*);
void levelOrder(s*,int);
void spiralOrder(s*,int);
void spiralPrint(s* r,int level,int n);
char a[max];

int main()
{
    s *root=NULL;
    root=create('A');
    root->left=create('B');
    root->right=create('C');
    root->left->left=create('D');
    root->left->right=create('E');
    root->left->right->left=create('I');
    root->left->right->right=create('J');
    root->left->right->right->left=create('K');
    root->right->left=create('F');
    root->right->right=create('G');
    root->right->right->left=create('H');
    int n,num,h;
    while(1)
    {
        printf("1. All possible paths\n");
        printf("2. Height of the tree\n");
        printf("3. In Order\n");
        printf("4. Level Order\n");
        printf("5. Spiral Order\n");
        printf("6. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&num);
        system("cls");
        switch(num)
        {
            case 1: allPath(root,0);
                    getch();
                    system("cls");
                    break;
            case 2: h= height(root);
                    printf("height = %d ",h);
                    getch();
                    system("cls");
                    break;
            case 3: inOrder(root);
                    printf("end");
                    getch();
                    system("cls");
                    break;
            case 4: printf("Enter the level you want to print: ");
                    scanf("%d",&n);
                    levelOrder(root,n);
                    printf("end");
                    getch();
                    system("cls");
                    break;

            case 5: spiralOrder(root,height(root));
                    getch();
                    system("cls");
                    break;

            case 6: exit(0);

            default: printf("Invalid Input!!");
                     getch();
                     system("cls");
        }
    }
    return 0;
}

void spiralOrder(s* r,int h)
{
    int level=1;
    if(r==NULL)
    {
        return;
    }
    else
    {
        printf("%c -> ",r->data);
        while(level < h)
        {
            if(level%2!=0)
            {
                spiralPrint(r->left,level,0);
                spiralPrint(r->right,level,0);
            }
            else
            {
                spiralPrint(r->right,level,1);
                spiralPrint(r->left,level,1);
            }
            level++;
        }
        printf("end");
    }
}

void spiralPrint(s* r,int level,int n)
{
    if(r==NULL)
    {
        return;
    }
    else if(level==1)
        {
            printf("%c -> ",r->data);
            return;
        }
    else
        {
            level--;
                if(n==1)
                {
                    spiralPrint(r->right,level,n);
                    spiralPrint(r->left,level,n);
                }
                else
                {
                     spiralPrint(r->left,level,n);
                     spiralPrint(r->right,level,n);
                }
        }
}
void levelOrder(s* r,int level)
{
    if(r==NULL)
    {
        return;
    }
    else if(level==1)
        {
            printf("%c -> ",r->data);
            return;
        }
    else
        {
            level--;
            levelOrder(r->left,level);
            levelOrder(r->right,level);
        }
}

s* create(char A)
{
    s *temp=(s*)malloc(sizeof(s));
    temp->data=A;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void inOrder(s *r)
{
    if(r==NULL)
        return;
    inOrder(r->left);
    printf("%c -> ",r->data);
    inOrder(r->right);

}

void allPath(s *r,int i)
{
    if(r!=NULL)
    {
        a[i++]=r->data;
        allPath(r->left,i);
        allPath(r->right,i);
        if(r->left==NULL && r->right==NULL)
        {
            a[i--]='\0';
            print(a);
            return;
        }
    }
    return;
}

void print(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {
        printf("%c -> ",a[i]);
        i++;
    }
    printf("end");
    printf("\n");
}

int height(s* r)
{
    int hl,hr;
    if(r==NULL)
        return 0;
    hl=height(r->left);
    hr=height(r->right);
    if(hl>hr)
        return hl+1;
    else
        return hr+1;
}





