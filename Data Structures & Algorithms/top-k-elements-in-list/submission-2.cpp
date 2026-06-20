class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto it : nums)mp[it]++;
        vector<pair<int,int>>v;
        for(auto it : mp){
            v.push_back({it.second, it.first});
        }
        sort(v.rbegin(), v.rend());
        vector<int>ans;
        for(int i = 0;i<min(k, n);i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
