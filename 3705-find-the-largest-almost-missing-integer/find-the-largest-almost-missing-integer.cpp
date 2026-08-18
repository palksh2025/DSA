class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(k == n){
            sort(nums.begin(), nums.end());

            return nums[n-1];
        }

        if(k == 1){
            sort(nums.begin(), nums.end());
            if(nums[n-1] != nums[n-2]){
                return nums[n-1];
            }

            for(int i = n-2; i >= 1; i--){
                if((nums[i-1] != nums[i]) && (nums[i+1] != nums[i])){
                    return nums[i];
                }
            }

            if(nums[0] != nums[1]){
                return nums[0];
            }

            return -1;
        }

        if(nums[0] == nums[n-1]){
            if(k != n){
                return -1;
            }
        }


        int first = nums[0];
        for(int i = 1; i < n-1; i++){
            if(nums[i] == first){
                first = -1;
                break;
            }
        }

        int last = nums[n-1];
        for(int i = 1; i < n-1; i++){
            if(nums[i] == last){
                last = -1;
                break;
            }
        }

        if(first == -1 && last == -1){
            return -1;
        }
        if(first == -1){
            return last;
        }
        if(last == -1){
            return first;
        }

        return max(first, last);
    }
};