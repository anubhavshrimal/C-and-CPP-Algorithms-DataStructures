#include <stdio.h>
#define max 30

void build_MaxHeap(int a[],int arraySize);
void max_Heapify(int a[],int i,int heapSize);
void heapSort(int a[],int arraySize);
void swap(int a[],int i,int largest);

int main()
{
	int a[max],arraySize;
	//getting array size
	printf("Enter array size: ");
	scanf("%d",&arraySize);

	//getting array elements
	int i;
	printf("Enter array elements: ");
	for(i=1;i<=arraySize;i++)
		scanf("%d",&a[i]);

	build_MaxHeap(a,arraySize);	//function calling to build max-heap

	heapSort(a,arraySize);		//function calling to sort the array

	//printing the array after sorting
	printf("\nAfter Heap Sort:\n");
	for(i=1;i<=arraySize;i++)
		printf("%d\t",a[i]);

	return 0;
}

//function to build heap from unordered array
void build_MaxHeap(int a[],int arraySize)
{
	int i;
	int heapSize=arraySize;		//initially heapSize is equal to arraySize

	for(i=arraySize/2;i>=1;i--)
		max_Heapify(a,i,heapSize);
}

//function to check whether the element at index  ' i ' satisfy max heap condition
void max_Heapify(int a[],int i,int heapSize)
{
	int l,r,largest;
	l=2*i;
	r=2*i+1;
	if(l<=heapSize)
	{
		if(a[i] < a[l])
			largest=l;
		else
			largest=i;

		if(r<=heapSize && a[largest]<a[r])
			largest=r;

		if(largest!=i)
		{
			swap(a,i,largest);
			max_Heapify(a,largest,heapSize);
		}
	}
}

//function to extract the maximum element from the heap
void heapSort(int a[],int arraySize)
{
	int heapSize=arraySize;
	int i;
	for(i=1;i<arraySize;i++)
	{
		swap(a,1,heapSize);
		max_Heapify(a,1,--heapSize);
	}
}

//function to swap key values in heap
void swap(int a[],int i,int largest)
{
	int temp=a[largest];
	a[largest]=a[i];
	a[i]=temp;
}











