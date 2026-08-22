class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n, sum = 0, prod = 1;
        while(temp){
            int dig = temp % 10;
            sum += dig;
            prod *= dig;
            temp /= 10;
        }
        return n % (sum + prod) == 0;
    }
};