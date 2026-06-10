class Solution {
public:
    bool possible(vector<int>& bloomDay, int days, int m, int k){
        int n = bloomDay.size();

        int count = 0;                 
        int noOfB = 0;                       

        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= days){
                count++;
            }
            else{
                noOfB = noOfB + (count / k);
                count = 0;
            }
        }

        noOfB = noOfB + (count / k);  

        return (noOfB >= m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = 1LL * m * k;

        if(val > n){
            return -1;  
        }

        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }

        int low = mini;
        int high = maxi;

        while(low <= high){
            int mid = (low + high) / 2;

            if(possible(bloomDay, mid, m, k) == 1){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};