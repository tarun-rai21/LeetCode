class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n = nums1.size();

        bool mix = 0;
        for(int i=1; i<n; i++){
            if((nums1[i-1]%2)!=(nums1[i]%2)){
                mix = 1;
                break;
            }
        }

        if(mix){
            sort(nums1.begin(), nums1.end());
            if(nums1[0]%2 != 0) return 1;
            else return 0;
        }

        return 1;
    }
};