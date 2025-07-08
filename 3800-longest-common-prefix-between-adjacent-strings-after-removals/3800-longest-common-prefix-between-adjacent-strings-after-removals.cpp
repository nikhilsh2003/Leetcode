class Solution {
public:
    int calPrefixLen(string &s1,string &s2) {
        int m=s1.length(),n=s2.length();
        for(int i=0;i<min(m,n);i++) {
            if(s1[i]!=s2[i])
                return i;
        }
        return min(m,n);
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        if(n==1) return {0};
        if(n==2) return {0,0};
        vector<int> calLen;
        for(int i=0;i<n-1;i++) {
            int cal=calPrefixLen(words[i],words[i+1]);
            calLen.push_back(cal);
        }
        vector<int> ans(n);
        vector<int> maxCalRight(calLen.size());
        for(int i=calLen.size()-1;i>=0;i--) {
            if(i==calLen.size()-1) maxCalRight[i]=calLen[i];
            else maxCalRight[i]=max(maxCalRight[i+1],calLen[i]);
        }
        int leftMax=0;
        for(int i=0;i<n;i++) {
            int currLen=0;
            if(i-1>=0 and i+1<n) {
                currLen=calPrefixLen(words[i-1],words[i+1]);
            }
            if(i>=n-2) {
                ans[i]=max(leftMax,currLen);
            }
            else {
                ans[i]=max(leftMax,max(currLen,maxCalRight[i+1]));
            }
            if(i!=0) {
                leftMax=max(leftMax,calLen[i-1]);
            }
        }
        return ans;
    }
};