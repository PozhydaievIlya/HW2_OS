#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int n=0;
int *Array;
int *temp;

	
void outputArray(int a[], int size) //output
{
	printf("Array:");
	for (int i=0;i<size;i++)
	{		
		printf(" %d ",a[i]);
		}
	printf("\n\n");

}

void add(int item) 
{	
	n++;
	Array = (int*)realloc(Array, n * sizeof(int));
	for (int i=0; i<n; i++)
		if(Array[i]==NULL)
			Array[i]=item;
	
	
	printf("%d added\n",item);
}

void insert(int item, int index)
{	
	temp = (int*)realloc(temp, n * sizeof(int));				
 	for (int i=0; i<n; i++)
 		temp[i]=Array[i];								
	
	n++;
	Array = (int*)realloc(Array, n * sizeof(int));
	for (int i=0; i<n; i++){
		if(i==index-1)
			Array[i]=item;
		if(i>index-1)
			Array[i]=temp[i-1];
		if(i<index-1)
			Array[i]=temp[i];
	}
	
	printf("%d added on %d position\n",item,index);
} 

void size()
{
	printf("Array size: %d\n",n);
}
 
void remove(int index)
{	
	n--;
	temp = (int*)realloc(temp, n * sizeof(int));				

 	Array[index-1]=0;
	int j=0;
	for (int i=0; i<=n-1; i++)
			{
				if(Array[j] != 0)					
				{
					temp[i] = Array[j];
				}
				else
				{
					temp[i] = Array[j+1];
					j++;
				}
				j++;			
			}
	for (int i=0; i<n; i++)
 		Array[i]=temp[i];
 	printf("Element %d deleted\n",index);	
			
}

void set(int index, int item)
{
	for (int i=0; i<n; i++)
	 	if (i==index-1){
	 		Array[i]=item;
	 		printf("Element %d: set as %d\n",index,item);	
	 	}
}

void get(int index)
{
	for (int i=0; i<n; i++)
 		if (i==index-1)
 			printf("Element %d: %d\n",index,Array[i]);	
}

int main()
{	
	Array = (int*)malloc(n * sizeof(int));
	temp = (int*)malloc(n * sizeof(int));
	printf("Task 4 - ArrayList functions\n");
	outputArray(Array, n);
	add(5);
	add(3);
	add(10);
	outputArray(Array, n);
	insert(10,2);
	outputArray(Array, n);
	size();
	outputArray(Array, n);
	remove(2); 
	outputArray(Array, n);
	set(2,66);
	outputArray(Array, n);
	get(2);
	free (Array);
	return 0;
}
