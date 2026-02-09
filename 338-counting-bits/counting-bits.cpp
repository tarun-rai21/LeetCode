//solved by Tarun

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = {0};

        for(int j=1; j<=n; j++){
            int count = 0;
            int i = j;
            while(i>0){
                int lastBit = (i & 1);
                if(lastBit == 1){
                    count++;
                }
                i>>=1;
            }
            ans.push_back(count);
        }

        return ans;
    }
};