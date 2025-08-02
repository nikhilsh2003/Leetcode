class Solution {
public:
    bool solution(int i,string &s,set<string>& dict,vector<int>& dp) {
        if(dp[i]!=-1) return dp[i];
        int n=s.length();
        string temp;
        bool ans=0;
        for(int j=i;j<n;j++) {
            temp+=s[j];
            if(dict.count(temp)==1) ans=ans or solution(j+1,s,dict,dp);
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        int n=s.length();
        for(auto &x:wordDict) {
            st.insert(x);
        }
        vector<int> dp(n+1,-1);
        dp[n]=1;
        return solution(0,s,st,dp);
    }
};