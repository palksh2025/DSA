class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int dirn){
        if(i >= m || j >= n){
            return 0;
        }

        if(i == m-1 && j == n-1){
            return 1;
        }

        if(dp[i][j][dirn] != -1){
            return dp[i][j][dirn];
        }
        
        //Direction -> 0 - Coming from up. 1 - Coming from right
        if(grid[i][j] == 1){
            if(dirn == 1){
                return dp[i][j][dirn] = dfs(grid, i+1, j, m, n, 0);
            }
            else{
                return dp[i][j][dirn] = dfs(grid, i, j+1, m, n, 1);
            }
        }

        int right = dfs(grid, i, j+1, m, n, 1);
        int down = dfs(grid, i+1, j, m, n, 0);

        return dp[i][j][dirn] = (right + down) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == 1){
            return 0;
        }

        dp.assign(m, vector<vector<int>>(n, {-1,-1}));

        return dfs(grid, 0, 0, m, n, 0);
    }
};