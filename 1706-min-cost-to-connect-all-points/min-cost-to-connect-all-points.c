#include <stdlib.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;

    int *visited = calloc(n, sizeof(int));
    int *dist = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        dist[i] = 2000000000;

    dist[0] = 0;

    int cost = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;
        }

        visited[u] = 1;
        cost += dist[u];

        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int dx = points[u][0] - points[v][0];
                int dy = points[u][1] - points[v][1];

                int distance = abs(dx) + abs(dy);

                if (distance < dist[v])
                    dist[v] = distance;
            }
        }
    }

    free(visited);
    free(dist);

    return cost;
}