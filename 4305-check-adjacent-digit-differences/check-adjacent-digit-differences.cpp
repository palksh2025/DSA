class Solution {
public:
    int absdif(int n1, int n2){
        if(n1 >= n2){
            return n1 - n2;
        }

        return n2 - n1;
    }

    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();

        int flag = 1;
        for(int i = 0; i < n-1; i++){
            if(absdif(s[i], s[i+1]) > 2){
                flag = 0;
                break;
            }
        }

        if(flag == 1){
            return true;
        }
        
        return false;
    }
};