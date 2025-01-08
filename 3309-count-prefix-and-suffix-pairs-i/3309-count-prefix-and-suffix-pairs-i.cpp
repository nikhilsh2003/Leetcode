class Solution {
public:
    bool isPrefixAndSuffix(string &a,string &b) {
        int m=a.size(),n=b.size();
        if(m>n) return 0;
        return a==b.substr(0,m) and a==b.substr(n-m,m);
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0,n=words.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(isPrefixAndSuffix(words[i],words[j]))
                    ans++;
            }
        }
        return ans;
    }
};