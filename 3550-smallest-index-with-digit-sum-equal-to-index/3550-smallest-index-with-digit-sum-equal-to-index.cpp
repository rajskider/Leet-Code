class Solution {
public:
    bool sumin(int num, int index){
        int sum = 0;
        while(num){
            sum += num % 10;
            if(sum > index) return false;
            num /= 10;
        }
        return sum == index;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(sumin(nums[i], i)) return i;
        }
        return -1;
    }
};