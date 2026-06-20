class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        set<char>aage = {'(', '{', '['};
        map<char, char>mp;
        mp[')'] = '(';
        mp['}'] = '{';
        mp[']'] = '[';
        for(auto it : s){
            if(aage.count(it)){
                st.push(it);
            }else{
                if(st.size()==0)return false;
                auto tp = st.top();
                auto expected = mp[it];
                if(tp!=expected)return false;
                st.pop();
            }
        }
        return st.size() == 0;
    }
};
