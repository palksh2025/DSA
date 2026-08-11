class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        int n = nums.size();

        int i;
        for(i = 1; i < n; i++){
            if(nums[i] == nums[i-1] + 1){
                sum = sum + nums[i];
            }
            else{
                break;
            }
        }

        sort(nums.begin() + i, nums.end());

        for(--i; i < n; i++){
            if(nums[i] == sum){
                sum++;
            }
            else{
                if(nums[i] >= sum){
                    return sum;
                }
            }
        }

        return sum;

    }
};