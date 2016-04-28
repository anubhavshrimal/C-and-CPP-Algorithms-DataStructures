#include <stdio.h>
#include <stdlib.h>
#define max 10001

void quickSort(int a[],int l,int r);
int partition(int a[],int l,int r);

//main function definition
int main()
{
    int size,i,a[max];
    printf("Enter the array size: ");
    scanf("%d",&size);

    //getting the array input
    printf("Enter the array elements:\n ");
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);

    //calling quick sort function for the array
    quickSort(a,0,size);

    //displaying the sorted array
    printf("After quick sorting the array:\n ");
    for(i=0;i<size;i++)
        printf("%d ",a[i]);
    return 0;
}

//quickSort function definition
void quickSort(int a[],int l,int r)
{
    if(l<r)
    {
        int q=partition(a,l,r); //finding the pivot position in sorted array
        quickSort(a,l,q-1);     //recursive calling before pivot sub array
        quickSort(a,q+1,r);     //recursive calling after pivot sub array
    }
}

//partition function definition
int partition(int a[],int l,int r)
{
    int j,temp,i=l;

    for(j=l;j<r-1;j++)
    {
        //swap values if a[j]<=a[r-1](i.e. pivot)
        if(a[j]<=a[r-1])
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;
        }
    }
    //place pivot at its position by swapping
    temp=a[i];
    a[i]=a[r-1];
    a[r-1]=temp;
    return i;
}















