class Solution {
public:
    string minWindow(string s, string t) {
        map<int,int>tmp;
        for(auto it : t)tmp[it]++;
        auto is_valid = [&](map<int,int>&mp)->bool{
            for(auto it : tmp){
                int key = it.first;
                int val = it.second;
                int tar = mp[key];
                if(tar<val)return false;
            }
            return true;
        };
        int n = s.size();
        pair<int,int> fine = {1e9, -1};
        for(int i = 0;i<n;i++){
            map<int,int>mp;
            for(int j = i;j<n;j++){
                mp[s[j]]++;
                if(is_valid(mp)){
                    int len = j - i +1;
                    if(fine.first>len){
                        fine.first = len;
                        fine.second = i;
                    }
                }
            }
        }
        string ans;
        if(fine.second == -1)return "";
        for(int i = fine.second;ans.size()<fine.first;i++){
            ans.push_back(s[i]);
        }
        return ans;
    }
};
