class Solution {
public:
    bool check(string &sub,string &s) {
        int m=sub.length(),n=s.length();
        if(m>n) return 0;
        for(int i=0;i<=n-m;i++) {
            if(sub==s.substr(i,m)) 
                return 1;
        }
        return 0;
    }
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) continue;
                if(check(words[i],words[j])) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};