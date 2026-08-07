class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0, i = num.size() - 1;
        while(i >= 0 || carry || k){
            int sum = carry;
            if(i >= 0) sum += num[i--];
            if(k > 0){
                sum += k % 10;
                k /= 10;
            }
            ans.push_back(sum % 10);
            carry = sum / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};