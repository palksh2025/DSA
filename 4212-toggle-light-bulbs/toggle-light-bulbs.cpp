class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        int n = bulbs.size();
        
        map<int, int> mpp;

        for(int i = 0; i < n; i++){
            mpp[bulbs[i]]++;
        }

        vector<int> out;

        for(auto it: mpp){
            if(it.second % 2 != 0){
                out.push_back(it.first);
            }
        }

        sort(out.begin(), out.end());

        return out;
    }
};