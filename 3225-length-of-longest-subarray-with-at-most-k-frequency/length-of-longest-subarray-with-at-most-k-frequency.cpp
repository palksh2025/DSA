class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        int left = 0;
        int right = 0;

        mpp[nums[0]]++;

        int maxi = 1;
        for(int i = 1; i < n; i++){
            mpp[nums[i]]++;
            right++;

            if(mpp[nums[i]] > k){
                while(mpp[nums[i]] > k){
                    mpp[nums[left]]--;
                    left++;
                }
            }

            maxi = max(maxi, (right - left + 1));
        }
        
        return maxi;
    }
};