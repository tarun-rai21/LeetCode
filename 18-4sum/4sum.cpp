class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;

        for(int i = 0; i < n - 3; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            long long min1 = (long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3];
            if(min1 > target) break;

            long long max1 = (long long)nums[i] + nums[n-1] + nums[n-2] + nums[n-3];
            if(max1 < target) continue;

            for(int j = i + 1; j < n - 2; j++) {

                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long min2 = (long long)nums[i] + nums[j] + nums[j+1] + nums[j+2];
                if(min2 > target) break;

                long long max2 = (long long)nums[i] + nums[j] + nums[n-1] + nums[n-2];
                if(max2 < target) continue;

                int low = j + 1;
                int high = n - 1;

                while(low < high) {
                    long long sum = (long long)nums[i] + nums[j] + nums[low] + nums[high];

                    if(sum == target) {
                        result.push_back({nums[i], nums[j], nums[low], nums[high]});

                        low++;
                        high--;

                        while(low < high && nums[low] == nums[low - 1]) low++;
                        while(low < high && nums[high] == nums[high + 1]) high--;
                    }
                    else if(sum < target) {
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