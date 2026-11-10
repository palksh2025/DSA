class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();

        int i;
        for(i = 0; i < n; i++){
            if(s[i] != ' '){
                break;
            }
        }

        int count = 0;
        for(int j = i; j < n; j++){
            if(count == 1 && s[j] != ' '){
                i = j;
                count = 0;
            }
            if(s[j] == ' ' && count == 0){
                count = 1;
            }
        }

        cout<<i;

        int length = 0;
        for(int j = i; j < n; j++){
            if(s[j] == ' '){
                break;
            }
            length++;
        }

        return length;
    }
};