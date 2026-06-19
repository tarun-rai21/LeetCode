class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        for(int i=0; i<n; i++){
            int min_num = nums[i]; 
            int max_num = nums[i];
            for(int j=i; j<n; j++){
                min_num = min(min_num, nums[j]);
                max_num = max(max_num, nums[j]);

                total += max_num - min_num;
            }
        }
        return total;        
    }
};