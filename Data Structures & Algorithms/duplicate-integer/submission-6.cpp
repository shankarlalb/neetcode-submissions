class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>st;
        for(auto it : nums){
            if(st.size()!=0 && (*(--st.upper_bound(it)))==it){
                return true;
            }
            st.insert(it);
        }
        return false;
    }
};