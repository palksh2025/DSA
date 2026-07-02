class Solution {
public:
    int firstMatchingIndex(string s) {
        int half;

        int n = s.length();
        
        if (n % 2 == 0){
            half = n/2;
        }
        else{
            half = n/2 + 1;
        }

        for (int i = 0; i < half; i++){
            if (s[i] == s[n-1-i]){
                return i;
            }
        }

        return -1;
    }
};