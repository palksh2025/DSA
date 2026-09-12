class Solution {
public:
    vector<int> dp = vector<int>(46, -1);

    int climbStairs(int n) {
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        int c1 = climbStairs(n-1);
        dp[n-1] = c1;

        int c2 = climbStairs(n-2);
        dp[n-2] = c2;

        return dp[n] = c1 + c2;
        }
};