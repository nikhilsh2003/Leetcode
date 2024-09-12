class Solution {
public:
    int returnNum(char c) {
        return (int)(c-'0');
    }
    string convertToBinary(int check) {
        string result;
        while(check>0) {
            if(check&1) result+='1';
            else result+='0';
            check>>=1;
        }
        reverse(result.begin(),result.end());
        return result;
    }
    string convertDateToBinary(string date) {
        int year=returnNum(date[0])*1000+returnNum(date[1])*100+returnNum(date[2])*10+returnNum(date[3]);
        int month=returnNum(date[5])*10+returnNum(date[6]);
        int day=returnNum(date[8])*10+returnNum(date[9]);
        string ans=convertToBinary(year)+'-'+convertToBinary(month)+'-'+convertToBinary(day);
        return ans;
    }
};