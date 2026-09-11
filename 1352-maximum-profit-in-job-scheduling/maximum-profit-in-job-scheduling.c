#include <stdlib.h>

typedef struct {
    int start;
    int end;
    int profit;
} Job;

int compareJobs(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;

    return j1->end - j2->end;
}


int jobScheduling(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int* profit, int profitSize) {

    int n = startTimeSize;

    Job *jobs = malloc(n * sizeof(Job));

    for (int i = 0; i < n; i++) {
        jobs[i].start = startTime[i];
        jobs[i].end = endTime[i];
        jobs[i].profit = profit[i];
    }

    qsort(jobs, n, sizeof(Job), compareJobs);

    int *dp = malloc((n + 1) * sizeof(int));

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        Job current = jobs[i - 1];

        int left = 0;
        int right = i - 2;
        int prev = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (jobs[mid].end <= current.start) {
                prev = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int take = current.profit;

        if (prev != -1) {
            take += dp[prev + 1];
        }

        int skip = dp[i - 1];

        dp[i] = (take > skip) ? take : skip;
    }

    int answer = dp[n];

    free(jobs);
    free(dp);

    return answer;
}
