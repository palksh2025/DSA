class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();

        stack<int> st;

        int i = 0;
        while(i != n){

            if(asteroids[i] > 0){
                st.push(asteroids[i]);
            }

            else{                        //If aster[] < 0
                
                while(!st.empty() && st.top() < -asteroids[i] && st.top() > 0){
                    st.pop();
                }

                if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }

                if(st.top() == -asteroids[i]){
                    st.pop();
                }
            }
            i++;
        }

        int m = st.size();

        vector<int> out(m,0);

        for(int i = m-1; i >=0; i--){
            out[i] = st.top();
            st.pop();
        }
        
        return out;
    }
};