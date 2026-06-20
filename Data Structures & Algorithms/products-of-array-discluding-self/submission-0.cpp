class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>per(n), suf(n);
        for(int i = 0;i<n-1;i++){
            int j = n-1-i;
            if(i==0){
                per[i] = nums[i];
                suf[j] = nums[j];
            }else{
                per[i] = per[i-1]*nums[i];
                suf[j] = suf[j+1]*nums[j];
            }
        }
        vector<int>ans;
        for(int i = 0;i<n;i++){
            if(i==0){
                ans.push_back(suf[i+1]);
            } else if(i==n-1){
                ans.push_back(per[i-1]);
            } else{
                ans.push_back(per[i-1]*suf[i+1]);
            }
        }
        return ans;
    }
};
