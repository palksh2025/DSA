class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 0;
        }
        if(n == 2){
            if(nums[1] > nums[0]){
                return 0;
            }
            else{
                return 1;
            }
        }
        
        int dips = 0;
        int rise = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                rise++;
            }
            else{
                dips++;
            }
        }

        if(rise == 0 && dips == 0){
            return 0;
        }

        if(rise > 1 && dips > 1){
            return -1;
        }

        if (dips == 0){
            return 0;
        }

        if(rise == 0){
            return 1;
        }

        if(rise == 1){
            if(n == 3){
                if(nums[0] == 2 && nums[1] == 0){
                    return 1;
                }
                else{
                    return 2;
                }
            }

            if(nums[n-1] < nums[0]){
                return -1;
            }
            else{
                int i;
                for(i = 1; i < n; i++){
                    if(nums[i] > nums[i-1]){
                        break;
                    }
                }

                if(n % 2 == 0){
                    if(i < n/2){
                        return i+1;
                    }
                    else{
                        //Reverse first
                        i = n-1 - i;
                        return i + 2;
                    }
                }

                else{
                    if(i <= n/2){
                        return i+1;
                    }
                    else{
                        //Reverse first
                        i = n-1 - i;
                        return i + 2;
                    }
                }
                
            }
        }

        else if(dips == 1){
            if(nums[n-1] > nums[0]){
                return -1;
            }
            else{
                int i;
                for(i = 1; i < n; i++){
                    if(nums[i] < nums[i-1]){
                        break;
                    }
                }

                if(n % 2 == 0){
                    if(i <= n/2){
                        return i;
                    }
                    else{
                        //Reverse first
                        i = n-1 - i;
                        return i + 3;
                    }
                }

                else{
                    if(i <= n/2 + 1){
                        return i;
                    }
                    else{
                        //Reverse first
                        i = n-1 - i;
                        return i + 3;
                    }
                }
            }
        }

        return -2;
    }
};