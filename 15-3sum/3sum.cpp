class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i=0; i<n-2; i++){
            
            if(i>0 && nums[i]==nums[i-1]) continue;

            else{
                int low = i+1;
                int high = n-1;
                
                while(low<high){
                    if(nums[low] + nums[high] == -nums[i]){
                        
                        vector<int>res = {nums[i], nums[low], nums[high]};
                        result.push_back(res);
                        
                        low++;
                        high--;

                        while(low < high && nums[low]==nums[low-1]) low++;
                        while(low < high && nums[high]==nums[high+1]) high--;
                    }
                    else if(nums[low] + nums[high] > -nums[i]) high--;
                    else low++;
                }
            }
        }
        return result;
    }
};