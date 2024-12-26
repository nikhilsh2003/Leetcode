class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(101,false);
        int i;
        for(i=n-1;i>=0;i--) {
            if(vis[nums[i]]) break;
            vis[nums[i]]=1;
        }
        return (i+3)/3;
    }
};