class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int> st;
        stack<int> out;

        for(int i = n - 2; i >= 0; i--){
            st.push(nums[i]);
        }

        for(int i = n - 1; i >=0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(st.empty()){
                out.push(-1);
            }
            else{
                out.push(st.top());
            }

            st.push(nums[i]);
        }

        vector<int> ans;
        while(!out.empty()){
            ans.push_back(out.top());
            out.pop();
        }

        return ans;
    }
};