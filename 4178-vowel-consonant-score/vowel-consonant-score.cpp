class Solution {
public:
    int vowelConsonantScore(string s) {
        int n = s.size();

        int countConst = 0;
        int countVow = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                countVow++;
            }
            else if(s[i] > 97 && s[i] <= 122){
                countConst++;
            }
        }

        if(countConst == 0){
            return 0;
        }

        return countVow / countConst;
    }
};