class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, sum = 0;
        while(n){
            int dig = n % 10;
            n /= 10;
            if(dig == 0) continue;
            x = x * 10 + dig;
        }
        int temp = 0;
        while(x){
            int dig = x % 10;
            temp = temp * 10 + dig;
            sum += dig;
            x /= 10;
        }
        return (long long) temp * sum;
    }
};