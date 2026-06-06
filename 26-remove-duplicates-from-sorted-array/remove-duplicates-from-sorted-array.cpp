class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int unique = 0; //pointer to unique elements

        for(int curr = 1; curr < nums.size(); curr++) {
            if(nums[curr] != nums[unique]) {
                unique++;
                nums[unique] = nums[curr];
            }
        }
        return unique + 1;
    }
};