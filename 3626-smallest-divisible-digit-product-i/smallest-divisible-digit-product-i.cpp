class Solution {
public:
    int smallestNumber(int n, int t) {
        int prod = 11;

        if (t == 1){
            return n;
        }

        while(prod % t != 0){
            prod = 1;

            int temp = n;

            while(temp){
                prod = prod * (temp % 10);
                temp = temp / 10;
            }

            n++;
        }

        return --n;
    }
};