#include <stdio.h>
int count=0;
void step(int n,char a,char b,char c)
{
    if(n==1)
    {
        count++;
        printf("%c->%c\n",a,c);
    }

    else
    {
        step(n-1,a,c,b);    //moving the top n-1 discs to B rod
        step(1,a,b,c);      //moving the bottom last disc to C rod
        step(n-1,b,a,c);    //moving the discs in B rod to C rod
    }
}
int main()
{
    int n;
    printf("enter the number of steps: ");
    scanf("%d",&n);
    step(n,'A','B','C');
    printf("Number of steps used are:- %d",count);
    return 0;
}
