class Solution {
public:
    bool isPossible(int mid, int n, vector<int>& quantities){
        int count = 0;
        for(int i = 0; i < quantities.size(); i++){
            count += (quantities[i] + mid - 1)/mid;
            if(count > n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1;
        int end = *max_element(quantities.begin(), quantities.end());
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(mid, n, quantities)) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};