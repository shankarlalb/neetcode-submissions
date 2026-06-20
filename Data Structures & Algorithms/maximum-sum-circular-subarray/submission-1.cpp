class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            nums.push_back(nums[i]);
        }
        int nn = 2*n;
        multiset<int>st;
        // st.insert(0);
        vector<int> per(nn,0);
        int sm = 0;
        int ans = -1e9;
        for(int i = 0;i<nn;i++){
            sm += nums[i];
            int mn = *st.begin();
            ans = max(ans, sm - mn);
            st.insert(sm);
            per[i] = sm;
            if(st.size()>n){
                st.erase(st.find(per[i-n]));
            }
        }
        return ans;
    }
};