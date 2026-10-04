class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> hash(101, 0);
        for (int x : nums) 
            hash[x]++;
        for (int x : nums) {
            if (x % 2 == 0 && hash[x] == 1)
                return x;
        }
        return -1;
    }
};