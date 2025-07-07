class Solution {
public:
    void dfs(int i,int idx,vector<vector<int>>& adj, vector<int> &vis,unordered_map<int, set<int>> &onlineComponents) {
        vis[i]=idx;
        onlineComponents[idx].insert(i);
        for(auto &x:adj[i]) {
            if(vis[x]!=-1) continue;
            dfs(x,idx,adj,vis,onlineComponents);
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> vis(c+1,-1);
        vector<vector<int>> adj(c+1);
        for(auto &x:connections) {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int idx=0;
        unordered_map<int, set<int>> onlineComponents;
        for(int i=1;i<=c;i++) {
            if(vis[i]!=-1) continue;
            dfs(i,idx,adj,vis,onlineComponents);
            idx++;
        }
        vector<int> ans;
        for(auto &x:queries) {
            int id=vis[x[1]];
            if(x[0]==1) {
                if(onlineComponents[id].find(x[1])!=onlineComponents[id].end())
                    ans.push_back(x[1]);
                else if(onlineComponents[id].size()!=0)
                    ans.push_back(*onlineComponents[id].begin());
                else
                    ans.push_back(-1);
            }
            else {
                onlineComponents[id].erase(x[1]);
            }
        }
        return ans;
    }
};