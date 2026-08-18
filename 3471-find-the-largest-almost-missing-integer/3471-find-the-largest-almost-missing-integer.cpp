class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i = 0; i <= nums.size() - k; i++){
            set<int> temp;
            for(int j = i; j < k + i; j++) temp.insert(nums[j]);
            for(int a : temp) mp[a]++;
        }
        for(auto it = mp.rbegin(); it != mp.rend(); it++)
            if(it->second == 1) return it->first;
        return -1;
    }
};