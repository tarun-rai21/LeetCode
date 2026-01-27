//Solved by Tarun

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
       
       int elements = nums.size();
       
       if (elements==1) return nums[0];
       
       for(int i = 0; i < elements-1; i+=2){
        if( nums[i]!=nums[i+1] ){
            return nums[i];
        }
       } 
       return nums[elements-1];
    }
};