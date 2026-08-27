class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxIndex = 0;

        int i = 0;
        while(i <= maxIndex){
            if(i == n-1){
                return true;
            }

            maxIndex = max(maxIndex, i + nums[i]);
            i++;
        }

        return false;
    }
};