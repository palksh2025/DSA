class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int first = -1;

        int ones = 1;

        int shortest = 101;

        vector<int> indices;
        indices.push_back(-1);
        indices.push_back(-1);

        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                first = i;
                break;
            }
        }

        if(first == -1){
            return "";
        }

        if (first != -1 && k == 1){
            string l;
            l = l + s[first];
            return l;
        }

        for(int i = first+1; i < n; i++){
            if(s[i] == '1'){
                ones++;
            }

            if(ones == k){
                if(shortest == (i - first + 1)){
                    int n1 = indices[0];
                    int n2 = first;

                    while(s[n1] == s[n2]){
                        n1++;
                        n2++;
                    }

                    if (s[n2] == '0'){
                        indices[0] = first;
                        indices[1] = i;
                    }
                }

                if(shortest > (i - first + 1)){
                    indices[0] = first;
                    indices[1] = i;

                    shortest = i - first + 1;

                    cout<<"First: "<<first<<" "<<"i: "<<i<<" "<<"Length: "<<i-first+1<<endl;
                }

                first++;

                if(first == n){
                    break;
                }
                while(s[first] != '1'){
                    first++;

                    if(first == n){
                        break;
                    }
                }
                ones--;

                cout<<"First after moving forward for next iteration: "<<first<<endl;
            }
        }

        string t;

        if(shortest == 101){
            return "";
        }

        for(int i = indices[0]; i <= indices[1]; i++){
            t = t + s[i];
        }

        return t;
    }
};