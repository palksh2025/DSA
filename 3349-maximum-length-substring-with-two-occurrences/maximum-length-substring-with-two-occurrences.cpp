class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mpp;
        int n = s.size();

        int left = 0; 
        int right = 0;

        int maxi = 1;

        mpp[s[0]]++;

        for(int i = 1; i < n; i++){
            right++;
            mpp[s[i]]++;

            if(mpp[s[i]] > 2){
                while(left != i-1 && mpp[s[i]] != 2){
                    mpp[s[left]]--;
                    left++;
                }
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};