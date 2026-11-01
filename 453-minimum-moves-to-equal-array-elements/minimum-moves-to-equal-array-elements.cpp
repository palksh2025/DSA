class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        int mini = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(nums[i] < nums[mini]){
                mini = i;
            }
        }

        return sum - n*nums[mini];
    }
};