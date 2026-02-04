//solved by Tarun

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> negative_nums;
        vector<int> positive_nums;

        for(int i=0; i<n; i++){
            if(nums[i]<0){
                negative_nums.push_back(nums[i]);
            }
            else{
                positive_nums.push_back(nums[i]);
            }
        }
        for(int i=0; i<n; i++){
            if(i%2==0){
                nums[i] = positive_nums[i/2];
            }
            else{
                nums[i] = negative_nums[i/2];
            }
        }
    return nums;
    }
};