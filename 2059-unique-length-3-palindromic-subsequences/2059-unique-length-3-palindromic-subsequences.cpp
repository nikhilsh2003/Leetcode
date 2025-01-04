class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.length();
        int ans=0;
        for(char x='a';x<='z';x++) {
            set<char> ct;
            int l=n,r=-1;
            for(int i=0;i<n;i++) {
                if(s[i]==x) {
                    l=i;
                    break;
                }
            }
            for(int i=n-1;i>=0;i--) {
                if(s[i]==x) {
                    r=i;
                    break;
                }
            }
            for(int j=l+1;j<r;j++) 
                ct.insert(s[j]);
            ans+=ct.size();
        }
        return ans;
    }
};