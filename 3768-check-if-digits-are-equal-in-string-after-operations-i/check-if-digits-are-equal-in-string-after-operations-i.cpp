class Solution {
public:
    bool hasSameDigits(string s) {
        string t = s;
        
        while(t.size() != 2){
            string x;

            int n = t.size();

            for(int i = 0; i < n-1; i++){
                x = x + char((int(t[i] - 48) + int(t[i+1] - 48)) % 10);
            }

            t = x;
        }

        if(t[0] == t[1]){
            return true;
        }

        return false;
    }
};