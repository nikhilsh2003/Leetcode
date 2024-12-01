class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        map<int, int> mp;
        int sum=0;
        for(auto &x:nums) {
            sum+=x;
            mp[2*x]++;
        }
        int ans=-10001;
        for(auto &x:nums) {
            mp[2*x]--;
            if(mp[sum-x]>0) ans=max(ans,x);
            mp[2*x]++;
        }
        return ans;
    }
};