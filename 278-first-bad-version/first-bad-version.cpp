// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;

        int first_bad;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(isBadVersion(mid)){
                first_bad = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return first_bad;
    }
};