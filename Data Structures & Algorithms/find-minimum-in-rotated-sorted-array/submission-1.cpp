class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int ii = 0, jj =n-1;
        int ans = 0;
        int frnt = nums.front();
        int bck = nums.back();
        if(n==1)return nums.front();
        if(frnt<bck)return frnt;
        while(ii<=jj){
            int mid = (ii+jj)/2;
            int val = nums[mid];
            if(val>=frnt){
                ii = mid+1;
            }else{
                ans = val;
                jj = mid-1;
            }
        }
        return ans;
    }
};
