#include <stdio.h>
#include <stdlib.h>
#define max 10001

void quickSort(int a[],int l,int r,int *count);
int partition(int a[],int l,int r);

//main function definition
int main()
{
    int size,i,a[max],count=0;
    printf("Enter the array size: ");
    scanf("%d",&size);

    //getting the array input
    printf("Enter the array elements:\n ");
    for(i=0;i<size;i++)
        scanf("%d ",&a[i]);

    //calling quick sort function for the array
    quickSort(a,0,size,&count);

    //displaying the sorted array
    printf("After quick sorting the array:\n ");
    //for(i=0;i<size;i++)
        printf("%d ",count);
    return 0;
}

//quickSort function definition
void quickSort(int a[],int l,int r,int *count)
{
    if(l<r-1)
    {
        *count=*count+r-l-1;
        int q=partition(a,l,r); //finding the pivot position in sorted array
        quickSort(a,l,q-1,count);     //recursive calling before pivot sub array
        quickSort(a,q+1,r,count);     //recursive calling after pivot sub array
    }
}

//partition function definition
int partition(int a[],int l,int r)
{
    int j,temp,i=l+1;

    for(j=l+1;j<r;j++)
    {
        //swap values if a[j]<=a[r](i.e. pivot)
        if(a[j]<=a[l])
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    //place pivot at its position by swapping
    temp=a[i-1];
    a[i-1]=a[l];
    a[l]=temp;
    return i;
}
