class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n = s.size();
        for(int i=0; i<n-1; i++){
            int first = int(s[i]);
            int second = int(s[i+1]);

            if(abs(second - first) > 2) return false;
        }
    return true;
    }
};