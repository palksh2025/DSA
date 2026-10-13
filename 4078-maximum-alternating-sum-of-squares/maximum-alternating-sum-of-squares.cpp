class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                nums[i] = abs(nums[i]);
            }
        }
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        long long total = 0;
    
        for(int i = n-1; i >= n/2; i--){
            total = total + pow(nums[i], 2);
        }
        for(int i = n/2 - 1; i >= 0; i--){
            total = total - pow(nums[i], 2);
        }

        return total;
    }
};