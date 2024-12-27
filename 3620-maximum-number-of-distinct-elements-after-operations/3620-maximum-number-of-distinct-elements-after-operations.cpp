class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums[0]-=k;
        int ans=1,n=nums.size();
        for(int i=1;i<n;i++) {
            if(nums[i-1]<nums[i]-k) {
                ans++;
                nums[i]-=k;
            }
            else if(nums[i-1]>=nums[i]-k and nums[i-1]<nums[i]+k) {
                ans++;
                nums[i]=nums[i-1]+1;
            }
            else nums[i]=nums[i-1];
        }
        return ans;
    }
};