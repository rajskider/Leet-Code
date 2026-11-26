class Solution {
public:
    bool canAliceWin(int n) {
        bool alice = true;
        int x = 10;
        while(n >= x){
            n -= x;
            x--;
            alice = !alice;
        }
        return !alice;
    }
};