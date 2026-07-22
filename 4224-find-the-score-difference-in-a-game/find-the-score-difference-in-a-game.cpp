class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();

        int p1 = 0;
        int p2 = 0;

        int active = 1;

        for(int i = 0; i < n; i++){
            if (nums[i] % 2 != 0){
                if (active == 1){
                    active = 2;
                }
                else{
                    active = 1;
                }
            }

            if(i % 6 == 5){
                if (active == 1){
                    active = 2;
                }
                else{
                    active = 1;
                }
            }

            if (active == 1){
                p1 += nums[i];
            }
            else {
                p2 += nums[i];
            }
        }

        return p1 - p2;
    }
};