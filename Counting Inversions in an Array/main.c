#include <stdio.h>
#include <stdlib.h>
#define max 100001

void countInv(long long int a[],long long int l,long long int n,long long int *count);
void countSplit(long long int a[],long long int l,int long mid,long long int n,long long int *count);
int main()
{
    long long int count=0,size,a[max],i;
    printf("Enter array size: ");       //input array size
    scanf("%lld",&size);

    printf("Enter array elements: \n");    //input array elements
    for(i=0;i<size;i++)
        scanf("%lld",&a[i]);

    countInv(a,0,size-1,&count);

    printf("\n Number of inversions are: %lld",count);
    return 0;
}

void countInv(long long int a[],long long int l,long long int n,long long int *count)
{
    if(n==l)
        return;
    int mid=l+(n-l)/2;
    countInv(a,l,mid,count);        //recursive calling for 1st half of array
    countInv(a,mid+1,n,count);      //recursive calling for 2nd half of array
    countSplit(a,l,mid,n,count);       //sorting the two sub arrays and counting inversions
}

void countSplit(long long int a[],long long int l,int long mid,long long int n,long long int *count)
{
    long long int i=l,j=mid+1,k=l,temp[max];

    while((i<=mid)&&(j<=n))
        {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
        {
        //number of inversions = remaining element in the first sub array
            *count=*count+(mid-i+1);
            temp[k++]=a[j++];
        }
        }
    if(i>mid)                   //if first sub array gets exhausted
        {
        while(j<=n)
            temp[k++]=a[j++];
        }
    else
        while(i<=mid)           //if second sub array gets exhausted
            temp[k++]=a[i++];

    for(i=l;i<=n;i++)           //copy sorted array into the original array
        a[i]=temp[i];
}
