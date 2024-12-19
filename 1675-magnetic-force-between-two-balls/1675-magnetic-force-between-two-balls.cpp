class Solution {
public:
    bool check(int x,vector<int>& pos,int m) {
        int ct=1,n=pos.size();
        int initPos=pos[0];
        for(int i=1;i<n;i++) {
            if(pos[i]-initPos>=x) {
                ct++;
                initPos=pos[i];
                if(ct==m) return true;
            }
        }
        return ct>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int low=0,high=position[n-1]-1,mid;
        int ans=0;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,position,m)) {
                ans=max(ans,mid);
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};