class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();
        int mn = prices.front();
        for(int i = 0;i<n;i++){
            ans = max(ans, prices[i]-mn);
            mn = min(mn, prices[i]);
        }
        return ans;
    }
};
