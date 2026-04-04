class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        int total = 0;
        int max_freq = 0;

        for(auto it : freq){
            max_freq = max(max_freq, it.second);
        }
        for(auto it : freq){
            if(it.second >= max_freq){
                total += it.second; 
            }
        }
        return total;
    }
};