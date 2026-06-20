class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        sort(nums.begin(), nums.end());
        for(auto it : nums){
            int val = it - 1;
            int count = 1;
            if(mp.count(val)){
                count += mp[val];
                mp.erase(val);
            }
            mp[it] = max(mp[it], count);
        }
        int ans = 0;
        for(auto it : mp){
            ans = max(ans, it.second);
        }
        return ans;
    }
};
