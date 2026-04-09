class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        
        int left, mid, right;
        
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        left = v[0];
        mid = v[1];
        right = v[2];

        int max_step = right - left - 2;

        int min_step = 0;
        if(right-left == 2) min_step = 0;
        else if(mid - left <= 2 || right - mid <= 2) min_step = 1;
        else min_step = 2; 

        return {min_step, max_step};
    }
};