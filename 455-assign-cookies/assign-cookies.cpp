class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int size_greed = g.size();
        int size_cookie = s.size();
        int ans=0;
        
        int i=0, j=0;
        while(i<size_cookie && j<size_greed){
            if(g[j]<=s[i]){
                ans++;
                j++;
            }
            i++;            
        } 
        return ans;       
    }
};