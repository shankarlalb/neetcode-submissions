class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int rem = target-nums[i];
            if(mp.count(rem)!=0){
                int ii = mp[rem];
                return {ii, i};
            }
            if(mp.count(nums[i])==0)
                mp[nums[i]] = i;
        }
        return {0};
    }
};
