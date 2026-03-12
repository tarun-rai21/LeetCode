class Solution {
public:

    int leftSum(int i, vector<int>& nums){
        if(i>0){
            int sum = 0;
            for(int j=0; j<i; j++){
                sum += nums[j];
            }
            return sum;
        }
        else return 0;
    }

    int rightSum(int i, vector<int>& nums){
        if(i< nums.size()-1){
            int sum = 0;
            for(int j=nums.size()-1; j>i; j--){
                sum += nums[j];
            }
            return sum;
        }
        else return 0;
    }

    int pivotIndex(vector<int>& nums) {
        
        for(int i=0; i<nums.size(); i++){
            int left = leftSum(i, nums);
            int right = rightSum(i, nums);
            
            if(left==right){
                return i;
            }
        }
        return -1;
    }
};