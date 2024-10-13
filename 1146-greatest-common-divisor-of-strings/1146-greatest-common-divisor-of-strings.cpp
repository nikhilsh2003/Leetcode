class Solution {
public:
    bool check(int i,string &str1,string &str2) {
        int m=str1.size(),n=str2.size();
        if(i+1>m or i+1>n or m%(i+1) or n%(i+1)) return 0;
        for(int j=0;j<=i;j++) {
            set<char> st;
            for(int x=j;x<m;x+=i+1) {
                st.insert(str1[x]);
                if(st.size()!=1) return 0;
            }
            for(int x=j;x<n;x+=i+1) {
                st.insert(str2[x]);
                if(st.size()!=1) return 0;
            }
        }
        return 1;
    }

    string gcdOfStrings(string str1, string str2) {
        int i=0;
        int ans=-1;
        string ansS;
        for(int j=i;j<str1.size();j++) {
            if(check(j,str1,str2)) 
                ans=j;
        }
        for(int i=0;i<=ans;i++) ansS+=str1[i];
        return ansS;
    }
};