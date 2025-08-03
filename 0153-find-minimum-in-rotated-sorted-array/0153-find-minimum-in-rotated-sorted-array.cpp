class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid;
        while(low<high) {
            if(low==(high-1)) return min(nums[low],nums[high]);
            mid=low+(high-low)/2;
            cout<<nums[low]<<" "<<nums[mid]<<" "<<nums[high]<<endl;
            if(nums[mid]<nums[high]) high=mid;
            else low=mid;
        }
        return nums[mid];
    }
};