class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        if (n >= 1 && n <= 8){
            return n;
        }
        else if(n >=9 && n <= 16){
            return 2*(n-8) + 8;
        }
        else if(n >= 17 && n <= 24){
            return 3*(n-16) + 24;
        }
        else{
            return 4*(n-24) + 48;
        }
    }
};