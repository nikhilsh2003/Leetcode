class Solution {
public:
    long long maxWeight(vector<int>& pizzas) {
        int n=pizzas.size();
        int days=n/4;
        sort(pizzas.begin(),pizzas.end());
        long long ans=0;
        int right=n-1;
        for(;right>=n-(days+1)/2;right--)
            ans+=(long long)(pizzas[right]);
        cout<<right;
        for(int i=0;i<days/2;i++) {
            right--;
            ans+=(long long)(pizzas[right]);
            right--;
        }
        return ans;
    }
};