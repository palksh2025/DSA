class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int oddCount = 0;
        int evenCount = 0;

        for(int i = 0; i < n; i++){
            if(nums1[i] % 2 == 0){
                evenCount++;
            }
            else{
                oddCount++;
            }
        } 

        sort(nums1.begin(), nums1.end());

        if(oddCount == 0 || evenCount == 0){
            return true;
        }

        if(nums1[0] % 2 != 0){
            return true;
        }
        else{
            return false;
        }
    }
};