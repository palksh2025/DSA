class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();

        for(int i = 0; i < n; i++){
            int n1 = words[i].size();
            int j = 0;
            int k = n1-1;

            int flag = 0;

            while(k > j){
                if(words[i][j] != words[i][k]){
                    flag = 1;
                    break;
                }
                k--;
                j++;
            }

            if(flag == 0){
                return words[i];
            }
        }  

        return ""; 
    }
};