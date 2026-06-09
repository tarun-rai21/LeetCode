class Solution {
public:
    string reverseStr(string s, int k) {
        
        int n = s.size();

        int first = 0; // pointer to the first element
        int second = k; // pointer to the kth element

        while(first < n){
            reverse(
                s.begin() + first,
                s.begin() + min(second, n)
            );

            first += 2*k;
            second += 2*k;
        }

        return s;
    }
};