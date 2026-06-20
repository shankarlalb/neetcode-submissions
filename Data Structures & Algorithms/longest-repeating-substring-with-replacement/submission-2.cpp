class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        auto getAns = [&](string &s, char c)->int{
            vector<int>v(n,0);
            int ans = 1;
            for(int i = 0;i<n;i++){
                v[i] = (s[i]!=c);
            }
            vector<int>per;
            for(int i = 0;i<n;i++){
                if(i==0){
                    per.push_back(v[i]);
                    continue;
                }else{
                    int ii = 0, jj = per.size()-1;
                    int sm = per.back() + v[i];
                    int mnTar = sm - k;
                    int ind = -1;
                    if(sm<=k){
                        ans =max(ans, i+1);
                    }
                    while(ii<=jj){
                        int mid = (ii + jj)/2;
                        if(per[mid]>=mnTar){
                            ind = mid;
                            jj = mid-1;
                        }else ii = mid+1;
                    }
                    if(ind != -1){
                        ans = max(ans, i - ind);
                    }
                    per.push_back(sm);
                }
            }
            return ans;
        };
        int ans = -1;
        for(char c = 'A';c<='Z';c++){
            ans = max(ans, getAns(s, c));
        }
        return ans;
    }
};
