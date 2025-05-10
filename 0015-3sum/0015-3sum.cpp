class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++) {
            if(i!=0 and nums[i]==nums[i-1]) continue;
            int sum=-nums[i],l=i+1,r=n-1;
            while(l<r) {
                if(nums[l]+nums[r]==sum) {
                    ans.push_back({nums[l],nums[r],nums[i]});
                    l++;
                    r--;
                    while(l<r and nums[l]==nums[l-1]) l++;
                    while(l<r and nums[r]==nums[r+1]) r--;
                }
                else if(nums[l]+nums[r]>sum) r--;
                else l++;
            }
        }
        return ans;
    }
};