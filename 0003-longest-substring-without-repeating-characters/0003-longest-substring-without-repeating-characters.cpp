class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        map<char, int> mp;
        int l=0,r=0,ans=0;
        while(r<n) {
            while(l<r and mp.size()<r-l) {
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            ans=max(ans,r-l);
            mp[s[r++]]++;
        }
        if(mp.size()==r-l) ans=max(ans,r-l);
        return ans;
    }
};