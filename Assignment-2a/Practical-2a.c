//Assignment No.2 a)

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void childprocess(int n , int arr[])
{
	//bubble sort  
	for(int i=0;i<n;i++)
	{
		for(int j=i+1 ; j<n;j++)
	    {
	      if(arr[i]>arr[j])
	      {
	         int temp=arr[i];
	         arr[i]=arr[j];
	         arr[j]=temp;
	      }
	   }
	 }
}

 // Quick Sort function
void parentprocess(int arr[], int low, int high)
{
	 int pivot , temp , i ,j;
       if(low < high)
       {
          pivot=low;
          i=low;
          j=high;
          
          while(i<j)
          {
             while(arr[i]<=arr[pivot] && i<high)
             {
                i++;
             }
             
             while(arr[j]>arr[pivot])
             {
                j--;
             }
             
             if(i<j)
             {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
             }
          }
          temp=arr[pivot];
          arr[pivot]=arr[j];
          arr[j]=temp;
          parentprocess(arr,low,j-1);
          parentprocess(arr,j+1,high);
       }
}

int main(void)
{
	int n;
	  
	printf("\n\n >> Enter the Number of Elements = ");
	scanf("%d",&n);
	  
	int arr[n];
	printf("\n");
	
  	for(int i=0;i<n;i++)
  	{
		printf(" >> Enter arr[%d] = ", i);
     	scanf("%d",&arr[i]);
	} 
	printf("\n");	
	
  	int p;
  	p=fork();
  	if(p==-1)
  	{
    	printf("There is an error while calling fork()\n");
  	}
  	if(p==0)
	{
		printf(" --> We are in the child process (Bubble Sort) \n\n");
		printf(" --> Child  => PID: %d\n",getpid());
		//printf(" --> Parent => PID: %d\n", getppid());
		childprocess(n,arr);
		
		printf("\n --> Sorted Array is :- \n\n");
		printf(" --> arr[%d] = [", n);
		for(int i=0 ;i<n;i++)
		{
			printf(" %d",arr[i]);
		}	
		printf(" ] \n\n\n");
	}
  	else
	{
		wait(NULL);
		printf(" --> We are in the parent process (Quick sort) \n\n");
		printf(" --> Parent => PID: %d\n", getpid());
		parentprocess(arr,0,n-1);
		
		printf("\n --> Sorted Array is :- \n\n");
		printf(" --> arr[%d] = [", n);
		for(int i=0 ;i<n;i++)
		{
			printf(" %d",arr[i]);
	   	}
	   	printf(" ] \n\n\n");
	}
  
  return 0;
}



