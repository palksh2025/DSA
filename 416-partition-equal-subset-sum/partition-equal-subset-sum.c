bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++){
        sum = sum + nums[i];
    }
    if(sum % 2 != 0){
        return false;
    }
    
    int target = sum / 2;

    bool *dp = calloc(target+1, sizeof(bool));
    dp[0] = true;

    for(int i = 0; i < numsSize; i++){
        for(int j = target; j >= nums[i]; j--){
            dp[j] = dp[j] || dp[j-nums[i]];
        }
        if(dp[target] == true){
            bool ans = dp[target];
            free(dp);
            return ans;
        }
    }

    bool ans = dp[target];
    free(dp);
    return ans;
}