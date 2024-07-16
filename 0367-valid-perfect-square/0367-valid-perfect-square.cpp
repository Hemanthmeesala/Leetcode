class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1,r=num;
        while(l<=r){
            int m = l+(r-l)/2;
            long long val = 1ll*m*1ll*m;
            if(val==num) return true;
            else if(val > num){
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return false;
    }
};