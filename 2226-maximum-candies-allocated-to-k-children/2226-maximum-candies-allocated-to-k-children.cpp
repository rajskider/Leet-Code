class Solution {
public:
    bool isPossible(int mid, vector<int>& candies, long long k){
        long long count = 0;
        for(int i = 0; i < candies.size(); i++){
            count += candies[i]/mid;
            if(count >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1;
        int end = *max_element(candies.begin(), candies.end());
        while(start <= end){
            long long mid = start + (end - start)/2;
            if(isPossible(mid, candies, k)) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
};