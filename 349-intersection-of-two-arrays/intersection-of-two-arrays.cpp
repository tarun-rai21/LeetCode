class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_set<int> mySet;
        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i=0; i<n1; i++){
            int low = 0;
            int high = n2-1;

            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums1[i] == nums2[mid]){
                    mySet.insert(nums1[i]);
                    break;
                }
                else if(nums1[i] < nums2[mid]) high = mid-1;
                else low = mid+1;
            }
        }
        return vector<int>(mySet.begin(), mySet.end());
    }
};