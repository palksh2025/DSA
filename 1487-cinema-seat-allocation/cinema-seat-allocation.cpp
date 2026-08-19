class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int count = 0;

        unordered_map<int, set<int>> rows;       //Storing only rows which have some reserved seats

        for(auto it:  reservedSeats){
            rows[it[0] - 1].insert(it[1] - 1);
        }

        count = count + (n - rows.size()) * 2;

        for(auto [row, seats] : rows){
            int groups = 0;

           if(!seats.count(1) && !seats.count(2) && !seats.count(3) && !seats.count(4)){
                groups++; 
           }

           if(!seats.count(5) && !seats.count(6) && !seats.count(7) && !seats.count(8)){
                groups++;
           }
           
           if(!seats.count(3) && !seats.count(4) && !seats.count(5) && !seats.count(6)){
                if(groups == 0){
                    groups++;
                }
           }

            count += groups;
        }

        return count;
    }
};