class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int totalZeroes = 0;

        for(int x : nums){
            if(x == 0) totalZeroes++;
        }

        int zeroLeft = 0;
        for(int i=0; i<totalZeroes; i++){
            if (nums[i] != 0) zeroLeft++;
        }

        int zeroRight = 0;
        for(int i=0; i<totalZeroes; i++){
            if (nums[(nums.size()-1)-i] != 0) zeroRight++;
        }

        return min(zeroRight, zeroRight);
    }
};