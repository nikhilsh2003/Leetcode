class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> maxRight(n);
        maxRight[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--) {
            maxRight[i]=max(maxRight[i+1],height[i]);
        }
        int leftMax=0;
        int ans=0;
        for(int i=0;i<n-1;i++) {
            ans+=max(0,min(leftMax,maxRight[i+1])-height[i]);
            leftMax=max(leftMax,height[i]);
        }
        return ans;
    }
};