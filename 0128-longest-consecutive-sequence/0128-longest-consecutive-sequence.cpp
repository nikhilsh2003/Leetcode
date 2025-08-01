class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        int ans=0;
        for(auto &x:nums) st.insert(x);
        for(auto x:nums) {
            if(st.count(x-1)) continue;
            int y=x+1;
            while(st.count(y)) {st.erase(y);y++;}
            ans=max(ans,y-x);
        }
        return ans;
    }
};