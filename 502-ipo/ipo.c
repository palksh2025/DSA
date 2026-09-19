typedef struct{
    int capital;
    int profit;
} Project;

void swapProject(Project *a, Project *b) {
    Project temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Project heap[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left].capital < heap[smallest].capital)
        smallest = left;

    if (right < n && heap[right].capital < heap[smallest].capital)
        smallest = right;

    if (smallest != i) {
        swapProject(&heap[i], &heap[smallest]);
        minHeapify(heap, n, smallest);
    }
}

void maxHeapify(int heap[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[left] > heap[largest])
        largest = left;

    if (right < n && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        maxHeapify(heap, n, largest);
    }
}

void maxHeapPush(int heap[], int *size, int value) {
    int i = *size;
    heap[i] = value;
    (*size)++;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

int maxHeapPop(int heap[], int *size) {
    int result = heap[0];

    (*size)--;
    heap[0] = heap[*size];

    maxHeapify(heap, *size, 0);

    return result;
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize) {
    int n = profitsSize;

    Project *projects = malloc(n * sizeof(Project));

    int *profitHeap = malloc(n * sizeof(int));

    int profitSize = 0;

    for (int i = 0; i < n; i++) {
        projects[i].capital = capital[i];
        projects[i].profit = profits[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(projects, n, i);
    }

    int projectCount = n;

    for (int i = 0; i < k; i++) {

        while (projectCount > 0 &&
               projects[0].capital <= w) {

            maxHeapPush(
                profitHeap,
                &profitSize,
                projects[0].profit
            );

            projects[0] = projects[projectCount - 1];
            projectCount--;

            minHeapify(projects, projectCount, 0);
        }

        if (profitSize == 0)
            break;

        w += maxHeapPop(profitHeap, &profitSize);
    }

    free(projects);
    free(profitHeap);

    return w;
}