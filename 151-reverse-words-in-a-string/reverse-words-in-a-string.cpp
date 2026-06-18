class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        string out;

        vector<vector<char>> words;
        words.push_back(vector<char>());
        int wordCount = 0;

        int i;
        for(i = 0; i < n; i++){
            if(s[i] != ' '){
                words[wordCount].push_back(s[i]);
            }
            else{
                if(i != 0 && s[i-1] != ' '){
                    words.push_back(vector<char>());
                    wordCount++;
                }
            }
        }

        if(s[i-1] != ' '){
            wordCount++;
        }

        for(int i = (wordCount - 1); i >= 0; i--){
            for(auto it: words[i]){
                out.push_back(it);
                cout<<it;
            }
            
            if(i != 0){
                out.push_back(' ');
                cout<<' ';
            }
        }

        return out;
    }
};