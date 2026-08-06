class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; i <= 100; i++){
            int temp = i, prod = 1;
            while(temp){
                int digit = temp % 10;
                if(digit == 0){
                    prod = 0;
                    break;
                }
                prod *= digit;
                temp /= 10;
            }
            if(prod % t == 0) return i;
        }
        return -1;
    }
};