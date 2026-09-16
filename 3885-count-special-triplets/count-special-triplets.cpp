class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        const long long MOD = 1000000007;

        vector<long long> left (200005, 0);
        vector<long long> right (200005, 0);

        for(int i = 0; i < n; i++){
            right[nums[i]]++;
        }

        long long count = 0;

        for(int j = 0; j < n; j++){
            int target = 2*nums[j];

            right[nums[j]]--;

            count = (count + (left[target] * right[target])) % MOD;

            left[nums[j]]++;
        }

        return count;
    }
};