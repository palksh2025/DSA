class Solution {
public:
    void addValid(string& s, int& balance, vector<string>& out, string& t, int i, int minRemove, int& removed){
        if(balance < 0){
            return;
        }

        if(removed > minRemove){
            return;
        }

        if(balance > (int)s.size() - i){
            return;
        }

        if(i == s.size()){
            if(balance == 0 && removed == minRemove){
                if(find(out.begin(), out.end(), t) == out.end()){
                    out.push_back(t);
                }
            }
            return;
        }

        //s[i] is a charcter
        if(s[i] != '(' && s[i] != ')'){
            t.push_back(s[i]);
            
            addValid(s, balance, out, t, i+1, minRemove, removed);

            t.pop_back();
            return;
        }

        //Take parenthesis
        t.push_back(s[i]);
        if(s[i] == ')'){
            balance--;
        }
        else if(s[i] == '('){
            balance++;
        }
        addValid(s, balance, out, t, i+1, minRemove, removed);
        t.pop_back();
        if(s[i] == ')'){
            balance++;
        }
        else if(s[i] == '('){
            balance--;
        }

        //Not Take
        removed++;
        addValid(s, balance, out, t, i+1, minRemove, removed);
        removed--;

        return;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> out;
        string t = "";
        int i = 0;
        int balance = 0;
        int removed = 0;
        
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                if(st.empty() || st.top() == ')'){
                    st.push(s[i]);
                }
                else if(st.top() == '('){
                    st.pop();
                }
            }
        }
        int minRemove = st.size();


        addValid(s, balance, out, t, 0, minRemove, removed);

        return out;
    }
};