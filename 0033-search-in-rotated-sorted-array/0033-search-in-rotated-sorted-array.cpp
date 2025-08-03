class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1) return (nums[0]==target)?0:-1;
        int low=0,high=n-1,mid;
        while(low<high) {
            if(low==(high-1)) {
                if(target==nums[low]) return low;
                else if(target==nums[high]) return high;
                else return -1;
            }
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>nums[high]) {
                if(nums[mid]>=target and nums[low]<=target) high=mid;
                else low=mid;
            } else {
                if(target>=nums[mid] and target<=nums[high]) low=mid;
                else high=mid;
            }
        }
        return -1;
    }
};