class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        int i=0,j=0;
        string ans;
        while(i!=m and j!=n) {
            if((i+j)%2) ans+=word2[j++];
            else ans+=word1[i++];
        }
        while(i!=m) ans+=word1[i++];
        while(j!=n) ans+=word2[j++];
        return ans;
    }
};