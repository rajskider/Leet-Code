class Solution {
public:
    bool isPossible(int mid, vector<int>& position, int m){
        int lastpos = position[0], count = 1;
        for(int i = 1; i < position.size(); i++){
            if(position[i] - lastpos >= mid) {
                lastpos = position[i];
                count++;
                if(count == m) return true;
            } 
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 1;
        int end = position[position.size() - 1] - position[0];
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(mid, position, m)) start = mid + 1;
            else end = mid - 1;
        }
        return end;
    }
};