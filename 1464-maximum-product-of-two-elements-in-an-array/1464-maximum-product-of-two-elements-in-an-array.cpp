class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx = INT_MIN, smx = INT_MIN;
        for(int i : nums){
            if(i > mx) {
                smx = mx;
                mx = i;
            }
            else if(i > smx) smx = i;
        }
        return (mx - 1) * (smx - 1);
    }
};