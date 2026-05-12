#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        long long total = 0;
        
        for (int num : nums) {
            int best = num;  // default: keep itself
            
            // Check all divisors of num in O(√num)
            for (int d = 1; (long long)d * d <= num; d++) {
                if (num % d == 0) {
                    // d is a divisor
                    if (num_set.count(d)) {
                        best = min(best, d);
                    }
                    // num/d is also a divisor
                    if (num_set.count(num / d)) {
                        best = min(best, num / d);
                    }
                }
            }
            
            total += best;
        }
        
        return total;
    }
};