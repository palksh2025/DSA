class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<int> out;

        for(int i = 1; i < n; i=i+2){
            out.push_back(nums[i]);
            out.push_back(nums[i-1]);
        }

        return out;
    }
};