class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;

        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=i+1; j<n; j++){
                if(nums[i]%2==0 && nums[j]%2!=0){
                    count++;
                }
                else if(nums[i]%2!=0 && nums[j]%2==0){
                    count++;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};