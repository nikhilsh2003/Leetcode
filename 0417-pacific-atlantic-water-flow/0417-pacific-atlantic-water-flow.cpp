class Solution {
public:
    bool isValid(int i,int j,int m,int n) {
        if(i>=0 and j>=0 and i<m and j<n) return 1;
        return 0;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<bool>> pacific(m,vector<bool>(n,0));
        vector<vector<bool>> atlantic=pacific;
        queue<pair<int, int>> qPacific,qAtlantic;
        for(int i=0;i<m;i++) {
            pacific[i][0]=1;
            atlantic[i][n-1]=1;
            qPacific.push({i,0});
            qAtlantic.push({i,n-1});
        }
        for(int j=0;j<n;j++) {
            if(!pacific[0][j]) {
                pacific[0][j]=1;
                qPacific.push({0,j});
            }
            if(!atlantic[m-1][j]) {
                atlantic[m-1][j]=1;
                qAtlantic.push({m-1,j});
            }
        }
        vector<int> dir={0,1,0,-1,0};
        while(!qPacific.empty()) {
            int x=qPacific.front().first,y=qPacific.front().second;
            qPacific.pop();
            for(int i=1;i<=4;i++) {
                int p=x+dir[i-1],q=y+dir[i];
                if(isValid(p,q,m,n) and !pacific[p][q] and heights[p][q]>=heights[x][y]) {
                    pacific[p][q]=1;
                    qPacific.push({p,q});
                }
            }
        }
        while(!qAtlantic.empty()) {
            int x=qAtlantic.front().first,y=qAtlantic.front().second;
            qAtlantic.pop();
            for(int i=1;i<=4;i++) {
                int p=x+dir[i-1],q=y+dir[i];
                if(isValid(p,q,m,n) and !atlantic[p][q] and heights[p][q]>=heights[x][y]) {
                    atlantic[p][q]=1;
                    qAtlantic.push({p,q});
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(pacific[i][j] and atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};