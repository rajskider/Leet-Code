class Solution {
public:
    bool isPossible(int mid, vector<int>& weights, int days){
        int sum = 0, count = 1;
        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] <= mid) sum += weights[i];
            else{
                count++;
                if(count > days) return false;
                sum = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = 0;
        for(int i = 0; i < weights.size(); i++)
            end += weights[i];
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(mid, weights, days)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};