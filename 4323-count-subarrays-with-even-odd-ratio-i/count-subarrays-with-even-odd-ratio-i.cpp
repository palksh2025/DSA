class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        float f = (float)a/b;
        int count = 0;

        for(int i = 0; i < n; i++){
            float countOdd = 0;
            float countEven = 0;

            for(int j = i; j < n; j++){

                if(nums[j] % 2 == 0){
                    countEven++;
                }
                else{
                    countOdd++;
                }

                if (countOdd == 0){
                    continue;
                }

                float fc = countEven / countOdd;

                if(fc <= f){
                    count++;
                }
            }
        } 

        return count;
    }
};