class Solution {
public:
    int countSubstrings(string s) {
        int ct=0;
        int n=s.length();
        for(int i=0;i<n;i++) {
            int l=i,r=i;
            while(l>=0 and r<n) {
                if(s[l]==s[r]) {
                    ct++;
                    l--;
                    r++;
                }
                else break;
            }
        }
        for(int i=1;i<n;i++) {
            int l=i-1,r=i;
            while(l>=0 and r<n) {
                if(s[l]==s[r]) {
                    ct++;
                    l--;
                    r++;
                }
                else break;
            }
        }
        return ct;
    }
};