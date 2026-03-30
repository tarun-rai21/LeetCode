class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int min_diff = INT_MAX; 
        int abs_diff = INT_MAX;
        int index1 = 0;
        int index2 = 0;

        for(int i=0; i<n-1; i++){
            if(nums[i] != 0){
                index1 = i;
                for(int j = i+1; j<n; j++){
                    if(nums[j]!=nums[index1] && nums[j]!=0){
                        index2 = j;
                        abs_diff = abs(index2 - index1);
                        min_diff = min(min_diff, abs_diff);
                    }
                }
            }
        }
        if(min_diff>n-1) return -1;
        else return min_diff;
        
    }
};