class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        vector<int> ans;
        if(!nums.size())
            return ans;

        for(auto x: nums){
            mp[x]++;
        }       

        vector<vector<int>> bucket(nums.size()+1);

        for(auto i : mp){
            bucket[i.second].push_back(i.first);
        }

        for(int i = bucket.size() - 1; i >= 0; --i){
            for(int j = 0; j < bucket[i].size(); ++j){
                ans.push_back(bucket[i][j]);
                if(ans.size() == k) return ans;
            }
        }

        return ans;
    }
};
