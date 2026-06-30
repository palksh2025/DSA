class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m != n){
            return false;
        }

        vector<int> freq(26,0);

        for(int i = 0; i < n; i++){
            freq[s[i] - 'a']++;
        }

        for(int i = 0; i < m; i++){
            freq[t[i] - 'a']--;
        }

        for(auto it: freq){
            if(it != 0){
                return false;
            }
        }

        return true;
    }
};