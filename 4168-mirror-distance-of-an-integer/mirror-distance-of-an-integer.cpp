class Solution {
public:
    int mirrorDistance(int n) {
        vector<int> nums;

        long long temp = n;
    
        while(temp){
            long long mod = temp % 10;
            nums.push_back(mod);
            temp = temp / 10;
        }

        long long x = 0;


        long long p = nums.size();
        for(int i = 0; i < p; i++){
            x = 10*x + nums[i];
        }

        long long ans = n - x;

        if(ans < 0){
            return -ans;
        }

        return ans;
    }
};