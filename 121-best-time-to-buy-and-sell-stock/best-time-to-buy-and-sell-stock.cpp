//solved by Tarun

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest_price = INT_MAX;
        int max_profit = 0;
        int n = prices.size();

        for(int i=0; i<n; i++){
            if(prices[i]< lowest_price){
                lowest_price = prices[i];
            }
            int profit = prices[i]-lowest_price;
            if(profit > max_profit){
                max_profit = profit;

            }
        }

    return max_profit;
    }
};