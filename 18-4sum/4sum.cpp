class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> result;
        
        for(int i=0; i<n-3; i++){

            if(i>0 && nums[i]==nums[i-1]) continue; //skip duplicates

            for(int j=i+1; j<n-2; j++){

                if(j>i+1 && nums[j]==nums[j-1]) continue; //skip duplicates

                int low = j + 1;
                int high = n - 1;

                while (low < high) {
                    long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[low], nums[high]});

                        low++;
                        high--;

                        // skip duplicates for low and high
                        while (low < high && nums[low] == nums[low - 1]) low++;
                        while (low < high && nums[high] == nums[high + 1]) high--;
                    }
                    else if (sum < target) {
                        low++;
                    }
                    else {
                        high--;
                    }
                }
            }
        }
        return result;
    }
};