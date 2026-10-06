class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();

        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                st.push(1);
            }
            else{
                if(st.empty()){
                    st.push(0);
                }
                else if(st.top() == 1){
                    st.pop();
                }
                else{
                    st.push(0);
                }
            }
        }

        return st.size();
    }
};