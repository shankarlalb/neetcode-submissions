class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it : nums)st.insert(it);
        int ans = 0;
        for(auto it : st){
            if(st.count(it-1)){
                continue;
            }
            int temp = 0;
            while(st.count(it++)){
                temp += 1;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};
