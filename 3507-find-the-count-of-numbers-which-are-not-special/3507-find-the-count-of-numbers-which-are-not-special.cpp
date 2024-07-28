class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int x=(int)sqrt(r);
        vector<bool> isPrime(x+1,true);
        isPrime[1]=false;
        for(int i=2;i*i<=x;i++) {
            for(int j=i*i;j<=x;j+=i) 
                isPrime[j]=false;
        }
        int ans=0;
        for(int i=2;i<=x;i++) {
            if(isPrime[i] and i*i>=l and i*i<=r) ans++;
        }
        return r-l+1-ans;
    }
};