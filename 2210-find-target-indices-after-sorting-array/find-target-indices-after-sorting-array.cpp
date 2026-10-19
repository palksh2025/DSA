class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<int> out;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > target){
                break;
            }
            if(nums[i] == target){
                out.push_back(i);
            }
        }

        return out;
    }
};