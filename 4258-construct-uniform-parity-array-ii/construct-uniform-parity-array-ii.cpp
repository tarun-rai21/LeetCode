class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());
        if (nums1[0]%2 != 0) return true;
        
        else{
            int n = nums1.size();
            for(int i=0; i<n-1; i++){
                if((nums1[i]%2)!=(nums1[i+1]%2)){
                    return false;
                }
            }
        }
        return true;
    }
};