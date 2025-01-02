class Solution {
public:
    int check(string &s) {
        int n=s.length();
        return (s[0]=='a' or s[0]=='e' or s[0]=='i' or s[0]=='o' or s[0]=='u') and
        (s[n-1]=='a' or s[n-1]=='e' or s[n-1]=='i' or s[n-1]=='o' or s[n-1]=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> chk(n,0);
        for(int i=0;i<n;i++) {
            if(i==0)
                chk[i]=check(words[0]);
            else
                chk[i]=chk[i-1]+check(words[i]);
        }
        int len=queries.size();
        vector<int> ans(len);
        for(int i=0;i<len;i++) {
            int l=queries[i][0],r=queries[i][1];
            if(l==0) 
                ans[i]=chk[r];
            else 
                ans[i]=chk[r]-chk[l-1];
        }
        return ans;
    }
};