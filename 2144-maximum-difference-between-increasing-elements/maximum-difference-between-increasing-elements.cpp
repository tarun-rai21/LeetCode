class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int lowest = INT_MAX;
        int max_difference = -1;

        for(int i=0; i<nums.size(); i++){
            
            if(nums[i]<lowest){
                lowest = nums[i];
            }
            int difference = nums[i]-lowest;
            
            max_difference = max(max_difference, difference);
        }
        if(max_difference == 0) return -1;
        else return max_difference;
    }
};