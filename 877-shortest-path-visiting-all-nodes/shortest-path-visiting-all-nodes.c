#include <stdlib.h>

struct State {
    int node;
    int mask;
    int dist;
};

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int n = graphSize;

    int maskCount = 1 << n;

    int allVisited = maskCount - 1;

    unsigned char* visited =
        (unsigned char*)calloc(n * maskCount, sizeof(unsigned char));

    int capacity = n * maskCount;
    struct State* queue =
        (struct State*)malloc(capacity * sizeof(struct State));

    int front = 0;
    int rear = 0;

    for (int i = 0; i < n; i++) {
        int mask = 1 << i;

        queue[rear++] = (struct State){i, mask, 0};
        visited[i * maskCount + mask] = 1;
    }

    while (front < rear) {
        struct State curr = queue[front++];

        int node = curr.node;
        int mask = curr.mask;
        int dist = curr.dist;

        if (mask == allVisited) {
            free(visited);
            free(queue);
            return dist;
        }

        for (int i = 0; i < graphColSize[node]; i++) {
            int nextNode = graph[node][i];

            int newMask = mask | (1 << nextNode);

            int index = nextNode * maskCount + newMask;

            if (!visited[index]) {
                visited[index] = 1;

                queue[rear++] =
                    (struct State){nextNode, newMask, dist + 1};
            }
        }
    }

    free(visited);
    free(queue);

    return -1;
}
