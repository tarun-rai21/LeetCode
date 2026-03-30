class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n=nums.size();
        int last1 = -1;
        int last2 = -1;
        int min_diff = INT_MAX;

        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                last1 = i;
                if(last2!=-1){
                    min_diff = min(min_diff, abs(last1 - last2));
                }
            }
            if(nums[i] == 2){
                last2 = i;
                if(last1!=-1){
                    min_diff = min(min_diff, abs(last1 - last2));
                }
            }
            
        }
        if(min_diff==INT_MAX) return -1;
        else return min_diff;
    }
};