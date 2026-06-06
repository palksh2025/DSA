class Solution {
public:
    int lowerBound(vector<int>& nums, int x){
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
    }

    int upperBound(vector<int>& nums, int x){
        return upper_bound(nums.begin(), nums.end(), x) - nums.begin();
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);

        if(lb == nums.size() || nums[lb] != target){
            return {-1,-1};
        }

        return {lb, ub-1};
    }
};