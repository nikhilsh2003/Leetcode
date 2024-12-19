class Solution {
public:
    bool check(int capacity,vector<int>& weights,int days) {
        int actDays=0;
        int n=weights.size();
        for(int i=0;i<n;) {
            int curr=0;
            while(i<n and curr<=capacity) {
                curr+=weights[i];
                i++;
            }
            if(curr>capacity) i--;
            actDays++;
            if(actDays>days) return false;
        }
        return actDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1,high=0,mid,ans;
        for(auto &x:weights) high+=x;
        ans=high;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,weights,days)) {
                ans=min(ans,mid);
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};