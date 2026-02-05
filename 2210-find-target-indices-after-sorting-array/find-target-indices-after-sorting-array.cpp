//solved by Tarun

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int index = 0;
        int n = nums.size();
        vector<int> result;

        for(int i=0; i<n; i++){
            if(nums[i]<target){
                index++;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]==target){
                result.push_back(index+count);
                count++;
            }
        }
        return result;
    }
};