class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.length();
        for(int i=0;i<n;i++) {
            int len=1;
            while(i+1<n and s[i]==s[i+1]) {
                len++;
                i++;
            }
            if(len==k) return 1;
        }
        return 0;
    }
};