class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int curr_profit = 0;
        int min_so_far = prices[0];

        for(int i=1; i<n; i++){
            curr_profit = prices[i] - min_so_far;
            max_profit = max(max_profit, curr_profit);
            min_so_far = min(min_so_far, prices[i]);
        }

        return max_profit;
    }
};