class Solution {
public:
    int mySqrt(int x) {
        int ans=1;
        if(x==0) return 0;
        if(x==1) return 1;
        
        int low = 1;
        int high = x/2;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(mid == x/mid){
                ans = mid;
                break;
            }
            else if(mid > x/mid){
                high = mid-1;
            }
            else{
                ans = mid;
                low = mid+1;
            }
        }
        return ans;
        
    }
};