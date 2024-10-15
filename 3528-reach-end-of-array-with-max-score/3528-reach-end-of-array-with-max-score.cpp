class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int last=nums[0];
        for(int i=1;i<n;i++) {
            ans+=1ll*last;
            if(last<nums[i]) last=nums[i];
        }
        return ans;
    }
};