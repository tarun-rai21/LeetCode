//solved by Tarun

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> results;
        vector<pair<int, int>> v;
        int n = names.size();

        for(int i=0; i<n; i++){
            v.push_back({heights[i], i});
        }
        sort(v.begin(), v.end(), greater<>());
        
        for(auto p : v){
                results.push_back(names[p.second]);
        }

        return results;
    }
};