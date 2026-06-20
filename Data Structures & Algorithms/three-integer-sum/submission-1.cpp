class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        set<vector<int>>ans;
        for(auto it : nums)mp[it]++;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                int a = nums[i];
                int b = nums[j];
                mp[a]--;
                mp[b]--;
                int rem = 0 - (a+b);
                if(mp[rem]>0){
                    vector<int>temp = {a, b, rem};
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                mp[a]++;
                mp[b]++;
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
