class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int j=0;j<n;j++) {
            for(int i=1;i<m;i++) {
                if(grid[i][j]<=grid[i-1][j])  {
                    int val=grid[i-1][j]+1;
                    ans+=val-grid[i][j];
                    grid[i][j]=val;
                }
            }
        }
        return ans;
    }
};