class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>result;
        int even = 0;
        int odd = 0;
        for(int i=0; i<n; i++){
            if(nums[i]%2==0) even++;
            else odd++;
        }

        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                result.push_back(odd);
                even--;
            }
            else{
                result.push_back(even);
                odd--;
            }
        }
        return result;
    }
};