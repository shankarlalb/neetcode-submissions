class Solution {
public:
    string get(int ct){
        return "_"+to_string(ct)+"_";
    }

    string encode(vector<string>& strs) {
        string ans;
        for(auto it : strs){
            auto per = get(it.size());
            ans += per + it;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int n = s.size();
        int i = 0;
        while(i<n){
            int ct = 0;
            string temp;
            while(ct<2){
                ct += s[i]=='_';
                if(s[i]!='_')
                temp.push_back(s[i]);
                i++;
            }
            int count = stoi(temp);
            string ani;
            while(ani.size()<count){
                ani.push_back(s[i]);
                i++;
            }
            ans.push_back(ani);
        }
        return ans;
    }
};
