class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        for(int i=0; i<n; i++){
            total += nums[i];
        }

        int left_sum = 0;
        for(int i=0; i<n; i++){
            if(left_sum == (total - left_sum - nums[i])){
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};