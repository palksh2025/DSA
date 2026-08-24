class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();

        if(k == 0){
            return n;
        }

        sort(nums.begin(), nums.end());

        int ind = n - k;

        for(int i = ind-1; i >= 0; i--){
            if(nums[i] != nums[ind]){
                return i+1;
            }
        }

        return 0;
    }
};