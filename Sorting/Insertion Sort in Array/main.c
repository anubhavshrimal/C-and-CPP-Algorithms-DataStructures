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

void insertionSort(int a[],int size)
{
    int i,j,x;
    for(i=1;i<size;i++)
    {
        j = i - 1;
        x = a[i];
        while(j >= 0 && a[j] > x){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}















