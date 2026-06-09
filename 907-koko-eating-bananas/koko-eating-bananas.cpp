class Solution {
public:
    int findMax(vector<int>& v){
        int maxi = INT_MIN;

        for(int i = 0; i < v.size(); i++){
            maxi = max(maxi, v[i]);   
        }

        return maxi;
    }

    long long totalTime(vector<int>& v, int k){
        long long total = 0;
        
        for(int i = 0; i < v.size(); i++){
            total = total + ceil((double)v[i] / (double)k);
        }

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);

        while(low <= high){
            int mid = (low + high) / 2;

            long long total = totalTime(piles, mid);

            if(total <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }
};