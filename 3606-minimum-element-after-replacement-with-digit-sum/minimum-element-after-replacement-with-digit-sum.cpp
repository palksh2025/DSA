class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int curr;

        for (int i = 0; i < n; i++){
            if(nums[i] > 9){
                sum = 0;
                curr = nums[i];

                while(curr != 0){
                    sum = sum + curr % 10;
                    curr = curr / 10;
                }

                nums[i] = sum;
            }
        }

        int mini = INT_MAX;

        for (int i = 0; i < n; i++){
            mini = min(mini, nums[i]); 
        }

        return mini;
    }
};