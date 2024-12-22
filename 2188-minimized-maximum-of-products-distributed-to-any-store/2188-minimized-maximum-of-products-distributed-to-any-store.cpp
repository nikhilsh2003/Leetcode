class Solution {
public:
    bool check(int x,int n,vector<int> &quantities) {
        int ct=0;
        for(auto &y:quantities) {
            ct+=(y+x-1)/x;
            if(ct>n) return 0;
        }
        return ct<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1,high=INT_MAX,ans,mid;
        // for(auto &x:quantities) high+=x;
        ans=high;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,n,quantities))  {
                ans=min(ans,mid);
                high=mid-1;
            }
            else 
            low=mid+1;
        }
        return ans;
    }
};