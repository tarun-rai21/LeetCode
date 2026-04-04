class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        unordered_map<int, int>freq;
        int n = grid.size();
        vector<int> result(2);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }

        
        for(int i = 1; i <= n*n; i++){
            if(freq[i]==2) result[0]=i;
            if(freq[i]==0) result[1]=i;
        }
        return result;
    }
};