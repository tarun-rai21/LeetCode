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
        //next smaller or equal element
        int n = arr.size();
        stack<int> st;
        vector<int> result(n, n);
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }

    long long sumSubarrayMin(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> pse = prevSmaller(arr);
        vector<int> nse = nextSmaller(arr);
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left  = i - pse[i];
            long long right = nse[i] - i;
            total = (total + arr[i] * left * right);
        }
        
        return total;
    }

    vector<int> nextLargerElement(vector<int>& arr) {
        //greater or equal element
        int n = arr.size();
        vector<int> result(n, n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return result;
    }

    vector<int> preGreaterEle(vector<int>& arr) {
        // strictly greater element
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty()) result[i] = st.top();
            st.push(i);
        }
        return result; 
    }


    long long sumSubarrayMax(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> nge = nextLargerElement(arr);
        vector<int> pge = preGreaterEle(arr);
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left  = i - pge[i];
            long long right = nge[i] - i;
            total = (total + arr[i] * left * right);
        }
        
        return total;
    }


    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMin(nums);               
    }
};