class Solution {
public:
    int parent(int i,vector<int> &par) {
        return par[i]=par[i]==i?i:parent(par[i],par);
    }
    void unionxy(int x,int y,vector<int>& par,vector<int>& siz) {
        int px=parent(x,par),py=parent(y,par);
        if(px==py) return;
        if(siz[px]<siz[py]) swap(px,py);
        par[py]=px;
        siz[px]+=py;
    }
    bool check(int x,int n,vector<vector<int>>& edges,int k) {
        vector<int> par(n,-1),siz(n,1);
        for(int i=0;i<n;i++) {
            par[i]=i;
        }
        for(auto &y:edges) {
            if(y[2]<=x) continue;
            unionxy(y[0],y[1],par,siz);
        }
        int count=0;
        for(int i=0;i<n;i++) {
            if(par[i]==i) count++;
        }
        return count>=k;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int low=0,high=-1,ans,mid;
        for(auto &x:edges) {
            high=max(high,x[2]);
        }
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,n,edges,k)) {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};