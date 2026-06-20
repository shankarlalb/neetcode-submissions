class Solution {
public:
    bool isPalindrome(string t) {
        unordered_set<char>st;
        for(char c = '0';c<='9';c++){
            st.insert(c);
        }
        for(char c = 'a';c<='z';c++){
            st.insert(c);
        }
        for(char c = 'A';c<='Z';c++){
            st.insert(c);
        }
        string s;
        for(auto it : t){
            if(st.count(it)){
                s.push_back(it);
            }
        }
        int n = s.size();
        for(int i = 0;i<n/2;i++){
            int a = s[i]|' ';
            int b = s[n-1-i]|' ';
            if(a!=b)return false;
        }
        return true;
    }
};
