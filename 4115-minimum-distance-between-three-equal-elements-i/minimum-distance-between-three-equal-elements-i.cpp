class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        vector<vector<int>> count(101);

        int n = nums.size();

        for(int i = 0; i < n; i++){
            count[nums[i]].push_back(i);
        }

        int mindis = 501;

        for(int i = 1; i <= 100; i++){
            if(count[i].size() >= 3){
                int j = 0;
                int k = 2;

                while(k < count[i].size()){
                    mindis = min(mindis, (abs(count[i][j] - count[i][j+1]) + abs(count[i][j+1] - count[i][j+2]) + abs(count[i][j+2] - count[i][j])));

                    k++;
                    j++;
                }
            }
        }

        if(mindis == 501){
            return -1;
        }

        return mindis;
    }
};