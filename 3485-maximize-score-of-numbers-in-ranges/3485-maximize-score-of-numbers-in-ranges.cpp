class Solution {
public:
    bool check(vector<int>& start,int x,int d) {
        int n=start.size();
        bool satisfied=true;
        long long last=start[0];
        for(int i=1;i<n;i++) {
            if(1ll*last+1ll*x>1ll*start[i]+1ll*d) return satisfied=false;
            last=max(1ll*start[i],1ll*last+1ll*x);
        }
        return satisfied;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(),start.end());
        int low=0,high=start[start.size()-1]+d;
        int ans=0;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(check(start,mid,d)) {low=mid+1;ans=max(ans,mid);}
            else high=mid-1;
        }
        return ans;
    }
};