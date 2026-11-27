class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), size = INT_MAX;
        int i = 0, j = 0;
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            if(sum >= target){
                while(i <= j && sum >= target){
                    size = min(size, j - i + 1);
                    sum -= nums[i++];
                }
            }
            j++;
        }
        return size == INT_MAX ? 0 : size;
    }
};