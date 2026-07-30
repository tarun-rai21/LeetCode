class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int str = start[0] + start[1];
        int end = target[0] + target[1];

        if(str%2==0){
            if(end%2!=0) return false;
        }
        else{
            if(end%2==0) return false;
        }
        return true;
    }
};