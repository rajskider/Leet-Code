class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int i = 2, temp = 1;
        while(i * i <= num){
            if(num % i == 0) temp += (i + num / i);
            i++; 
        }
        return temp == num;
    }
};