class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long sum = 0;

        int n = nums.size();

        for(int i = 0; i < n; i++){
            vector<int> freq (101, 0);
            int count = 0;

            for(int j = i; j < n; j++){
                if(freq[nums[j]] == 0){
                    count++;
                    freq[nums[j]]++;
                }
                
                sum = sum + pow(count, 2);
            }
        }

        return sum;
    }
};