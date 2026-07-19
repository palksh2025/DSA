class Solution {
public:
    int countMonobit(int n) {
        if(n == 0){
            return 1;
        }
        else if(n == 1 || n == 2){
            return 2;
        }
        else if(n >= 3 && n < 7){
            return 3;
        }
        else if(n >= 7 && n < 15){
            return 4;
        }
        else if(n >= 15 && n < 31){
            return 5;
        }
        else if(n >= 31 && n < 63){
            return 6;
        }
        else if(n >= 63 && n < 127){
            return 7;
        }
        else if(n >= 127 && n < 255){
            return 8;
        }
        else if(n >= 255 && n < 511){
            return 9;
        }
        else if(n >= 511){
            return 10;
        }

        return -1;
    }
};