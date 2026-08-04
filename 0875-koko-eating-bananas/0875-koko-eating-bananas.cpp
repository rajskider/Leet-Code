class Solution {
public:
    bool isPossible(int mid, vector<int>& piles, int h){
        int count = 0;
        for(int i = 0; i < piles.size(); i++){
            count += (piles[i] + mid - 1) / mid;
            if(count > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(mid, piles, h)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};