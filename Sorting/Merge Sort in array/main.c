#include <stdio.h>
#include <stdlib.h>
#define max 30

void mergeSplit(int a[],int l,int n);
void mergeSort(int a[],int l,int mid,int n);

int main()
{
int n;

printf("enter the number of elements: ");       //input array size
scanf("%d",&n);

printf("enter %d elements: ",n);                //input array
int i,a[max];
for(i=0;i<n;i++)
	scanf("%d",&a[i]);

mergeSplit(a,0,n-1);                //call split function

printf("After merge sort:\n");      //print sorted array
for(i=0;i<n;i++)
    printf("%d ",a[i]);
return 0;
}

void mergeSplit(int a[],int l,int n)
{
if(n<=l)
	return;
int mid=l+(n-l)/2;
mergeSplit(a,l,mid);        //recursive calling for 1st half of array
mergeSplit(a,mid+1,n);      //recursive calling for 2nd half of array
mergeSort(a,l,mid,n);       //sorting the two sub arrays
}

void mergeSort(int a[], int l, int mid, int n)
{
int i=l,j=mid+1,k=l,temp[max];

while((i<=mid)&&(j<=n))
	{
	if(a[i]<a[j])
		temp[k++]=a[i++];
	else
		temp[k++]=a[j++];
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



















