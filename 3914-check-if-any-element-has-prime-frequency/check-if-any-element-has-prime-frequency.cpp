class Solution {
public:
    bool isPrime(int n){
        if(n == 1){
            return false;
        }

        for(int i = 2; i <= n/2; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(101,0);

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }

        for(int i = 0; i < 101; i++){
            if(freq[i] == 0){
                continue;
            }

            if(isPrime(freq[i])){
                return true;
            }
        }

        return false;
    }
};