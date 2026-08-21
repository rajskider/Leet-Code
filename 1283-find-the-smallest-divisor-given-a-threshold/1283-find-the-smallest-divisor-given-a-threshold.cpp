class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int threshold){
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += (nums[i] + mid - 1)/mid;
            if(count > threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *max_element(nums.begin(), nums.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(mid, nums, threshold)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};