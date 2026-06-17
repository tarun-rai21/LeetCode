class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        //previous smaller element
        int n = arr.size();
        stack<int> st;
        vector<int> result(n, -1);
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> nextSmallerEle(vector<int>& arr) {
        //next smaller or equal element
        int n = arr.size();
        vector<int> result(n, n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }


    int sumSubarrayMins(vector<int>& arr) {
        
        const int MOD = 1e9 + 7;
        long long total = 0;
        int n = arr.size();
        vector<int> pse = prevSmaller(arr);
        vector<int> nse = nextSmallerEle(arr);

        for(int i=0; i<n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contrib = ((left % MOD) * (right % MOD)) % MOD;

            contrib = (contrib * arr[i]) % MOD;

            total = (total + contrib) % MOD;
        }

        return int(total);
    }
};