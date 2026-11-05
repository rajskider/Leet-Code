class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            if (nums[i] <= 0 || 
                nums[i] > nums.size() ||
                nums[i] == i + 1 ||
                nums[i] == nums[nums[i] - 1])
                i++;
            else
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != j + 1)
                return j + 1;
        }
        return i + 1;
    }
};