class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();

        int index = -1;

        for(int i = 0; i < n; i++){
            if(capacity[i] == itemSize){
                return i;                
            }

            if(index == -1 && capacity[i] > itemSize){
                index = i;
            }

            else if(capacity[i] > itemSize && capacity[i] < capacity[index]){
                index = i;
            }
        }

        return index;
    }
};