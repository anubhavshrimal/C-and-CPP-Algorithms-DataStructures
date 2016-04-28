#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *link;
}*top;

int check(char c);
void insert(char c);
void push(char c,int value);
void pop();
char printVal(int value);

int j;
char b[7];
int main()
{
    int i,value;
    char a[7]={'a','*','b','+','c','/','e'};
    j=0;
    for(i=0;i<7;i++)
    {
        value=check(a[i]);
        if(value==0)
            insert(a[i]);
        else
            push(a[i],value);
    }
    while(top!=NULL)
        pop();
    for(i=0;i<7;i++)
        printf("%c ",b[i]);
    return 0;
}

int check(char c)
{
    if(c=='+')
        return 1;
    if(c=='-')
        return 2;
    if(c=='*')
        return 3;
    if(c=='/')
        return 4;
    else
        return 0;
}

void insert(char c)
{
    b[j]=c;
    j++;
}

void push(char c,int value)
{
    struct node *temp=((struct node *)malloc(sizeof(struct node)));
    temp->num=value;

    if(top==NULL)
    {
        top=temp;
        temp->link=NULL;
    }
    else
    {
        if(value==4)
        {
            while(top!=NULL && (top->num==3||top->num==4))
                pop();
            temp->link=top;
            top=temp;
            return;
        }
        if(value==3)
        {
            while(top!=NULL && (top->num==3||top->num==4))
                pop();
            temp->link=top;
            top=temp;
            return;
        }
        if(value==2)
        {
            while(top!=NULL && (top->num==2||top->num==1||top->num==3||top->num==4))
                pop();
            temp->link=top;
            top=temp;
            return;
        }

        if(value==1)
        {
            while(top!=NULL && (top->num==2||top->num==1||top->num==3||top->num==4))
                pop();
            temp->link=top;
            top=temp;
            return;
        }
    }
}

void pop()
{
    char ch=printVal(top->num);
    insert(ch);
    struct node *ptr=top;
    top=top->link;
    free(ptr);
}

char printVal(int value)
{
    if(value==1)
        return '+';

    if(value==2)
        return '-';

    if(value==3)
        return '*';

    if(value==4)
        return '/';
}




















