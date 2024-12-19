class Solution {
public: 
    bool check(int speed, vector<int>& piles,int h) {
        int time=0;
        for(auto &x:piles) {
            time+=(x+speed-1)/speed;
            if(time>h) return false;
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=INT_MAX,mid;
        int ans=high;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,piles,h)) {
                ans=min(ans,mid);
                high=mid-1;
            }
            else 
                low=mid+1;
        }
        return ans;
    }
};