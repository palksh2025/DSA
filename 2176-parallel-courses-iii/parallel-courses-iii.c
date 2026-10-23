int minimumTime(int n, int** relations, int relationsSize, int* relationsColSize, int* time, int timeSize) {
    int *head = (int*)malloc((n + 1) * sizeof(int));
    int *to = (int*)malloc((relationsSize > 0 ? relationsSize : 1) * sizeof(int));
    int *next = (int*)malloc((relationsSize > 0 ? relationsSize : 1) * sizeof(int));
    int *indegree = (int*)calloc(n + 1, sizeof(int));
    int *dp = (int*)malloc((n + 1) * sizeof(int));
    int *queue = (int*)malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < relationsSize; i++) {
        int u = relations[i][0];
        int v = relations[i][1];

        to[i] = v;
        next[i] = head[u];
        head[u] = i;
        indegree[v]++;
    }

    int front = 0, rear = 0;
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = time[i - 1];
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int u = queue[front++];

        if (dp[u] > ans)
            ans = dp[u];

        for (int e = head[u]; e != -1; e = next[e]) {
            int v = to[e];

            if (dp[u] + time[v - 1] > dp[v])
                dp[v] = dp[u] + time[v - 1];

            if (--indegree[v] == 0)
                queue[rear++] = v;
        }
    }

    free(head);
    free(to);
    free(next);
    free(indegree);
    free(dp);
    free(queue);

    return ans;
}