class Solution {
public:
    void generatePalindromes(int i,int n,set<string> &ans,string s,int k) {
        if(i==n) {
            if(stoll(s)%k==0) {
                sort(s.begin(),s.end());
                ans.insert(s);
            }
            return;
        }
        if(i==0) {
            for(char c='1';c<='9';c++) 
                generatePalindromes(i+1,n,ans,s+c,k);
        }
        else {
            if(i>=((n+1)/2)) {
                generatePalindromes(i+1,n,ans,s+s[n-i-1],k);
            }
            else {
                for(char c='0';c<='9';c++) 
                    generatePalindromes(i+1,n,ans,s+c,k);
            }
        }
    }
    long long factorial(int n,vector<long long> &factorialStore) {
        if(factorialStore[n]!=-1) return factorialStore[n];
        else
        return factorialStore[n]=(n==1 || n==0) ? 1: n*1ll * factorial(n - 1,factorialStore);
    }
    long long countGoodIntegers(int n, int k) {
        set<string> uniqueFreq;
        generatePalindromes(0,n,uniqueFreq,"",k);
        vector<long long> factorialStore(n+1,-1);
        long long ans=0;
        for(auto &x:uniqueFreq) {
            vector<int> freq(10,0);
            for(auto &c:x) freq[c-'0']++;
            long long temp1=factorial(n,factorialStore),temp2=0;
            for(int i=0;i<=9;i++) {
                temp1/=factorial(freq[i],factorialStore);
            } 
            if(freq[0]!=0) {
                temp2=factorial(n-1,factorialStore);
                temp2/=factorial(freq[0]-1,factorialStore);
                for(int i=1;i<=9;i++) {
                    temp2/=factorial(freq[i],factorialStore);
                }
            }
            ans+=temp1-temp2;
        }
        return ans;
    }
};