class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int>mp1, mp2;
        for(auto it : s){
            mp1[it]++;
        }
        for(auto it : t){
            mp2[it]++;
        }
        for(char c = 'a';c<='z';c++){
            if(mp1[c]!=mp2[c]){
                return false;
            }
        }
        return true;
    }
};
