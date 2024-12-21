class Solution {
public:
    bool check(int x,vector<int>& bloomDay,int k,int m) {
        int num=0,n=bloomDay.size();
        for(int i=0;i<n;i++) {
            int curr=0;
            while(i<n and bloomDay[i]<=x) {
                curr++;
                if(curr==k) {
                    num++;
                    curr=0;
                }
                i++;
            }
        }
        return num>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        // sort(bloomDay.begin(),bloomDay.end());
        int n=bloomDay.size();
        int low=1,maxDay=bloomDay[n-1],high,mid;
        for(auto &x:bloomDay) maxDay=max(maxDay,x);
        if(n<m) return -1;
        int ans=maxDay+1;
        high=maxDay;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,bloomDay,k,m)) {
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return (ans==maxDay+1)?-1:ans;
    }
};