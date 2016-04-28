#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row;
    int col;
}a[250002];
int main()
{
    int t,absi,absj,i,j,k,n;
    long int steps,q,x;
    scanf("%d",&t);
    for(k=0;k<t;k++)
    {
        steps=0;
        scanf("%d ",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                {
                    scanf("%ld",&x);
                    a[x].row=i;
                    a[x].col=j;
                }

        for(q=1;q<=(n*n-1);q++)
        {

            absi=abs(a[q].row-a[q+1].row);
            absj=abs(a[q].col-a[q+1].col);
            steps=steps+absi+absj;
        }
        printf("\n%ld\n",steps);
    }

    return 0;
}
