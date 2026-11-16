class Solution {
public:
    string digitSum(string s, int k) {
        if(s.size() <= k){
            return s;
        }

        string out;

        while(s.size() > k){
            out = "";

            int sum = 0;

            for(int i = 0; i < s.size(); i++){
                sum = sum + int(s[i]-48);

                if(i == s.size()-1){
                    out = out + to_string(sum);
                    break;
                }

                if((i+1) % k == 0){
                    out = out + to_string(sum);
                    sum = 0;
                }
            }

            s = out;
        }

        return out;
    }
};