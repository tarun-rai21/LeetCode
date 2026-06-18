class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for(int i=0; i<n; i++){

            bool alive = true; //denotes the sondition of current asteroid

            while(!st.empty() && asteroids[i]<0 && st.top()>0 && alive){
                if(abs(asteroids[i]) > st.top()){
                    st.pop();
                }
                else if(abs(asteroids[i]) == st.top()){
                    st.pop();
                    alive = false;
                }
                else alive = false;
            }    
            if(alive) st.push(asteroids[i]);
        }    
        
        vector<int> result(st.size());
        for(int k = st.size()-1; k>=0; k--){
            result[k] = st.top();
            st.pop();
        }
        return result;        
    }        
};