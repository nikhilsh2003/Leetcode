class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1=0,sum2=0;
        for(auto &x:nums) {
            if(x>9) sum2+=x;
            else sum1+=x;
        }
        return sum1!=sum2;
    }
};