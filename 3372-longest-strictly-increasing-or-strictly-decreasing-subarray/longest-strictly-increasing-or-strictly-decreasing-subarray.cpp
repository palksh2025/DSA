class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxi = 1;
        int count = 1;

        int flag = -1;
        

        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]){
                flag = -1;
                count = 1;
                continue;
            }
            else if((flag == 1 || flag == -1) && nums[i] > nums[i-1]){
                count++;
                flag = 1;

                if(count > maxi){
                    maxi = count;
                }
            }
            else if((flag == 0 || flag == -1) && nums[i] < nums[i-1]){
                count++;
                flag = 0;

                if(count > maxi){
                    maxi = count;
                }                
            }
            else if(flag == 0 && nums[i] > nums[i-1]){
                count = 2;
                flag = 1;

                if(count > maxi){
                    maxi = count;
                }
            }
            else if(flag == 1 && nums[i] < nums[i-1]){
                count = 2;
                flag = 0;

                if(count > maxi){
                    maxi = count;
                }
            }
            else{
                return -1;
            }
        }

        return maxi;
    }
};