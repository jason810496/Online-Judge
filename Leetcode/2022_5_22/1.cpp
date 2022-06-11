class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<int,int> M;
        for(auto i : s){
            M[ i ]++;
        }

        int n = s.size();

        return 100*(M[ letter ])/n;
    }
};