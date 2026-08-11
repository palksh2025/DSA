class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> out;

        for(int i = 0 ; i < n1; i++){
            int j = 0;
            while(nums1[i] != nums2[j]){
                j++;
            }
            

            int flag = 0;
            for(int k = j+1; k < n2; k++){
                if(nums2[k] > nums2[j]){
                    out.push_back(nums2[k]);
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                out.push_back(-1);
            }
        }

        return out;
    }
};