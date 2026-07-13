class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.size();

        int last;
        for(int i = n-1; i >= 0; i--){
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'){
                last = i;
                break;
            }
        }

        string out;

        for(int i = 0; i <= last; i++){
            out += s[i];
        }

        return out;
    }
};