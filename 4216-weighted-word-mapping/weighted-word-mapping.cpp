class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        
        string out;

        for(int i = 0; i < n; i++){
            int m = words[i].size();

            int weight = 0;
            for(int j = 0; j < m; j++){
                weight = weight + weights[words[i][j] - 'a'];
            }

            weight = weight % 26;

            out = out + char('z' - weight);
        }

        return out;
    }
};