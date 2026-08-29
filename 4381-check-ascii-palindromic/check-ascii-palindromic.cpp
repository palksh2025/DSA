class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";

        for(char c : s){
            binary += bitset<8>(c).to_string();
        }

        string rev = binary;

        reverse(rev.begin(), rev.end());

        return binary == rev;
    }
};