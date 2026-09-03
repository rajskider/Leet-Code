class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int high = 0, alti = 0;
        for(int i = 0; i < gain.size(); i++){
            alti += gain[i];
            high = max(high, alti);
        }
        return high;
    }
};