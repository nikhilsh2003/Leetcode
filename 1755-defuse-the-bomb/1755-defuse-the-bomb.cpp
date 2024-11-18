class Solution {
public:
    void solve(vector<int>& code,int k,vector<int>& ans) {
        int temp=0;
        int n=code.size();
        for(int i=1;i<=k;i++) temp+=code[i];
        for(int i=0;i<n;i++) {
            ans[i]=temp;
            temp=temp-code[(i+1)%n]+code[(i+k+1)%n];
        }
    }
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n,0);
        if(k<0) {
            k=abs(k);
            reverse(code.begin(),code.end());
            solve(code,k,ans);
            reverse(ans.begin(),ans.end());
        }
        else if(k>0) {
            solve(code,k,ans);
        }
        else return ans;
        return ans;
    }
};