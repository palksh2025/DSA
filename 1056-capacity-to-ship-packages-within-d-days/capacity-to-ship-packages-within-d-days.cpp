class Solution {
public:
    int findDays(vector<int>& weights, int cap){
        int n = weights.size();
        
        int totalDays = 0;
        int filled = 0;

        for(int i = 0; i < n; i++){
            if ((cap - filled) >= weights[i]){
                filled = filled + weights[i];
            }
            else{
                totalDays++;
                filled = weights[i];
            }
        }

        return ++totalDays;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while(low <= high){
            int mid = (low + high) / 2;

            if (findDays(weights, mid) <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};