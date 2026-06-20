class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights.back().size();
        auto isValid = [&](int r, int c)->bool{
            return r>=0&&c>=0&&r<n&&c<m;
        };
        vector<vector<int>>count(n, vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++){
            q.push({i,0});
            count[i][0] = 1;
        }
        for(int j = 1;j<m;j++){
            q.push({0,j});
            count[0][j] = 1;
        }
        auto doBfs = [&](int comp) -> void{
            vector<int>dx = {1,-1,0,0};
            vector<int>dy = {0,0,-1,1};
            while(!q.empty()){
                auto pr = q.front();
                q.pop();
                int r = pr.first;
                int c = pr.second;
                for(int i = 0;i<4;i++){
                    int rr = r + dx[i];
                    int cc = c + dy[i];
                    if(isValid(rr,cc) && heights[rr][cc] >= heights[r][c] && count[rr][cc] == comp){
                        q.push({rr,cc});
                        count[rr][cc] = comp+1;
                    }
                }
            }
        };
        doBfs(0);
        auto printMap = [&](map<pair<int,int>, int>&mp)->void{
            for(auto it : mp){
                cout<<it.first.first<<" "<<it.first.second<<" : "<<it.second<<endl;
            }
        };


        /*
        
        2 1
        1 2
        
        
        */
        while(q.size())q.pop();
        map<pair<int,int>,int>mp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(count[i][j]){
                    mp[{i,j}]+=1;
                }
                count[i][j] = 0;
            }
        }
        printMap(mp);
        for(int i = 0;i<n;i++){
            q.push({i, m-1});
            count[i][m-1]=1;
        }
        for(int j = 0;j<m-1;j++){
            q.push({n-1,j});
            count[n-1][j] = 1;
        }
        doBfs(0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(count[i][j]){
                    mp[{i,j}]+=1;
                }
            }
        }
        cout<<"again"<<endl;
        printMap(mp);
        vector<vector<int>>ans;
        for(auto it : mp){
            if(it.second == 2){
                ans.push_back({it.first.first, it.first.second});
            }
        }
        return ans;
    }
};
