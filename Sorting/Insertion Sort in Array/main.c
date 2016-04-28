#include <stdio.h>
#include <stdlib.h>
#define max 30

void insertionSort(int a[],int size);
int main()
{
    int size,i,a[max];
    printf("Enter Array size\n");
    scanf("%d",&size);
    printf("Enter array elements\n");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    insertionSort(a,size);
    printf("After Insertion Sort :\n");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    return 0;
}

insertionSort(int a[],int size)
{
    int i,j,k,temp;
    for(i=1;i<size;i++)
    {
       for(j=0;j<i;j++)
       {
           if(a[i]<a[j])
           {
               temp=a[i];
               for(k=i-1;k>=j;k--)
               {
                   a[k+1]=a[k];
               }
               a[k+1]=temp;
               break;
           }
       }
    }
}















