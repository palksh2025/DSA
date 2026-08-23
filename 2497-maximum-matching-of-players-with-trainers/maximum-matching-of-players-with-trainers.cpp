class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size();
        int m = trainers.size();

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0;
        int j = 0;

        while(i < m && j < n){
            if(trainers[i] >= players[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return j;
    }
};