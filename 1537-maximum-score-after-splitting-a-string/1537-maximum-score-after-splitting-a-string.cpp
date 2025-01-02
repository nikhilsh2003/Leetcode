class Solution {
public:
    int maxScore(string s) {
        int len=s.length();
        int ones=0;
        for(auto &x:s) {
            if(x=='1') ones++;
        }
        int ans=ones-1,zero=0;
        for(int i=0;i<len-1;i++) {
            if(s[i]=='0') zero++;
            else ones--;
            ans=max(ans,zero+ones);
        } 
        return ans;
    }
};