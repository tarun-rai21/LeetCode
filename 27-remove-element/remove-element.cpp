class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int curr = 0; //pointer to the current result index

        for(int i=0; i<n; i++){
            if(nums[i]!=val){
                nums[curr] = nums[i];
                curr++;
            }
        }

        return curr;        
    }
};