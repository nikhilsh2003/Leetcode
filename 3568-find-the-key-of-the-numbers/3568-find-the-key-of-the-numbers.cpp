class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans=0;
        int ct=0;
        while(num1>0 or num2>0 or num3>0) {
            ans+=pow(10,ct++)*min(num1%10,min(num2%10,num3%10));
            num1/=10;
            num2/=10;
            num3/=10;
        }
        return ans;
    }
};