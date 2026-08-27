class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        bool nega = (num < 0);
        num = abs(num);
        string ans;
        while(num){
            ans.push_back((num % 7) + '0');
            num /= 7;
        }
        reverse(ans.begin(), ans.end());
        if(nega) ans = "-" + ans;
        return ans;
    }
};