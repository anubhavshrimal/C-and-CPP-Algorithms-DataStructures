#include <stdio.h>
#include <stdlib.h>
#define max 10

//main function definition
int main()
{
    long long int size,i,num,a[max],b[15]={0},c[max];

	//getting array length
	printf("enter the size of the array\n");
    scanf("%d",&size);

    //getting the array A input and keeping the key's count in array B
    printf("Enter the array elements\n");
    for(i=0;i<size;i++)
    {
		scanf("%d",&a[i]);
		b[a[i]]++;
	}

	for(i=0;i<15;i++)
    {
		b[i+1]=b[i]+b[i+1];
	}

	for(i=size-1;i>=0;i--)
    {
		c[b[a[i]]]=a[i];
	}

    for(i=0;i<size;i++)
    {
		printf("%d\t",c[i]);
	}
    return 0;
}
