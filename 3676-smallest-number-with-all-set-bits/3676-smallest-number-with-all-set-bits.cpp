class Solution {
public:
    int smallestNumber(int n) {
        int x=1;
        while(true) {
            int num=(1<<x)-1;
            if(num>=n) return num;
            x++;
        }
    }
};