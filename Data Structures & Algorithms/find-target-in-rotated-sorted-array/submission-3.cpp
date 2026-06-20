class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto getInd  = [&](vector<int>nums)->int{
            int n = nums.size();
            int ii = 0, jj =n-1;
            int ans = 0;
            int frnt = nums.front();
            int bck = nums.back();
            if(n==1)return 0;
            if(frnt<bck)return 0;
            while(ii<=jj){
                int mid = (ii+jj)/2;
                int val = nums[mid];
                if(val>=frnt){
                    ii = mid+1;
                }else{
                    ans = mid;
                    jj = mid-1;
                }
            }
            return ans;
        };
        int ind = getInd(nums);
        int ii = -1, jj = -1;
        int n =nums.size();
        if(n==1){
            if(nums[0]==target)return 0;
            return -1;
        }
        if(target>=nums.front()){
            ii = 0;
            jj = ind-1;
        }else{
            ii = ind;
            jj = n-1;
        }
        if(nums.front()<nums.back()){
            ii =0;
            jj = n-1;
        }
        int ans = -1;
        while(ii<=jj){
            int mid = (ii+jj)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target)
                    ans = mid;
                jj =mid-1;
            }else ii =mid+1;
        }
        
        return ans;
    }
};
