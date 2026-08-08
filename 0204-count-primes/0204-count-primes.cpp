class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> temp(n, true);
        temp[0] = temp[1] = false;
        int count = 0;
        for(int i = 2; i < n; i++){
            if(temp[i]){
                count++;
                if((long long)i * i < n){
                    for(int j = i * i; j < n; j += i)
                        temp[j] = false;
                }
            }
        }
        return count;
    }
};