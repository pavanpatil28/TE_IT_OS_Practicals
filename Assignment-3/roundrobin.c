#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, i, qt, cnt = 0, temp, sq = 0, bt[10], wt[10], tat[10], rem_bt[10], at[10];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);-
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    
    printf("Enter the arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d: ", i+1);
        scanf("%d", &at[i]);
    }
    printf("Enter the quantum time: ");
    scanf("%d", &qt);

    int time = 0;

    while (1) {//till  the completion of the program
        bool done = true;

        for (i = 0; i < n; i++) {
            if (rem_bt[i] > 0 && at[i] <= time) {
                done = false;
                
                if (rem_bt[i] > qt) {
                    time += qt;
                    rem_bt[i] -= qt;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i] - at[i];
                    rem_bt[i] = 0;
                    tat[i] = wt[i] + bt[i];
                }
            }
        }

        if (done)
            break;
    }

    printf("\nProcess\tBurst time\tArrival time\tTurnaround time\tWaiting time\n");

    for (i = 0; i < n; i++) {
        atat += tat[i];
        awt += wt[i];
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", i+1, bt[i], at[i], tat[i], wt[i]);
    }

    printf("\n Average waiting time = %f", (float)awt/(float)n);
	printf("\n Average turn around time = %f \n", (float)atat/(float)n);

    return 0;
}
