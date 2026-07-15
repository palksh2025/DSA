class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n = nums.size();

        vector<int> out;

        for(int i = 0; i < n; i++){
            if (nums[i] % 2 == 0){
                if(find(nums.begin(), nums.begin() + i, nums[i]) == nums.begin() + i){
                        out.push_back(nums[i]);
                }
                else{
                    if(find(out.begin(), out.end(), nums[i]) != out.end()){
                        int index = find(out.begin(), out.end(), nums[i]) - out.begin();
                        out.erase(out.begin() + index);
                    }
                }
            }
        }

        if(out.empty() == true){
            return -1;
        }

        return out[0];
    }
};