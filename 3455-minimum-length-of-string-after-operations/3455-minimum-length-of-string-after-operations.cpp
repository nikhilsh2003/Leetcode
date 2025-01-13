class Solution {
public:
    int minimumLength(string s) {
        vector<int> ct(26,0);
        for(auto &x:s) {
            ct[x-'a']++;
            if(ct[x-'a']==3) ct[x-'a']=1;
        }
        int ans=0;
        for(int i=0;i<26;i++) {
            ans+=ct[i];
        }
        return ans;
    }
};