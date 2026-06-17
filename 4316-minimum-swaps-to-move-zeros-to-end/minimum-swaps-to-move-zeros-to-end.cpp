class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = n-1;
        int count = 0;

        while(j > i){
            if(nums[i] == 0){
                if(nums[j] != 0){
                    swap(nums[i], nums[j]);
                    count++;
                    i++;
                }
                else{
                    j--;
                }
            } 
            else{
                i++;
            }
        }

        return count;
    }
};