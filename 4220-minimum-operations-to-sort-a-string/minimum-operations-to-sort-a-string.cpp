class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string copy = s;
        sort(copy.begin(), copy.end());

        int flag = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != copy[i]){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            return 0;
        }

        if(n == 2){
            return -1;
        }

        int maxi = s[n-1];
        for(int i = 0; i < n-1; i++){
            if(s[i] > maxi){
                maxi = s[i];
            }
        }

        if(maxi == s[n-1]){
            return 1;
        }


        int mini = s[0];
        for(int i = 1; i < n; i++){
            if(s[i] < mini){
                mini = s[i];
            }
        }

        if(mini == s[0]){
            return 1;
        }

        int maxiCount = 0;
        int miniCount = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == maxi){
                maxiCount++;
            }
            if(s[i] == mini){
                miniCount++;
            }
        }

        if(maxiCount == 1 && miniCount == 1 && s[0] == maxi && s[n-1] == mini){
            return 3;
        }

        return 2;
    }
};