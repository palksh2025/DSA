class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long n = nums.size();

        long long strength = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long long divisor = gcd(nums[i], nums[j]);

                long long temps = (1LL * nums[i] * nums[j]) / (long long)pow(divisor, 2);
                strength = max(strength, temps);
            }
        }

        return strength;
    }
};