class Solution {
public:
    bool isEnglishLetter(char &x) {
        return (x>='A' and x<='Z') or (x>='a' and x<='z');
    } 
    string generateTag(string caption) {
        string ans="#";
        int n=caption.length();
        for(int i=0;i<n;i++) {
            if(!isEnglishLetter(caption[i])) continue;
            char capital=(char)toupper(caption[i]);
            char lower=(char)tolower(caption[i]);
            if(ans.length()==1)  {
                ans+=lower;
            }
            else if(caption[i-1]==' ') {
                ans+=capital;
            }
            else {
                ans+=lower;
            }
            if(ans.length()==100) break;
        }
        return ans;
    }
};