class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size();

        if(n>1){
            int left = 0;
            int right = 1;

            while(left<n && right<n){
                if(nums[left]==0 && nums[right]==0) right++;
            
            else if(nums[left]==0 && nums[right]!=0){
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
            else{
                left++;
                right++;
            }
            }
        }
    }
};