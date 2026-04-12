class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_water = 0;
        int left = 0; 
        int right = n-1;

        while(left<right){
            int curr_water = min(height[left], height[right]) * (right-left);
            max_water = max(max_water, curr_water);

            if(height[left]<=height[right]) left++;
            else right--;
        }
        return max_water;
    }
};