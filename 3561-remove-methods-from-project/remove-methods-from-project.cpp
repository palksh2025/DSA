class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& suspicious, int node){
        suspicious[node] = true;

        for(auto it: adj[node]){
            if(suspicious[it] == false){
                dfs(adj, suspicious, it);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto& it: invocations){
            adj[it[0]].push_back(it[1]);
        }

        vector<bool> suspicious(n, false);

        dfs(adj, suspicious, k);

        for(auto& it: invocations){
            if(suspicious[it[0]] == false && suspicious[it[1]] == true){
                vector<int> out;
                for (int i = 0; i < n; i++){
                    out.push_back(i);
                }

                return out;
            }
        }

        vector<int> out;
        for (int i = 0; i < n; i++){
            if(suspicious[i] == false){
                out.push_back(i);
            }
        }

        return out;
    }
};