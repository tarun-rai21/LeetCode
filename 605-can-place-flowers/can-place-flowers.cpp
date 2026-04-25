class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for(int i=0; i<n; i++){
            if(nums[i]==0){
                bool left = (i==0 || nums[i-1]==0);
                bool right = (i==n-1 || nums[i+1]==0);

                if(left && right){
                    k--;
                    nums[i]=1;
                    if(k==0) return true;
                }
            }    
        }
        return k<=0;
    }
};