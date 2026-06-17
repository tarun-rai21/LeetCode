class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        //next smalller element
        int n = arr.size();
        stack<int> st;
        vector<int> result(n, -1);
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result;
    }

    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> result(n, n);
        
        for (int i = 0; i < n; i++) {
            //next smaller or equal element
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }

    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();
        
        vector<int> pse = prevSmaller(arr);
        vector<int> nse = nextSmaller(arr);
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left  = i - pse[i];
            long long right = nse[i] - i;
            total = (total + arr[i] * left % MOD * right) % MOD;
        }
        
        return (int)total;
    }
};