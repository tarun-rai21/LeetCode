class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;

        unordered_set<char> my_set;
        my_set.insert(s[0]);
        
        int low = 0, high = 0;
        int curr_length = 1, max_length = 1;

        int n = s.size();

        while(high<n-1){
            if(my_set.contains(s[high+1])){
                my_set.erase(s[low]);
                low++;
                curr_length = high - low + 1;
            }
            else{
                high++;
                curr_length = high - low + 1;
                my_set.insert(s[high]);
            }
            max_length = max(max_length, curr_length);
        }
        return max_length;
    }
};