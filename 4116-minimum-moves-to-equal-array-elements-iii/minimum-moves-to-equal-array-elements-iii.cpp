class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0];
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            count += (maxi - nums[i]);
        }

        return count;
    }
};