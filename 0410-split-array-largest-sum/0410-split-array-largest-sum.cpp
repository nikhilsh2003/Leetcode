class Solution {
public:
    bool check(int x,vector<int>& nums,int k) {
        int ct=0,n=nums.size();
        for(int i=0;i<n;) {
            int curr=0;
            while(i<n and curr<=x) {
                curr+=nums[i];
                i++;
            }
            ct++;
            if(ct>k) return 0;
            if(curr>x) i--;
        }
        return ct<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0,ans,mid;
        for(auto &x:nums) high+=x;
        ans=high+1;
        cout<<check(6,nums,k)<<endl;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,nums,k)) {
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};