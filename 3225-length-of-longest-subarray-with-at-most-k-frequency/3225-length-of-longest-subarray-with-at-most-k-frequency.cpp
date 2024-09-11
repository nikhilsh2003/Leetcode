class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mp;
        int l=0,r=0;
        int ans=0;
        for(;l<n;l++) {
            while(r<n and (mp[nums[r]]+1)<=k) {
                mp[nums[r]]++;
                r++;
            }
            if(r<n and mp[nums[r]]+1<=k) 
                ans=max(ans,r-l+1);
            else
                ans=max(ans,r-l);
            mp[nums[l]]--;
        }
        return ans;
    }
};