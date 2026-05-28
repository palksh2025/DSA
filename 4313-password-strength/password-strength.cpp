class Solution {
public:
    int passwordStrength(string password) {
        set<char> st;

        int n = password.length();

        for(int i = 0; i < n; i++){
            st.insert(password[i]);
        }

        int total = 0;

        for(auto it: st){
            if (it == '!' || it == '@' || it == '#' || it == '$'){
                total = total + 5;
            }

            else if ('0' <= it && it <= '9'){
                total = total + 3;
            }

            else if (97 <= it && it <= 122){
                total++;
            }

            else if('A' <= it && it <= 'Z'){
                total = total + 2;
            }
        }

        return total;
    }
};