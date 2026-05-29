class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int n = nums.size();
        int counter = 1;
        vector<int> result;

        result.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i-1]==nums[i]){
                counter++;
                if(counter<=k) result.push_back(nums[i]);
            }
            else{
                counter = 0;
                result.push_back(nums[i]);
                counter++;
            }
        }
        return result;
    }
};