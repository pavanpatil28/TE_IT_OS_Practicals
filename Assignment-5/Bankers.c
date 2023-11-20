//Bankers Algorithm
#include <stdio.h>
#include <stdbool.h>

bool CheckSafe(int n, int m, int alloc[10][10], int max[10][10], int avail[10]) {//SAFETY ALGORITHM
    int ans[n], finish[n];
    for (int i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int work[3];
    for (int i = 0; i < 3; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (max[i][j] - alloc[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; j++) {
                        work[j] += alloc[i][j];
                    }
                    ans[count] = i;
                    finish[i] = 1;
                    count++;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("The given sequence is not safe \n");
            return false;
        }
    }

    printf("Following is the SAFE Sequence \n");

    for (int i = 0; i < n - 1; i++) {
        printf(" P%d ->", i);
    }
    printf(" P%d \n", ans[n-1]);
    return true;
}

bool ResourceRequest(int n, int m, int alloc[10][10], int max[10][10], int avail[10], int process) {// Resource Request Function
    int Req[3];

    printf("Enter the resource request for process P%d \n", process);
    for (int i = 0; i < m; i++) {
        scanf("%d", &Req[i]);
    }

    // Check if the request is valid
    bool valid = true;
    for (int j = 0; j < m; j++) {
        if (Req[j] > (max[process][j] - alloc[process][j]) || Req[j] > avail[j]) {
            valid = false;
            break;
        }
    }

    if (valid) {
        // Changing the actual allocation
        for (int j = 0; j < m; j++) {
            alloc[process][j] += Req[j];
            avail[j] -= Req[j];
        }
        // Checking if the updated state is safe
        if (CheckSafe(n, m, alloc, max, avail)) {

            printf("RESOURCE REQUEST GRANTED\n");
            printf("Updated allocation matrix:\n");

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", alloc[i][j]);
                }
                printf("\n");
            }
            return true;
        }

        else {
            // The request is not safe, revert the changes
            for (int j = 0; j < m; j++) {
                alloc[process][j] -= Req[j];
                avail[j] += Req[j];
            }
        }
    }

    printf("Resource request denied. The request tdgyh not be safe.\n");
    return false;
}

int main() {
    printf("STARTING WITH BANKER'S ALGORITHM\n");
    int n, m, i, j, k, alloc[10][10], max[10][10], avail[10];

    n = 5; // Number of processes
    m = 3; // Number of resources

    printf("Taking input allocation matrix for each process from the user:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter for [ %d ][ %d ]=", i, j);
            scanf("%d", &alloc[i][j]);
            printf("\n");
        }
    }

    printf("Taking input max matrix for each process from the user:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Enter for [ %d ][ %d ]=", i, j);
            scanf("%d", &max[i][j]);
            printf("\n");
        }
    }
    printf("Enter the number of available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    CheckSafe(n, m, alloc, max, avail);

    while (true) {//Till user wants to enter the text
        int process;
        printf("Enter the process that wants a resource request (0 to %d or -1 to exit): ", n-1);
        scanf("%d", &process);

        if (process == -1) {
            break;
        }

        if (process < 0 || process >= n) {
            printf("Invalid process number. \n");
            continue;
        }

        if (ResourceRequest(n, m, alloc, max, avail, process)) {
            printf("Resource request granted. \n");
        } 
        else {
            printf("Resource request denied. \n");
        }
    }

    return 0;
}

