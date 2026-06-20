class Solution {
public:
    int maxArea(vector<int>& heights) {
        auto fun = [&](vector<int>v)->int{
            int n = v.size();
            vector<int>perMax;
            int last = v.front();
            int ans = -1;
            for(int i = 0;i<n;i++){
                int curr = v[i];
                if(i==0){
                    perMax.push_back(max(curr, last));
                    last = max(last, curr);
                    continue;
                }else{
                    int ii = 0, jj = perMax.size()-1;
                    int ind = -1;
                    while(ii<=jj){
                        int mid = (ii+jj)/2;
                        if(perMax[mid]>=curr){
                            ind = mid;
                            jj = mid-1;
                        }else{
                            ii = mid+1;
                        }
                    }
                    cout<<i<<" "<<v[i]<<" "<<ind<<endl;
                    if(ind==-1){
                        perMax.push_back(max(curr, last));
                        last = max(last, curr);
                        continue;
                    }else{
                        ans = max(ans, curr * (i-ind));
                    }
                }
                perMax.push_back(max(curr, last));
                last = max(last, curr);
            }
            return ans;
        };
        auto temp = heights;
        reverse(temp.begin(), temp.end());
        return max(fun(heights), fun(temp));
    }
};
