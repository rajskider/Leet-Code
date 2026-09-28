class Solution {
public:
    int maxDepth(string s) {
        int mx = 0, count = 0;
        for(char c : s){
            if(c == '('){
                count++;
                mx = max(count, mx);
            }
            else if(c == ')') count--;
        }
        return mx;
    }
};