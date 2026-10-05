class Solution {
public:
    int calcScore(int i, int j, string s){
        vector<int> nodes;
        nodes.push_back(i);

        int sum = 1;
        for(int k = i+1; k < j; k++){
            if(s[k] == ')'){
                sum--;
            }
            else if(s[k] == '('){
                sum++;
            }

            if(sum == 0 && k+1 < j){
                nodes.push_back(k+1);
            }
        }

        int score = 0;

        for(int k = 0; k < nodes.size()-1; k++){
            if(s[nodes[k]+1] == ')'){
                score++;
            }
            else{
                score = score + 2*calcScore(nodes[k]+1, nodes[k+1]-2, s);
            }
        }
        if(s[nodes[nodes.size()-1]+1] == ')'){
            score++;
        }
        else{
            score = score + 2*calcScore(nodes[nodes.size()-1]+1, j-1, s);
        }

        return score;
    }

    int scoreOfParentheses(string s) {
        return calcScore(0, s.size()-1, s);
    }
};