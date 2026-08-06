class Solution {
public:
    int reverse(int x) {
        int temp = 0, mx = INT_MAX / 10, mn = INT_MIN / 10;
        while(x){
            int dig = x % 10;
            if(temp > mx || (temp == mx && dig > 7)) return 0;
            if(temp < mn || (temp == mn && dig < -8)) return 0;
            temp = temp * 10 + dig;
            x /= 10;
        }
        return temp;
    }
};