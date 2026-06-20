class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int ans = 0;
        int n =s.size();
        int i = 0, j = 0;
        for(i = 0;i<n;i++){
            int sz = mp.size();
            mp[s[i]]++;
            int nsz = mp.size();
            if(nsz==sz){
                while(s[j]!=s[i]){
                    mp[s[j]]--;
                    if(mp[s[j]]==0)mp.erase(s[j]);
                    j++;
                }
            }
            ans = max(ans, (int)mp.size());
        }
        return ans;
    }
};
