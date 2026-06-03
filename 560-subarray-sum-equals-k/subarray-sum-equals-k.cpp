class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        map<int,int> mpp;
        mpp[0] = 1;

        int preSum = 0;
        int count = 0;

        for (int i = 0; i < n; i++){
            preSum = preSum + nums[i];

            int complement = preSum - k;
            count = count + mpp[complement];

            mpp[preSum]++;
        }

        return count;
    }
};