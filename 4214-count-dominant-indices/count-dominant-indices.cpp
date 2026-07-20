class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 0;
        }

        vector<int> avg(n-1,-1);

        for(int i = n-2; i >=0; i--){
            int sum = 0;
            int count = 0;

            for(int j = n-1; j > i; j--){
                sum = sum + nums[j];
                count++;
            }

            int average = sum / count;

            avg[i] = average;
        }

        int count = 0;
        for(int i = 0; i < n-1; i++){
            if(nums[i] > avg[i]){
                count++;
            }
        }

        return count;
    }
};