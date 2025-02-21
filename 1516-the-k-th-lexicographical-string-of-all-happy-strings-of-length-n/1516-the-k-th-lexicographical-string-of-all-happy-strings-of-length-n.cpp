class Solution {
public:
    string getHappyString(int n, int k) {
        int num=3*(int)(pow(2,n-1));
        if(k>num) return "";
        if(n==1) {
            if(k==1) return "a";
            if(k==2) return "b";
            if(k==3) return "c";
        }
        string last=getHappyString(n-1,(k+1)/2);
        if(k%2) {
            if(last[n-2]=='a') 
                return last+'b';
            else
                return last+'a';
        }
        else {
            if(last[n-2]=='c') 
                return last+'b';
            else 
                return last+'c';
        }
        return "";
    }
};