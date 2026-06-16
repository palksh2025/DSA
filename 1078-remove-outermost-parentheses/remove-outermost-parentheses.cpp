class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();

        if(n == 0){
            return {};
        }
        
        if(n % 2 != 0){
            return {};
        }
        
        int lastOpenIndex = 0;
        int countOpen = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                countOpen++;
            }
            else{
                if(countOpen == 1){
                    s.erase(lastOpenIndex, 1);
                    s.erase(i-1, 1);
                    i = i - 2;
                    n = n - 2;
                    lastOpenIndex = i + 1;
                }

                countOpen--;
            }
        }

        return s;
    }
};