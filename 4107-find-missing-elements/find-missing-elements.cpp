class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int count = nums[0]+1;
        int f = nums[n-1];

        int index = 1;
        vector<int> out;


        while(count < f){
            if(nums[index] == count){
                count++;
                index++;
            }
            else{
                out.push_back(count);
                count++;
            }
        }

        return out;
    }
};