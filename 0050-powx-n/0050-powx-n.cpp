class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long copy = n;
        copy = abs(copy);
        while(copy){
            if(copy & 1) ans *= x;
            x *= x;
            copy >>= 1;
        }
        return (n < 0) ? 1 / ans : ans;
    }
};