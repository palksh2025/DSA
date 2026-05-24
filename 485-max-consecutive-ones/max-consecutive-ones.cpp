class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxm = 0;
        int curr = 0;

        for(int i = 0; i < n; i++){
            if (nums[i] == 1){
                curr++;
                maxm = max(maxm, curr);
            }
            else{
                curr = 0;
            }
        }

        return maxm;
    }
};