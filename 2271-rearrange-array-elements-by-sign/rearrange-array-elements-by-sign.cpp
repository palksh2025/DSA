class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> out(n,0);
        int posindex = 0;
        int negindex = 1;

        for(int i = 0; i < n; i++){
            if (nums[i] > 0){
                out[posindex] = nums[i];
                posindex = posindex + 2;
            }
            else{
                out[negindex] = nums[i];
                negindex = negindex + 2;
            }
        }

        return out;
    }
};