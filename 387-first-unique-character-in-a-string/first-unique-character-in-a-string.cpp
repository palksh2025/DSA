class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26, 0);

        for(int i = 0; i < s.size(); i++){
            hash[int(s[i] - 97)]++;
        }

        for(int i = 0; i < s.size(); i++){
            if(hash[int(s[i] - 97)] == 1){
                return i;
            }
        }

        return -1;
    }
};