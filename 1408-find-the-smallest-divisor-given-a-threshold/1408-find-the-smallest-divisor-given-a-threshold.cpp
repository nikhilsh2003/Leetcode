class Solution {
public:
    bool check(int x,vector<int>& nums,int threshold) {
        int ct=0;
        for(auto &y:nums) {
            ct+=(y+x-1)/x;
            if(ct>threshold) return 0;
        }
        return ct<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=1,mid,ans;
        for(auto &x:nums) high=max(high,x);
        ans=high+1;
        high++;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,nums,threshold)) {
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};