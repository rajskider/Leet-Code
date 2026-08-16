class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int index = -1, mini = INT_MAX;
        for(int i = 0; i < drones.size(); i++){
            int total = 0;
            for(int j = 0; j < 2; j++)
                total += abs(drones[i][j] - target[j]);
            if(total <= drones[i][2] && total < mini){
                mini = total;
                index = i;
            }
        }
        return index;
    }
};