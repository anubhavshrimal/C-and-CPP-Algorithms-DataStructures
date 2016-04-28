#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int coef,pow;
    struct node *link;
};

void create(struct node **q);
void display(struct node *q);
void multi(struct node *p1,struct node *p2,struct node **p3);

int main()
{
    struct node *p1=NULL,*p2=NULL,*p3=NULL;
    printf("\nCreating First Polynomial :-");
    create(&p1);
    printf("\nCreating Second Polynomial :-");
    create(&p2);
    display(p1);
    display(p2);
    multi(p1,p2,&p3);
    return 0;
}

void create(struct node **q)
{
    int i,n,c,p;
    struct node *temp,*t;
    t=*q;

    printf("\nEnter the number of nodes you want to create in the polynomial: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));

        printf("\nEnter the coefficient and power of the polynomial\n ");
        scanf("%d",&c);
        scanf("%d",&p);

        if(t==NULL)
        {
            temp->link=NULL;
            temp->coef=c;
            temp->pow=p;
            *q=temp;
            t=*q;
        }
        else
        {
            while(t->link!=NULL)
            {
                t=t->link;
            }
            temp->coef=c;
            temp->pow=p;
            temp->link=NULL;
            t->link=temp;
        }
    }
    if(n>0)
        printf("\nPolynomial Created!!\n");
    else
        printf("\nPolynomial not created\n");
}

void display(struct node *q)
{
    printf("\n");
    if(q==NULL)
    {
        printf("\nEmpty List!!");
        getch();
        return;
    }
    printf("\nList:-\n");
    while(q!=NULL)
    {
        printf("%d x^%d +", q->coef,q->pow);
        q=q->link;
    }
    printf("\b ");
}

void multi(struct node *p1,struct node *p2,struct node **p3)
{
    struct node *t1=p1,*t2=p2,*t3=*p3,*temp;
    if(t1==NULL||t2==NULL)
    {
        printf("\nMultiplication cannot be proceeded");
        return;
    }
    else
    {
        while(t1!=NULL)
        {
            t2=p2;
            while(t2!=NULL)
            {
                temp=(struct node *)malloc(sizeof(struct node));
                temp->coef=t1->coef*t2->coef;
                temp->pow=t1->pow+t2->pow;
                temp->link=NULL;
                if(*p3==NULL)
                {

                }
            }
        }
    }
}
