#include <stdio.h>
#include <stdlib.h>
#define size 10
int main()
{
    int a[size],i,j,temp;
    printf("Enter %d elements:\n",size);
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    for(i=0;i<size;i++)
        for(j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    printf("\nAfter Bubble Sorting:\n");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    return 0;
}
