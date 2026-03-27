class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int odd = 0, even = 0;
        int mn = nums[0];

        for (int x : nums) {
            if (x % 2) odd++;
            else even++;
            mn = min(mn, x);
        }

        // already uniform
        if (odd == 0 || even == 0) return true;

        // check smallest element
        return (mn % 2 == 1);
    }
};