#include<stdio.h> 
#include<stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h> 

void bubbleSort(int arr[],int n)
{
    printf("\n\n --> Sorting Started ");
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
     
    printf("\n --> Sorting Completed! \n\n"); 
    printf(" --> arr[] = [");
    for(int i=0 ;i<n;i++){
    	printf(" %d ",arr[i]);
  	}
  	printf("]");  
}
 
// To Convert Integer to Char*
void tostring(char str[], int num)
{
    int i, rem, len = 0, n;
  
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}
 
int main(int argc, char *argv[])
{
    printf("\n --> This is the main process: ");
    printf("\n --> Process Id: %d",getpid());
    printf("\n --> Parent Id: %d",getppid());
     
    int n;
  
    printf("\n\n >> Enter the Number of elements :: ");
    scanf("%d",&n);
  
  	printf("\n");
    int arr[n];
    for(int i=0;i<n;i++){
	    printf(" >> Enter the Numbers : ");
    	scanf("%d",&arr[i]);
    } 
    printf("\n >> Sorting Array using Bubble Sort : ");
    bubbleSort(arr,n);
 
 
    printf("\n\n >> Forking the current process : ");
    pid_t cpid = fork();
    //The pid_t data type is a signed integer type which is capable of representing a process ID. 
 
 
    if(cpid > 0)//parent process
    {
        printf("\n\n --> Parent is Running:\n --> ParentID: %d \n --> It's ID: %d \n",getppid(),getpid());
 
        printf("\n --> Parent is waiting for child to Complete! \n\n");
         
        wait(NULL);
  
        printf("\n --> Parent is Exiting!! \n\n"); 
    }
    else if(cpid == 0)//child process
    {
        printf("\n\n --> Child is running:\n --> ParentID: %d \n --> It's ID: %d \n",getppid(),getpid());
 
        char *arrChar[n+1];
 
        //Creating Ascii Character Array to Pass as command line Argument
        arrChar[0] = (char *) "child";   // Arg 0 = name of executable file
        for(int i=0;i<n;i++)
        {
            char *string = malloc (sizeof(char) * (20));
            tostring(string,arr[i]);
            arrChar[i+1] = string;
        }
        arrChar[n+1] = NULL;
 
        printf("\n --> Child Calling EXECV System Call:\n");
        execv("./child",arrChar);
 
        printf("\n --> Child EXECV Call Complete\n");
        printf("\n --> Child Execution Complete \n");
    }   
    else if(cpid < 0)
    {
        printf("\n --> Error");
    }
}
