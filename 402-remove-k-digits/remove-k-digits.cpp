class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();

        if(num[0] == '0'){
            return num;
        }

        if(k == n){
            return "0";
        }

        stack<char> st;
        st.push(num[0]);
        int i;
        for(i = 1; i < n; i++){
            cout<<st.top()<<" ";
            if(num[i] < st.top()){
                while(!st.empty() && k && st.top() > num[i]){
                    st.pop();
                    k--;
                }

                st.push(num[i]);

                if(k == 0){
                    break;
                }
            }
            else{
                st.push(num[i]);
            }
        }
        i++;

        if(k != 0){
            while(k){
                st.pop();
                k--;
            }
        }

        if(i < n){
            while(i != n){
                st.push(num[i]);
                i++;
            }
        }

        vector<char> unrev;
        while(!st.empty()){
            unrev.push_back(st.top());
            st.pop();
        }

        int m = unrev.size();

        int j = m-1;
    
        while(unrev[j] == '0'){
            j--;
            if(j == -1){
                return "0";
            }
        }


        string out;

        for(int i = j; i >= 0; i--){
            out += unrev[i];
        }

        return out;


    }
};