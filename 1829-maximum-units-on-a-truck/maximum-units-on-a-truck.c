int compare (const void* a, const void* b){
    int *box1 = *(int **)a;
    int *box2 = *(int **)b;

    return box2[1] - box1[1];
}

int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize) {
    int n = boxTypesSize;
    int m = truckSize;

    int totUnit = 0;

    qsort(boxTypes, boxTypesSize, sizeof(int *), compare);

    int i = 0;
    while(i < n && m > 0){
        int boxes = boxTypes[i][0];
        int units = boxTypes[i][1];

        if (boxes <= m){
            totUnit += boxes * units;
            m = m - boxes;
        }
        else{
            totUnit += m * units;
            m = 0;
        }

        i++;
    }

    return totUnit;
}