class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int &flag){
        if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[0].size()-1){
            flag = 1;
            return;
        }

        grid[i][j] = 1;

        if(i != 0 && grid[i-1][j] == 0){
            dfs(grid, i-1, j, flag);
        }

        if(i != grid.size()-1 && grid[i+1][j] == 0){
            dfs(grid, i+1, j, flag);
        }

        if(j != 0 && grid[i][j-1] == 0){
            dfs(grid, i, j-1, flag);
        }

        if(j != grid[0].size()-1 && grid[i][j+1] == 0){
            dfs(grid, i, j+1, flag);
        }

        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    int flag = 0;
                    dfs(grid, i, j, flag);
                    if(flag != 1){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};