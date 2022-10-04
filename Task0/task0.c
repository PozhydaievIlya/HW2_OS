#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void outputArray(int a[], int size) //output
{
	printf("Array:");
	for (int i=0;i<size;i++)
	{		
		printf(" %d ",a[i]);
		}
	printf("\n");

}

int returnMin(int a[], int size) //find min element
{

 	int min = a[0];
 	outputArray(a, size);
	for (int i=1; i<size; i++)
	{	
		if (min > a[i])
		min = a[i];
	}
	printf("min: %d\n",min);
	return min;
}
 

int main()
{	
	srand(time(NULL));
	int *MassArray;
	int *temp;
	int n, min;
	printf("Task 0 - mass array problem\nEnter the size of the array (n):");
	scanf("%d",&n);
	MassArray = (int*)malloc(n * sizeof(int));
	temp = (int*)malloc(n * sizeof(int));
	
	for (int i=0; i<=n-1; i++)
		{
			MassArray[i] = rand() %500; 		//array filling 
		}
	
	int index=0; 						//an index to mark the minimum element to remove
	
	while (n>0)
	{
		min = returnMin(MassArray, n); 			//find min element
		for (int i=0; i<=n-1; i++)
			{
				if(MassArray[i] == min)
				{
					index = i;		//mark it
				}		
			}
			
		if (MassArray[index-1] != NULL)
		{
			MassArray[index-1] = MassArray[index] + MassArray[index-1];	//previous element received min element's mass (as default)
			MassArray[index] = 0;						// min element removed 
		}
		else
		{
			MassArray[index+1] = MassArray[index]+MassArray[index+1];	//next element received min element's mass
			MassArray[index]=0;						// min element removed 
		}
			
		n--;
		temp = (int*)realloc(temp, n * sizeof(int));				//temporary array
		
		int j=0;								//new index to walk in may array independently to avoid 0 (deleted element)
		for (int i=0; i<=n-1; i++)
			{
				if(MassArray[j] != 0)					//saving all elements excluding 0 to temporary array
				{
					temp[i] = MassArray[j];
				}
				else
				{
					temp[i]=MassArray[j+1];
					j++;
				}
				j++;			
			}
			
		MassArray = (int*)realloc(temp, n * sizeof(int));			//new arrat with size--
		for (int i=0; i<=n-1; i++)
		{
			MassArray[i] = temp[i];						//copying all elements from temporary to main array
		}
		printf("\n");
		
	}
	free(MassArray);
	free (temp);
	return 0;
}
