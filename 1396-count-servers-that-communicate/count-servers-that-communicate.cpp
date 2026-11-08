class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& count, int m, int n){
        count++;
        grid[i][j] = 0;

        for(int k = 0; k < m; k++){
            if(grid[k][j] == 1){
                dfs(grid, k, j, count, m, n);
            }
        }

        for(int k = 0; k < n; k++){
            if(grid[i][k] == 1){
                dfs(grid, i, k, count, m, n);
            }
        }

        return;
    }

    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;
        int CommCount = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, count, m, n);
                    if(count > 1){
                        CommCount += count;
                    }
                    count = 0;
                }
            }
        }

        return CommCount;
    }
};