/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** constructProductMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    int m = gridColSize[0];    //gridColSize[i] is the no. of columns in the ith row

    int total = n * m;

    int** p = (int **)malloc(n * sizeof(int*));
    *returnColumnSizes = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        p[i] = (int *)malloc(m * sizeof(int));
        (*returnColumnSizes)[i] = m;
    }


    int prefix = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            p[i][j] = prefix;

            prefix = (prefix * (grid[i][j] % 12345)) % 12345;
        }
    }


    int suffix = 1;

    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            p[i][j] = (p[i][j] * suffix) % 12345;

            suffix = (suffix * (grid[i][j] % 12345)) % 12345;
        }
    }

    *returnSize = n;

    return p;
}