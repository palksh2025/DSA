class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string t;

        if(sum < 10){
            t.push_back(char(sum) + '0');

            while(num != 1){
                t.push_back('0');
                num--;
            }

            return t;
        }

        else{
            t.push_back('9');

            sum = sum - 9;

            while(sum >= 9){
                t.push_back('9');
                sum = sum - 9;
            }

            if(sum != 0){
                t.push_back(char(sum) + '0');
            }

            if(t.size() > num){
                return "";
            }
            if(t.size() < num){
                while(t.size() != num){
                    t.push_back('0');
                }
            }

            return t;
        }

        return "-1";
    }
};