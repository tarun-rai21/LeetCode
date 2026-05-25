class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        //count frequencies
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        //max heap: {frequency, element}
        priority_queue<pair<int, int>> pq;

        for(auto x : freq){
            pq.push({x.second, x.first});
        }

        //store answer
        vector<int> ans;

        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    return ans;
    }
};