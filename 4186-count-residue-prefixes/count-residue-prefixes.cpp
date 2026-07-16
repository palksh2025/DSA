class Solution {
public:
    int residuePrefixes(string s) {
        int n = s.size();

        int prefixCount = 1;
        int distinctCount = 1;

        for(int i = 1; i < n; i++){
            if(find(s.begin(), s.begin() + i, s[i]) == s.begin() + i){
                distinctCount++;
            }

            if(distinctCount == (i+1) % 3){
                prefixCount++;
            }
        }

        return prefixCount;
    }
};