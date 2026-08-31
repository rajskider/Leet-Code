class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ac = 0, bc = 0, lc = 0, oc = 0, nc = 0;
        for(char i : text){
            if(i == 'a') ac++;
            else if(i == 'b') bc++;
            else if(i == 'l') lc++;
            else if(i == 'o') oc++;
            else if(i == 'n') nc++;
        }
        return min({ac, bc, lc / 2, oc / 2, nc});
    }
};