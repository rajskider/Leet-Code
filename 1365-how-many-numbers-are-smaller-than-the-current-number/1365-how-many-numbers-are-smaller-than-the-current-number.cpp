class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        vector<int> temp(mx + 1, 0);
        for(int i = 0; i < nums.size(); i++)
            temp[nums[i]]++;
        int count = 0;
        for(int i = mn; i <= mx; i++) {
            if(temp[i] > 0) {
                int freq = temp[i];
                temp[i] = count;
                count += freq;
            }
        }
        for(int i = 0; i < nums.size(); i++)
            nums[i] = temp[nums[i]];
        return nums;
    }
};