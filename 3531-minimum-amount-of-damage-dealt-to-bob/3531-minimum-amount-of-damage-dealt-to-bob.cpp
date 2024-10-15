class Solution {
public:
    static bool cmp(pair<int, int> x,pair<int, int> y) {
        double a=x.first/(x.second*1.0),b=y.first/(y.second*1.0);
        return a>b;
    }
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        vector<pair<int, int>> chk;
        int n=damage.size();
        long runSum=0;
        for(int i=0;i<n;i++) {
            int t=(health[i]+power-1)/power;
            runSum+=damage[i]*1ll;
            chk.push_back({damage[i],t});
        }
        sort(chk.begin(),chk.end(),cmp);
        long long ans=0;
        for(int i=0;i<n;i++) {
            ans+=1ll*runSum*chk[i].second;
            runSum-=chk[i].first;
        }
        return ans;
    }
};