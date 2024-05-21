#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id; 
    int deadline; 
    int profit; 
} Job;
int compare(const void *a, const void *b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}
void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compare);
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }
    int schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; ++i)
        schedule[i] = -1;
    int totalProfit = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = jobs[i].deadline - 1; j >= 0; --j) {
            if (schedule[j] == -1) {
                schedule[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }
    printf("Job Schedule: ");
    for (int i = 0; i < maxDeadline; ++i) {
        if (schedule[i] != -1)
            printf("%d ", schedule[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}
int main() {
    Job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(jobs) / sizeof(jobs[0]);
    printf("Given Jobs:\n");
    printf("Job ID\tDeadline\tProfit\n");
    for (int i = 0; i < n; ++i)
        printf("%d\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
    printf("\n");
    jobSequencing(jobs, n);
    return 0;
}
