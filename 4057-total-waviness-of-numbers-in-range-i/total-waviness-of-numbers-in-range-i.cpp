class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if (num1 > num2){
            return 0;
        }

        int count = 0;

        for(int i = num1; i <= num2; i++){
            if(i < 100){
                continue;
            }

            vector<int> digits;

            int num = i;

            while(num != 0){
                int lastDigit = num % 10;
                digits.push_back(lastDigit);
                num = num / 10;
            }

            for (int j = 1; j < digits.size() - 1; j++){
                if(digits[j] > digits[j-1] && digits[j] > digits[j+1]){
                    count++;
                }
                else if(digits[j] < digits[j-1] && digits[j] < digits[j+1]){
                    count++;
                }
            }
        }

        return count;
    }
};