class Solution {
public:
    int findFirst(vector<int>& nums, int target){
            
            int low = 0; int high = nums.size()-1;
            int ans_low = -1;

            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target){
                    ans_low = mid;
                    high = mid-1; //keep searching left
                }

                if(nums[mid]>target){
                    high = mid-1;
                }

                if(nums[mid]<target){
                    low = mid+1;
                }
            }
            return ans_low;
        }

        int findLast(vector<int>& nums, int target){
            
            int low = 0; int high = nums.size()-1;
            int ans_high = -1;

            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]==target){
                    ans_high = mid;
                    low = mid+1; //keep searching right
                }

                if(nums[mid]>target){
                    high = mid-1;
                }

                if(nums[mid]<target){
                    low = mid+1;
                }
            }
            return ans_high;
        }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int low_index = findFirst(nums, target);
        int high_index = findLast(nums, target);

        return {low_index, high_index};
    }
};