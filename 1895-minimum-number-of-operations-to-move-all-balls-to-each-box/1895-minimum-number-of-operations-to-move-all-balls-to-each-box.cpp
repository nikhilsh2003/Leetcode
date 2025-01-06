class Solution {
public:
    vector<int> minOperations(string boxes) {
        int len=boxes.size();
        int right=0,ctRight=0;
        for(int i=len-1;i>=0;i--) {
            if(boxes[i]=='1'){   
                right+=i;
                ctRight++;
            }
        }
        vector<int> ans(len,0);
        int left=0,ctLeft=0;
        for(int i=0;i<len;i++) {
            if(boxes[i]=='1') {
                right-=i;
                ctRight--;
            }
            ans[i]=i*ctLeft-left+right-i*ctRight;
            if(boxes[i]=='1') {
                left+=i;
                ctLeft++;
            }
        }
        return ans;
    }
};