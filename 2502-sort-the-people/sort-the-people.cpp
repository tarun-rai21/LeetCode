//solved by Tarun

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        vector<string> results;
        vector<pair<int, string>> v;
        int n = names.size();

        for(int i=0; i<n; i++){
            v.push_back({heights[i], names[i]});
        }
        sort(v.begin(), v.end(), greater<>());
        
        for(auto &p : v){
                results.push_back(p.second);
        }

        return results;
    }
};