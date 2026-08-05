class Solution {
public:
    bool isPossible(int mid, vector<int>& bloomDay, int m, int k){
        int count = 0, bouq = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                count++;
                if(count == k){ 
                    bouq++;
                    count = 0;
                    if(bouq == m) return true;
                }
            }
            else count = 0;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL * m * k > bloomDay.size()) return -1;
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(mid, bloomDay, m, k)) end = mid -  1;
            else start = mid + 1;
        }
        return start;
    }
};