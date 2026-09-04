class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int stable = 0;

        vector<int> maxi;
        vector<int> mini;

        maxi.push_back(nums[0]);
        mini.push_back(nums[n-1]);

        for(int i = 1; i < n; i++){
            maxi.push_back(max(maxi[i-1], nums[i]));
        }

        for(int i = n-2; i >= 0; i--){
            mini.push_back(min(mini[n-i-2], nums[i]));
        }

        reverse(mini.begin(), mini.end());

        int i = 0;
        while(i != n && stable != 1){
            if ((maxi[i] - mini[i]) <= k){
                stable++;
            }
            i++;
        }

        if(stable == 1){
            return --i;
        }

        return -1;
    }
};