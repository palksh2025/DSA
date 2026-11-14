class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minsum = 1000000;

        for(int i = l; i <= r; i++){
            int j = i-1;
            int sum = 0;
            
            for(int k = 0; k <= j; k++){
                sum = sum + nums[k];
            }
            if(sum > 0 && sum < minsum){
                minsum = sum;
            }

            for(int k = j+1; k < n; k++){
                sum = sum - nums[k-j-1] + nums[k];

                if(sum > 0 && sum < minsum){
                    minsum = sum;
                }
            }
        }


        if(minsum == 1000000){
            return -1;
        }
        return minsum;
    }
};