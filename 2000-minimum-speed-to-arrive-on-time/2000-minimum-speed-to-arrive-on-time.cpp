class Solution {
public:
    bool check(int x,vector<int>& dist,double hour) {
        double time=0.0;
        int n=dist.size();
        for(int i=0;i<n;i++) {
            if(i==n-1)
            time+=(double)(dist[i]/(x*1.0));
            else
            time+=(dist[i]+x-1)/x;
            if(time>hour) return false;
        }
        return time<=hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size();
        int low=1,high=1e7+1,mid;
        int ans=1e7+1;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,dist,hour)) {
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans==1e7+1?-1:ans;
    }
};