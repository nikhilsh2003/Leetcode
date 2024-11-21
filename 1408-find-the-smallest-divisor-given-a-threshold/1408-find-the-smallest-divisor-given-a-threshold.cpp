class Solution {
public:
    bool check(int x,vector<int>& nums,int threshold) {
        int sum=0;
        for(auto &y:nums) {
            sum+=y/x;
            if(y%x!=0) sum++;
            if(sum>threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=-1,mid;
        int ans;
        for(auto &x:nums) {
            high=max(high,x);
        }
        high++;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,nums,threshold)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};