class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();

        map <char, int> mpp;

        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }

        vector<pair<char,int>> arr(mpp.begin(), mpp.end());

        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string out;

        for(auto &it: arr){
            out = out + string(it.second,it.first);
        }

        return out;
    }
};