#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {

    int n = numCourses;
    *returnSize = 0;

    int* head = malloc(n * sizeof(int));
    int* to = malloc((prerequisitesSize > 0 ? prerequisitesSize : 1) * sizeof(int));
    int* next = malloc((prerequisitesSize > 0 ? prerequisitesSize : 1) * sizeof(int));
    int* indegree = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
        head[i] = -1;

    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        to[i] = course;
        next[i] = head[prereq];
        head[prereq] = i;

        indegree[course]++;
    }

    int* queue = malloc(n * sizeof(int));
    int* order = malloc(n * sizeof(int));

    int front = 0, rear = 0;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int curr = queue[front++];
        order[(*returnSize)++] = curr;

        for (int e = head[curr]; e != -1; e = next[e]) {
            int neighbor = to[e];

            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                queue[rear++] = neighbor;
        }
    }

    free(head);
    free(to);
    free(next);
    free(indegree);
    free(queue);

    if (*returnSize != n) {
        free(order);
        *returnSize = 0;
        return malloc(sizeof(int));
    }

    return order;
}