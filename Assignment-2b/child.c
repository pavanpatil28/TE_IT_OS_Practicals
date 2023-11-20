#include <stdio.h>
#include<stdlib.h>
 
void main(int argc, char *argv[])
{ 
    /* argv[0] is the program name */
     
    int *data = (int *) malloc((argc) * sizeof(int));
    for(int i = 0;i < argc;i++) 
    {
        data[i] = atoi(argv[i]);
    }
 
    // Printing Element in Reverse
    printf("\n --> Printing Element in Reverse : \n\n ");
    printf("--> arr[] = [");
    for (int i = argc - 1; i > 0; i--)
    {
          printf(" %d ", data[i]);	
    }
	printf("]");
     
    printf("\n\n --> EXCEV task Completed \n");
}
