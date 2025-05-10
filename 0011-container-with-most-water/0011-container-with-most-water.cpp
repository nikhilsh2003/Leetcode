class Solution {
public:
    int maxArea(vector<int>& height) {
        int i,j,n=height.size();
        i=0;
        j=n-1;
        int ans=0;
        while(j>i) {
            ans=max(ans,min(height[i],height[j])*(j-i));
            if(height[i]>=height[j]) j--;
            else i++;
        }
        return ans;
    }
};