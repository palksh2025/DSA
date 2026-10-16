class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        for(int i = 0; i <= k; i++){
            vector<int> temp = cost;

            for(auto &flight: flights){
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];

                if(cost[u] != INT_MAX && cost[u] + price < temp[v]){
                    temp[v] = cost[u] + price;
                }
            }

            cost = temp;
        }

        if(cost[dst] == INT_MAX){
            return -1;
        }

        return cost[dst];
    }
};