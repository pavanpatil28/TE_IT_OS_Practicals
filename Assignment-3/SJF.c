// C++ program to implement Shortest Remaining Time First 
// Shortest Remaining Time First (SRTF) 
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

struct Process { 
	int pid; // Process ID 
	int bt; // Burst Time 
	int art; // Arrival Time 
}; 

// Function to find the waiting time for all 
// processes 
void findWaitingTime(struct Process proc[], int n, int wt[]) 
{ 
	int rt[n]; 

	// Copy the burst time into rt[] 
	for (int i = 0; i < n; i++) 
		rt[i] = proc[i].bt; 

	int complete = 0, t = 0, minm = INT_MAX; 
	int shortest = 0, finish_time; 
	bool check = false; 

	// Process until all processes gets 
	// completed 
	while (complete != n) { 

		// Find process with minimum 
		// remaining time among the 
		// processes that arrives till the 
		// current time` 
		for (int j = 0; j < n; j++) { 
			if ((proc[j].art <= t) && 
			(rt[j] < minm) && rt[j] > 0) { 
				minm = rt[j]; 
				shortest = j; 
				check = true; 
			} 
		} 

		if (check == false) { 
			t++; 
			continue; 
		} 

		// Reduce remaining time by one 
		rt[shortest]--; 

		// Update minimum 
		minm = rt[shortest]; 
		if (minm == 0) 
			minm = INT_MAX; 

		// If a process gets completely  executed 
		if (rt[shortest] == 0) { 

			// Increment complete 
			complete++; 
			check = false; 

			// Find finish time of current 
			// process 
			finish_time = t + 1; 

			// Calculate waiting time 
			wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art; 

			if (wt[shortest] < 0) 
				wt[shortest] = 0; 
		} 
		// Increment time 
		t++; 
	} 
} 

// Function to calculate turn around time 
void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) 
{ 
	// calculating turnaround time by adding 
	// bt[i] + wt[i] 
	for (int i = 0; i < n; i++) 
		tat[i] = proc[i].bt + wt[i]; 
} 

// Function to calculate average time 
void findavgTime(struct Process proc[], int n) 
{ 
	int wt[n], tat[n], total_wt = 0, 
					total_tat = 0; 

	// Function to find waiting time of all 
	// processes 
	findWaitingTime(proc, n, wt); 

	// Function to find turn around time for 
	// all processes 
	findTurnAroundTime(proc, n, wt, tat); 

	// Display processes along with all 
	// details 
	printf( " p\t\tBT\t\tWT\t\tTAT\t\t\n");

	// Calculate total waiting time and 
	// total turnaround time 
	for (int i = 0; i < n; i++) { 
		total_wt = total_wt + wt[i]; 
		total_tat = total_tat + tat[i]; 
		printf(" %d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, wt[i], tat[i]);	
	} 

	printf("\n Average waiting time = %f", (float)total_wt/(float)n);
	printf("\n Average turn around time = %f \n", (float)total_tat/(float)n);
} 

// Driver code 
int main() 
{ 
	int n;
	struct Process proc[20];

	printf("Enter the no of the process:");
	scanf("%d", &n);

	printf("\nEnter Procid Burst time Arrival time:\n");

	for(int i=0;i<n;i++){
		scanf("%d %d %d", &proc[i].pid, &proc[i].bt, &proc[i].art);
	}
	printf("\n");

	findavgTime(proc, n); 
	return 0; 
} 
