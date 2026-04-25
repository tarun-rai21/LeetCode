class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        if(k==0 && n>0) return true;
        if(n==1 && nums[0]==0 && k<=1) return true;
        if(n==2){
            if(nums[0]==0 && nums[1]==0 && k==1) return true;
            else return false;
        }

        if(nums[0]==0 && nums[1]==0) count++;
        if(nums[n-1]==0 && nums[n-2]==0) count++;

        for(int i=1; i<n-3;){
            if(nums[i]==0 && nums[i+1]==0 && nums[i+2]==0){
                count++;
                i+=2;
            }
            else i++;
        }


        if(k <= count) return true;
        return false;
    }
};