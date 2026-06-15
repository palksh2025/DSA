class Solution {
public:
    bool isPossible(vector<int>& arr, int m, int barrier){ 
        int n = arr.size();
        
        int allocatedStu = 1;
        int pages = 0;

        for(int i = 0; i < n; i++){
            if (arr[i] > barrier){
                return false;
            }

            if(pages + arr[i] > barrier){
                allocatedStu++;
                pages = arr[i];
            
                if(allocatedStu > m){
                    return false;
                }
            }

            else{
                pages += arr[i];
            }
        }

        return true;
    }

    int splitArray(vector<int>& arr, int m) {
        int n = arr.size();

        if(m > n){
            return -1;
        }

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(isPossible(arr, m, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};