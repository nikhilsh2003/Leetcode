class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n=s.length();
        for(int i=0;i<n;i++) {
            if(ans.size()==0 or ans[ans.size()-1].length()==k) {
                ans.push_back("");
            }
            ans[ans.size()-1]+=s[i];
        }
        while(ans[ans.size()-1].length()<k) 
            ans[ans.size()-1]+=fill;
        return ans;
    }
};