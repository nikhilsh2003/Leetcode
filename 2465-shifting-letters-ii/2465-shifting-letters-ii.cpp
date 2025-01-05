class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();
        vector<int> ct(n,0);
        for(auto &x:shifts) {
            if(x[2]==1) {
                ct[x[0]]++;
                if(x[1]+1<n) 
                    ct[x[1]+1]--;
            }
            else {
                ct[x[0]]--;
                if(x[1]+1<n)
                    ct[x[1]+1]++;
            }
        }
        int currSum=0;
        for(int i=0;i<n;i++) {
            currSum+=ct[i];
            int tmp=currSum%26;
            s[i]='a'+(s[i]+tmp-'a'+26)%26;
        }
        return s;
    }
};