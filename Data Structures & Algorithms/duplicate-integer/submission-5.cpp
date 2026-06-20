class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto it : nums){
            if(((st.lower_bound(it))!=st.end()) && (*st.lower_bound(it))==it){
                return true;
            }
            st.insert(it);
        }
        return false;
    }
};