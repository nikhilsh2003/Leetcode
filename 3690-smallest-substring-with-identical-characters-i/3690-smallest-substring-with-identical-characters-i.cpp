class Solution {
public:
    bool validate(string &s,int numOps) {
        int ct1=0,ct2=0,n=s.size();
        for(int i=0;i<n;i++) {
            if(i%2) {
                if(s[i]=='1') ct1++;
                else ct2++;
            }
            else {
                if(s[i]=='1') ct2++;
                else ct1++;
            }
        }
        return ct1<=numOps or ct2<=numOps;
    }
    bool check(int mid,string &s,int numOps) {
        if(mid==1) 
            return validate(s,numOps);
        int n=s.size(),ct=0;
        for(int i=1;i<n;i++) {
            int curr=1;
            while(i<n and s[i-1]==s[i]) {
                curr++;
                i++;
            }
            ct+=curr/(mid+1);
            if(ct>numOps) return 0;
        }
        return ct<=numOps;
    }
    int minLength(string s, int numOps) {
        int low=1,high=s.size(),mid,ans;
        ans=high;
        while(low<=high) {
            mid=low+(high-low)/2;
            if(check(mid,s,numOps)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};